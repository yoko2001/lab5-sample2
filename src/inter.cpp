#include"inter.h"
#include"tree.h"
#include<sstream>
std::stringstream ss;
int TempNum;
int LabelNum;
extern _domain* FSYM;

extern ofstream iro;
domain_elem* TranslateExpression(TreeNode* expr);

int OP2IROP(int opcode){
    switch(opcode){
    case OP_EQ:
        return JE;
    case OP_N_EQ:
        return JNE;
    case OP_REL_G:
        return JG;
    case OP_REL_L:
        return JL;
    case OP_REL_GE:
        return JGE;
    case OP_REL_LE:
        return JLE; 
    case OP_ADD:
        return ADD;
    case OP_SUB:
        return SUB;
    case OP_MUL:
        return MUL;
    case OP_DIV:
        return DIV;
    case OP_MOD:
        return MOD;
    case OP_SFT_L:
        return LSH;
    case OP_SFT_R:
        return RSH;
    case OP_BIT_XOR:
        return BXOR;
    case OP_BIT_OR:
        return BOR;
    case OP_BIT_AND:
        return BAND;
    case OP_BIT_NOT:
        return BCOM;
    case OP_FUNC_CALL:
        return CALL;
    case OP_UNA_DEREF:
        return DEREF;
    case OP_UNA_REF:
        return ADDR;
    case OP_MINUS:
        return NEG;
    case OP_POSITIVE:
        return NOP;
    case OP_OFFSET_ACCESS:
        return NOP;
    }
}

//BBLock
BBlock CreateBBlock(){
    BBlock bb;
    bb = (BBlock)malloc(sizeof(struct bblock));
    bb->instlist.opcode = NOP;
    //initial dual-linklist
    bb->instlist.prev = bb->instlist.next = &bb->instlist;
    return bb;
}

void StartBBlock(BBlock bb){
    currentBB->next = bb;
    bb->prev = bb;
    IRInst lastinst;
    lastinst = currentBB->instlist.prev;

    if(lastinst->opcode != JMP && lastinst->opcode != IJMP){
        DrawCFGEdge(currentBB, bb);
    }
    currentBB = bb;
}

static void AddSuccessor(BBlock from, BBlock to);
static void AddPredecessor(BBlock to, BBlock from);
void DrawCFGEdge(BBlock from, BBlock to){
    AddSuccessor(from, to);
	AddPredecessor(to, from);
}

static void AddSuccessor(BBlock from, BBlock to){
    CFGEdge e;
    e = (CFGEdge) malloc(sizeof(struct cfgedge));
    e->bb = to;
    //add edge an edge to "to" to succs list of "from"
    e->next = from->succs;
    from->succs = e;
    from->nsucc++;
}

void AppendInst(IRInst inst, BBlock bb){
    assert(bb != NULL);
    bb->instlist.prev->next = inst;
    inst->prev = bb->instlist.prev;
    inst->next = &bb->instlist;
    bb->instlist.prev = inst;
    bb->ninst++;
}

static void AddPredecessor(BBlock to, BBlock from){
    CFGEdge e;
    e = (CFGEdge) malloc(sizeof(struct cfgedge));
    e->bb = from;
    
    //add edge an edge from "from" to pred list of "to"
    e->next = to->preds;
    to->preds = e;
    to->npred++;
}

//gen INST
void genMov(_Type ty, domain_elem* dst, domain_elem* src){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    //add ref
    dst->ref++; src->ref++;
    inst->ty = ty;
    inst->opcode = MOV;
    inst->opds[0] = dst;
    inst->opds[1] = src;
    inst->opds[2] = NULL;

    AppendInst(inst, currentBB);
    // /*************************************************
	// 	If a named variable is the destination of MOV,
	// 	all the calculated subexpression using this variable is invalid.
	//  ************************************************/
//这部分用来做子表达式以及冗余变量删除，由于时间太他妈不够了，所以就不写了
    // if (dst->kind == SK_Variable)
	// {
	// 	TrackValueChange(dst);
	// }
	// else if (dst->kind == SK_Temp)
	// {
	// 	DefineTemp(dst, MOV, (Symbol)inst, NULL);
	// }
}

