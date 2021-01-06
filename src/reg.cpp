#include"reg.h"
#include<assert.h>
static int FindEmptyReg(int endreg){
    for(int i = EAX; i <= endreg; i++){
        if(X86Regs[i] != NULL && X86Regs[i]->p_val == NULL && !UsedRegs[i]){
            return i;
        }
    }
    return -1;
}

static int SelectSwapReg(int endreg){
    domain_elem* p;
    int reg = -1;
    int ref, refm = INT32_MAX;
    for(int i = EAX; i <= endreg; i++){
        //used by current inst, continue
        if(X86Regs[i] == NULL || UsedRegs[i]) continue;

        p = (domain_elem*) X86Regs[i]->p_val;
        if(p != NULL){
            ref = p->ref;
        }
        if (ref < refm){
            refm = ref;
            reg = i;
        }
    }

    assert(reg != -1);
    return reg;
}

void SwapReg(domain_elem* reg){
    domain_elem* p;
    p = (domain_elem*) reg->p_val;

    if(p != NULL){
        p->reg = NULL;
        if(p->need_wb && p->ref > 0){
            p->need_wb = 0;
            StoreVar(reg, p);
        }
    }
    reg->p_val = NULL;
}

domain_elem* GetReg(){
    int endreg = EDI;
    domain_elem** Regs = X86Regs;
    // try to find an unused register, that is , empty
    int i = FindEmptyReg(endreg);

    //can't get
    if (i == -1){
        i = SelectSwapReg(endreg);
        SwapReg(X86Regs[i]);
    }

    UsedRegs[i] = true;
    return Regs[i];
}

/**
 * X86Regs[EBX] = CreateReg("%ebx", "(%ebx)", EBX);
 */
domain_elem* CreateReg(std::string* name, std::string* iname, int no){
    domain_elem* reg = new domain_elem();
    reg->kind = DEK_Register;
    reg->s = new std::string(*name);
    reg->intval = no;
    if(iname != NULL){
        reg->next = new domain_elem();
        reg->next->kind = DEK_Register;
        reg->next->s = new std::string(*iname);
    }

    return reg;
}