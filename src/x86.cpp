#include"reg.h"
#include"tree.h"
#include"x86code.h"
#include"output.h"
#include<sstream>
static std::stringstream ss;
extern domain* d_root;
extern ofstream asmo;
static int Renamer = 0;


static std::string* putAccessName(domain_elem* opd){
    if (opd->access_name != NULL){
        asmo << *opd->access_name;
        return opd->access_name;
    }

    switch (opd->kind)
    {
    case DEK_Constant:
        if(opd->s != NULL){
            opd->access_name = new std::string(*opd->s);
            asmo << *opd->access_name;
        }
        return opd->access_name;
    case DEK_String:
    case DEK_label:
    case DEK_Register+1:
        if(opd->s != NULL){
            opd->access_name = new std::string(*opd->s);
            asmo << *opd->access_name;
        }
        return opd->access_name;

    case DEK_variable:
	case DEK_Temp:
        //全局的
        if(opd->dm == d_root){
            opd->access_name = new std::string("_");
            *opd->access_name += *opd->s;
            asmo << *opd->access_name;
        }
        else{
            ss.clear();
            ss << *opd->s;
            opd->access_name = new std::string();
            ss << Renamer++;
            ss >> *opd->access_name;
            asmo << *opd->access_name;
        }
        return opd->access_name;

    case DEK_function:
        opd->access_name = new std::string("_");
        *opd->access_name += *opd->s;
        asmo << *opd->access_name;
        return opd->access_name;
    default:
        break;
    }
    return opd->access_name;
}
static void PutASMCode(int code, domain_elem** opds){
    char* format = x86code[code];
    char* prefix;
    int i;
    
    asmo << '\t';
    while(*format){
        switch (*format)
        {
        case ';':
            asmo << "\n\t";
            break;
        case '%':
            format++;
            if(*format == 'b'){
                prefix = "BYTE PTR ";
                format++;
            } 
            else if (*format == 'w'){
                prefix = "WORD PTR ";
                format++;
            }       
            else{
                prefix = NULL;
            }

            i = *format - '0';
            if(opds[i]->reg != NULL){
                asmo << opds[i]->reg->s;
            }
            else{
                if (prefix != NULL && opds[i]->kind != DEK_Constant && opds[i]->kind != DEK_function){
                    asmo << prefix;
                }
                putAccessName(opds[i]);
            }
            break;
        default:
            asmo << (*format);
            break;
        }
        format++;
    }
    asmo << '\n';
}

static void AddVarToReg(domain_elem* reg, domain_elem*v){
    assert(v->kind == DEK_Temp);
    assert(reg->p_val == NULL);

    v->reg = reg;
    reg->p_val = v;
}

/**
 * When a variable is modified, if it is not in a register, do nothing;
 * otherwise, spill othere variables in this register, set the variable's
 * needWB flag.(need write back to memory)
 */
static void ModifyVar(domain_elem* e){
    domain_elem*reg;
    if(e->reg == NULL) return;
    e->need_wb = 0;
    reg = e->reg;

    assert(reg->p_val != NULL);
    //SwapReg(reg);
    //AddVarToReg(reg, e);
    e->need_wb = 1;
}

static void X86Move(int code, domain_elem* dst, domain_elem* src){
    domain_elem* opds[2];
    opds[0] = dst;
    opds[1] = src;
    PutASMCode(code, opds);
}

static void AllocateReg(IRInst inst, int index){
    domain_elem* reg, *e;
    e = inst->opds[index];

    if(e->kind != DEK_Temp) return;

    if(e->reg != NULL){
        UsedRegs[e->reg->intval] = true;
        return;
    }

    reg = GetReg();
    if(index != 0){
        X86Move(X86_MOVI4, reg, e);
    }
    AddVarToReg(reg, e);
}

static void emitMove(IRInst inst){
    int tcode = TypeCode(inst->ty);
    domain_elem* op0 = inst->opds[0];
    domain_elem* op1 = inst->opds[1];
    domain_elem* reg;
    if(tcode == F4 || tcode == F8){
        assert(0);
        return;
    }
    if(tcode == B){
        assert(0);
        return;
    }

    switch (tcode)
    {
    case I1:
    case U1:
        if(op1->kind == DEK_Constant){
            X86Move(X86_MOVI1, op0, op1);
        }
        else{
            reg = GetReg();
            X86Move(X86_MOVI1, reg, op1);
            X86Move(X86_MOVI1, op0, reg);
        }
        break;
    case I2:
    case U2:
        assert(0);
        break;
    case I4:
    case U4:
        if(op1->kind == DEK_Constant){
            X86Move(X86_MOVI4, op0, op1);
        }
        else{
            AllocateReg(inst, 0);
            AllocateReg(inst, 1);
            if(op0->reg == NULL && op1->reg == NULL){
                reg = GetReg();
                X86Move(X86_MOVI4, reg, op1);
                X86Move(X86_MOVI4, op0, reg);
            }
            else{
                X86Move(X86_MOVI4, op0, op1);
            }
        }
        ModifyVar(op0);
    default:
        break;
    }
}

static void emitInst(IRInst inst){
    struct irinst _inst = *inst;

    switch(_inst.opcode){
    case MOV:
        emitMove(&_inst);
    }
}




void StoreVar(domain_elem* reg, domain_elem* v){
    X86Move(X86_MOVI4, v, reg);
}