void genAssign(_Type ty, domain_elem* dst, int opcode, domain_elem* src1, domain_elem* src2){
    assert(dst->kind == DEK_Temp);
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    dst->ref++;
    src1->ref++;
    if (src2) src2->ref++;

    inst->ty = ty;
    inst->opcode = opcode;
    inst->opds[0] = dst;
    inst->opds[1] = src1;
    inst->opds[2] = src2;
    AppendInst(inst, currentBB);
}

/********************************************************
	[addr] = 30;	---------> because temporary has no address,
		so [addr] = 30  isn't the definition of a temporary.
		That is , no need to call DefineTemp(...) here.
 ********************************************************/
void genIMOV(_Type ty, domain_elem* dst, domain_elem* src){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    //add ref
    dst->ref++; src->ref++;
    inst->ty = ty;
    inst->opcode = IMOV;
    inst->opds[0] = dst;
    inst->opds[1] = src;
    inst->opds[2] = NULL;
    AppendInst(inst, currentBB);
}

//void genAssign 这个在这里省略了，我用不到，我太菜了



/*************************************************************************
	GenerateBranch(choice->ty, lhalfBB, JL, choice, IntConstant(bucketArray[mid]->minVal));
	output:
		if (a < 1) goto BB5;
	@ty			the type of 'a'
	@dstBB		BB5
	@opcode		JL
	@src1		'a'
	@src2		1
 *************************************************************************/
void genBranch(_Type ty, BBlock dstBB, int opcode, domain_elem* src1, domain_elem* src2){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    dstBB->ref++;
    src1->ref++;
    if(src2) src2->ref++;
    DrawCFGEdge(currentBB, dstBB);

    inst->ty = ty;
    inst->opcode = opcode;
    inst->opds[0] = &dstBB->label;
    inst->opds[1] = src1;
    inst->opds[2] = src2;
    AppendInst(inst, currentBB);
}

void genJump(BBlock dstBB){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    dstBB->ref++;
    inst->ty = T(VOID);
    inst->opcode = JMP;
    inst->opds[0] = &dstBB->label;
    inst->opds[1] = inst->opds[2] = NULL;
    AppendInst(inst, currentBB);
}

void genRet(_Type ty, domain_elem* src){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    inst->ty = ty;
    inst->opcode = RET;
    src->ref++;
    inst->opds[0] = src;
    inst->opds[1] = inst->opds[2] = NULL;

    AppendInst(inst, currentBB);
}

/**
 * faddr: the element of the function
 * recv: a = f(a, b); -> a
 */
void genFuncCall(_Type ty, domain_elem* recv, domain_elem* faddr, TreeNode* args){
    IRInst inst;
    inst = (IRInst)malloc(sizeof(irinst));

    if(recv) recv->ref++;
    faddr->ref++;
    TreeNode* arg = args->child;
    //mark ref
    while(arg){
        assert(arg->p_val!= NULL);
        ((domain_elem*)(arg->p_val))->ref++;
        arg = arg->sibling;
    }
    inst->ty = ty;
    inst->opds[0] = recv;
    inst->opds[1] = faddr;
    //just save it here in this way, have to
    //transform to treenode brfore deref
    inst->opds[2] = (domain_elem*) args;

    inst->opcode = CALL;
    AppendInst(inst, currentBB);
}

//TO DO
//this function is for clear unfull space of initilization
//void genCLR(domain_elem* dst, int size);

//const & temp element create
domain_elem* IntConst(int i){
    domain_elem* e;
    e = new domain_elem();
    e->ty = T(INT);

    //set name
    ss.clear();
    ss<<i;
    ss >> (e->s);

    //set value
    e->intval = i;
    e->dm = FSYM;
    e->pos = FSYM->startline;

    e->defined = false;
    e->kind = DEK_Constant;

    return e;
}

domain_elem* PointerConst(int addr){
    domain_elem* e;
    e = new domain_elem();
    e->ty = T(POINTER);
    e->intval = addr;
    //set name
    ss.clear();
    ss << "0x"; ss << addr;
    ss >> (e->s);

    e->dm = FSYM;
    e->pos = FSYM->startline;

    e->defined = false;
    e->kind = DEK_Constant;

    return e;
}

domain_elem* AddTemp(_Type ty){
    domain_elem* e;
    e = new domain_elem();
    e->ty = ty;
    e->kind = DEK_Temp;

    ss.clear();
    ss << "t"; ss << TempNum++;
    ss >> (e->s);

    e->dm = FSYM;
    e->pos = FSYM->startline;
    FSYM->add_element(e);
}

domain_elem* AddLabel(){
    domain_elem* e;
    e = new domain_elem();
    e->kind = DEK_label;

    ss.clear();
    ss << "BB"; ss << LabelNum++;
    ss >> (e->s);

    e->pos = FSYM->startline;
    return e;
}




//translations
//part0 translate util
TreeNode* NOT(TreeNode* expr){
    TreeNode *c1, *c2;
    switch(expr->optype)
    {
    case OP_LGC_OR:
        expr->optype = OP_LGC_AND;
        c1 = expr->child;
        c2 = c1->sibling;
        c1 = NOT(c1);
        c2 = NOT(c2);
        return expr;   
    case OP_LGC_AND:
        expr->optype = OP_LGC_OR;
        c1 = expr->child;
        c2 = c1->sibling;
        c1 = NOT(c1);
        c2 = NOT(c2);
        return expr;
    case OP_EQ:
        expr->optype = OP_N_EQ;
        return expr;
    case OP_N_EQ:
        expr->optype = OP_EQ;
        return expr;
    case OP_REL_G:
        expr->optype = OP_REL_LE;
        return expr;
    case OP_REL_GE:
        expr->optype = OP_REL_L;
        return expr;
    case OP_REL_L:
        expr->optype = OP_REL_GE;
        return expr;
    case OP_REL_LE:
        expr->optype = OP_REL_G;
        return expr;

    case OP_LGC_NOT:
        iro << "doesn't support use LOGIC NOT in logic expression" << endl;
        exit(0); 
    default:
        iro << "doesn't support use this op in logic expression: op" << expr->optype << " node:"<<expr->nodeID<<endl;
    }
}


domain_elem* Simplyfy(_Type ty, int opcode, domain_elem* src1, domain_elem* src2){
    domain_elem*t;
    
    if(src2 == NULL || (src2->kind != DEK_Constant && opcode != SUB)){
        goto ret;
    }
    //src2 is constant for sure
    switch (opcode)
    {
    case ADD:
        if (src2->intval == 0){
            return src1;
        }
        goto ret;
    case SUB:
        if(src2->kind == DEK_Constant && src2->intval == 0){
            return src1;
        }
        goto ret;
    case MUL:
    case DIV:
        if(src2->intval == 1){
            return src1;
        }
        break;
    case MOD:
        if(src2->intval == 1){
            return IntConst(0);
        }
        break;
    default:
        break;
    }
ret:
    t = AddTemp(ty);
    genAssign(ty, t, opcode, src1, src2);
    return t;
}

domain_elem* TranslateCast(_Type ty, _Type sty, domain_elem* src){\
    domain_elem* e;
    int scode, dcode, opcode;

    dcode = TypeCode(ty);
    scode = TypeCode(sty);

    if (scode == dcode){
        return src;
    }

    if(dcode == V){
        return NULL;
    }

    switch (scode)
    {
    case I1:
        opcode = EXTI1;
        break;
    case I2:
        opcode = EXTI2;
        break;
    case U1:
        opcode = EXTU1;
        break;
    case U2:
        opcode = EXTU2;
        break;
    case I4:
        if(dcode <= U1){
            opcode = TRUI1;
        }else if(dcode <= U2){
            opcode = TRUI2;
        }else if (dcode == F8){
            opcode = CVTI4F8;
        }else{
            /*************************************************
			short a = -1;
			int main(int argc,char * argv[]){
				printf("%x \n",((unsigned int)a) >> 1);
				return 0;
			}
			//	short	-->		int	-->		unsigned int
			 **************************************************/	
            domain_elem* temp = AddTemp(ty);
            genMov(ty, temp, src);
            return temp;
        }
        break;
    case U4:
        if(dcode == F8){
            opcode = CVTU4F8;
        }else{
            domain_elem* temp = AddTemp(ty);
            genMov(ty, temp, src);
            return temp;
        }
        break;
    case F8:
        if(dcode == I4){
            opcode = CVTF8I4;
        }else if (dcode == U4){
            opcode  = CVTF8U4;
        }
        else{
            opcode = -1;
        }
        break;
    default:
        assert(0);
        return NULL;
    }

    e = AddTemp(ty);
    genAssign(ty, e, opcode, src, NULL);
    
    return e;
}

//part1 translate expressions
static domain_elem* TranslatePrimaryExpression(TreeNode* expr){
    if(expr->optype == OP_CONST){
        if(IsIntType(expr->sysType)){
            iro << "add int const of ival: " << expr->int_val << endl;
            return IntConst(expr->int_val);
        }else{
            iro << "TranslatePrimaryExpression only work with int, nodeid:" << expr->nodeID << endl;
        }
    }
    else if(expr->nodeType == NODE_VAR){
        return (domain_elem*)(expr->p_val);
    }
    if (expr->p_val != NULL){
        return (domain_elem*)expr->p_val;
    }else{
        iro << "TranslatePrimaryExpression inner error , NODEID:" << expr->nodeID << endl;
    }
}
/*******************************************************************
	if(expr)	goto trueBB.
	@expr	the expression for test
	@trueBB
	@falseBB	
			We need falseBB only when we are translating short-cut	&&  ||
			the @expr needs to jump to falseBB.
 *******************************************************************/
void TranslateBranch(TreeNode* expr, BBlock trueBB, BBlock falseBB){
    BBlock restBB;
    domain_elem* src1, *src2;
    _Type ty;
    int opcode;

    TreeNode* c1, *c2;

    int opc;
    switch(expr->optype)
    {    
    case OP_LGC_AND:
        c1 = expr->child;
        c2 = c1->sibling;
        restBB = CreateBBlock();
        TranslateBranch(NOT(c1), falseBB, restBB);
        StartBBlock(restBB);
        TranslateBranch(c2, trueBB, falseBB);
        break;

    case OP_LGC_OR:
        c1 = expr->child;
        c2 = c1->sibling;
        restBB = CreateBBlock();
        TranslateBranch(c1, trueBB, restBB);
        StartBBlock(restBB);
        TranslateBranch(c2, trueBB, falseBB);
        break;

    case OP_LGC_NOT:
        iro << "doesn't support ! in logic expression" << endl;
        break;
    case OP_EQ:
    case OP_N_EQ:
    case OP_REL_G:
    case OP_REL_L:
    case OP_REL_GE:
    case OP_REL_LE:
        opc = OP2IROP(expr->optype);
        c1 = expr->child;
        c2 = c1->sibling;
        src1 = TranslateExpression(c1);
        src2 = TranslateExpression(c2);
        
        genBranch(c1->sysType, trueBB, opc, src1, src2);
        break;
    case OP_CONST:
        if(!(expr->int_val == 0)){
            genJump(trueBB);
        }    
        break;
    default:
        src1 = TranslateExpression(expr);
        if(src1->kind == DEK_Constant){
            if(!(src1->intval == 0)){
                genJump(trueBB);
            }
        }
        else{
            ty = expr->sysType;
            if(ty->categ < INT){
                src1 = TranslateCast(T(INT), ty, src1);
                ty = T(INT);
            }
            genBranch(ty, trueBB, JNZ, src1, NULL);
        }
    }


}
/**
 * Generate intermedicate code to calculate a branch expression's value.
 * e.g. int a, b; a = a > b;
 * Introduces a new temporary t to holds the value of a > b.
 *     if a > b goto trueBB
 * falseBB:
 *     t = 0;
 *     goto nextBB;
 * trueBB:
 *     t = 1;
 * nextBB:
 *     ...
 */
 /***********************************************************
		int main(){
			int a = 3, b = 3;
			a = a > b;	----------  (a > b) is a branch expression
									convert logic value to arithmetic value (0/1)
			return 0;
		}

		function main
			a = 3;
			b = 3;
			if (a > b) goto BB0;
			a = 0;		-----------	falseBB
			goto BB1;
		BB0:				-----------	trueBB
			a = 1;
		BB1:				-----------  nextBB
			return 0;	
  ***********************************************************/
static domain_elem* TranslateBranchExpression(TreeNode* expr){
    BBlock nextbb, truebb, falsebb;
    domain_elem* t;
    t = AddTemp(expr->sysType);
    nextbb = CreateBBlock();
    truebb = CreateBBlock();
    falsebb = CreateBBlock();

    TranslateBranch(expr, truebb, falsebb);
    StartBBlock(falsebb);
    genMov(expr->sysType, t, IntConst(0));
    StartBBlock(truebb);
    genMov(expr->sysType, t, IntConst(1));
    StartBBlock(nextbb);

    return t;
}

static domain_elem* TranslateNormalBinaryExpression(TreeNode* expr){
    domain_elem* src1, * src2;
    TreeNode* c1, *c2;
    c1 = expr->child;
    c2 = c1->sibling;
    src1 = TranslateExpression(c1);
    src2 = TranslateExpression(c2);
    return Simplyfy(expr->sysType, OP2IROP(expr->optype), src1, src2);
}

static domain_elem* TranslateArrayIndex(TreeNode* expr){
    domain_elem *addr, *dst, *voff = NULL;
    int coff = 0;

    TreeNode* n = expr;
    do{
        TreeNode* lch = n->child;
        TreeNode* rch = lch->sibling;
        if (rch->optype == 0) rch = rch->child;
        if(rch->nodeType == NODE_CONST || rch->optype == OP_CONST){
            coff += rch->int_val;
        }
        else if(voff == NULL){
            voff = TranslateExpression(rch);
        }
        else{
            voff = Simplyfy(voff->ty, ADD, voff, TranslateExpression(voff));
        }
        n = lch;
    }while(n->optype == OP_OFFSET_ACCESS);

    addr = TranslateExpression(n);

}

static domain_elem* TranslateFunctionCall(TreeNode* expr){}

static domain_elem* TranslatePostfixExpression(TreeNode* expr){
    switch (expr->optype)
    {
    case OP_OFFSET_ACCESS:
        return TranslateArrayIndex(expr);
    case OP_FUNC_CALL:
        return TranslateFunctionCall(expr);
    case OP_POSTSELFDEC:
    case OP_POSTSELFINC:
        iro << "TranslatePostfixExpression doesn't support ++ --" << endl;
        assert(0);
        return NULL;
        //return TranslateIncrement(expr);
    default:
        assert(0);
        return NULL;
    }
}

domain_elem* TranslateExpression(TreeNode* expr){
    assert(expr->nodeType == NODE_EXPR);
    switch (expr->optype)
    {
    case OP_ADD:
    case OP_SUB:
    case OP_BIT_AND:
    case OP_BIT_NOT:
    case OP_BIT_OR:
    case OP_BIT_XOR:
    case OP_MOD:
    case OP_DIV:
    case OP_MUL:
    case OP_SFT_L:
    case OP_SFT_R:
        return TranslateNormalBinaryExpression(expr);
    case OP_LGC_AND:
    case OP_LGC_NOT:
    case OP_LGC_OR:
    case OP_EQ:
    case OP_N_EQ:
    case OP_REL_G:
    case OP_REL_L:
    case OP_REL_GE:
    case OP_REL_LE:
        return TranslateBranchExpression(expr);
    case OP_ID:
    case OP_CONST:
        return TranslatePrimaryExpression(expr);
        break;
    case 0:
        return TranslateExpression(expr->child);
        break;
    default:
        break;
    }
}


//part2 translate statements
/**
 * continue is translate into:
 *    goto loop's contBB
 * nextBB:
 *    ...
 */
static void TranslateContinueStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) 
    && (stmt->stype == STMT_CONTINUE)
    && (stmt->p_val != NULL));

    //the treenode we are returning to is in stmt->p_val;
    genJump(((TreeNode*)stmt->p_val)->contBB);
    StartBBlock(CreateBBlock());
}