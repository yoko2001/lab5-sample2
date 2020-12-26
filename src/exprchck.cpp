#include"exprchck.h"

inline void ARITH_CONVERSION(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    expr->sysType = CommonRealType(ln->sysType, rn->sysType);
    Cast(ln, expr->sysType);
    Cast(rn, expr->sysType);

}
void DoIntegerPromotion(TreeNode* n);

bool tyAdjust(TreeNode* n, int rvalue);
bool tyCheckAssignmentExpression(TreeNode* expr);
bool tyCheckEqualityOP(TreeNode* expr);
bool tyCheckUnaryExpression(TreeNode* expr);
bool tyCheckMultiplicativeOP(TreeNode* expr);
bool tyCheckAddOP(TreeNode* expr);
bool tyCheckSubOP(TreeNode* expr);
bool tyCheckShiftOP(TreeNode* expr);
bool tyCheckRelationalOP(TreeNode* expr);
bool tyCheckBitwiseOP(TreeNode* expr);
bool tyCheckLogicalOP(TreeNode* expr);
bool tyCheckConditionalExpression(TreeNode*expr);
bool tyCheckPrimaryExpression(TreeNode*expr);
bool tyTransformIncrement(TreeNode*expr);
TreeNode* tyCheckPostfixExpression(TreeNode*expr);

static int CanModify(TreeNode* expr);
static TreeNode* ScalePointerOffset(TreeNode* expr, int scale);
/**
 * Check a NODE_EXPR or a NODE_CONST
 */
bool tyCheckExpression(TreeNode* init){
    if(init->nodeType == NODE_DECL_INIT)
    {
        return false;
    }
    else if(init->nodeType == NODE_EXPR)
    {
        switch(init->optype){
            case OP_ASSIGN:
            case OP_AS_ADDEQ:
            case OP_AS_ANDEQ:
            case OP_AS_DIVEQ:
            case OP_AS_MULEQ:
            case OP_AS_OREQ:
            case OP_AS_SFTL_EQ:
            case OP_AS_SFTR_EQ:
            case OP_AS_SUB_EQ:
                return tyCheckAssignmentExpression(init);
                break;
            case OP_EQ:
            case OP_N_EQ:
                return tyCheckEqualityOP(init);
                break;
            case OP_UNA_REF:
            case OP_UNA_DEREF:
            case OP_POSITIVE:
            case OP_MINUS:
            case OP_BIT_NOT:
            case OP_LGC_NOT:
            case OP_PRESELFDEC:
            case OP_PRESELFINC:
                return tyCheckUnaryExpression(init);
                break;
            case OP_MOD:
            case OP_DIV:
            case OP_MUL:
                return tyCheckMultiplicativeOP(init);
                break;
            case OP_ADD:
                return tyCheckAddOP(init);
                break;
            case OP_SUB:
                return tyCheckSubOP(init);
                break;
            case OP_SFT_L:
            case OP_SFT_R:
                return tyCheckShiftOP(init);
                break;
            case OP_POSTSELFDEC:
            case OP_POSTSELFINC:
            case OP_OFFSET_ACCESS:
            case OP_AC_MEMBER:
            case OP_PTAC_MEMBER:
            case OP_FUNC_CALL:
                init = tyCheckPostfixExpression(init);
                return true;
                break;
            case OP_REL_G:
            case OP_REL_GE:
            case OP_REL_L:
            case OP_REL_LE:
                return tyCheckRelationalOP(init);
                break;
            case OP_BIT_AND:
            case OP_BIT_XOR:
            case OP_BIT_OR:
                return tyCheckBitwiseOP(init);
                break;
            case OP_LGC_AND:
            case OP_LGC_OR:
                return tyCheckLogicalOP(init);
                break;
            case OP_CONDITION:
                return tyCheckConditionalExpression(init);
                break;
            default:
                error("tyCheckExpression", init->lineno, "haven't realize exprchck of this kind of operator");
        }   
    }
    else if(tyCheckPrimaryExpression(init))
    {
        return true;
    }
    else 
    {
        error("tyCheckExpression", init->lineno, "unexpected node type");
    }
}

static void create_expr_for_assign(TreeNode* expr, int lineno, OperatorType op,  TreeNode* c1, TreeNode* c2){
    expr = new TreeNode(lineno, NODE_EXPR);
    expr->optype = op;
    expr->addChild(c1);
    expr->addChild(c2);
}
/**
 * ID or Function name or Const
 */
bool tyCheckPrimaryExpression(TreeNode*expr){
    if(expr->nodeType == NODE_CONST){
        if(expr->type == TYPE_INT || expr->type == TYPE_CHAR){
            expr->optype = OP_CONST;
            expr->l_value = 0;
            return true;
        }
        else if(expr->type == TYPE_STRING){
            /**
             * printf("%p\n",&"12345");
             * Because &"12345"	is legal in C, "12345" is different 
             * from int const, such as 123. we can't use &123, but &"123" is legal.
             * another example
             *      char address[4]; strcpy(address, chars2);
             */
            expr->optype = OP_ID;
            expr->l_value = 1;
            return true;
        }
        else{
            error("tyCheckPrimaryExpression", expr->lineno, "this type of primary expression not supported");    
        }
    }
    else if (expr->nodeType == NODE_VAR)
    {
        domain_elem* e;
        e = LookupID(expr->domain, expr->var_name); 
        if (e == NULL){
            error("tyCheckPrimaryExpression", expr->lineno, "undeclared identifier");
            
            //try to assign INT for this element
            e = new domain_elem(expr->var_name, expr->lineno, (_Type)T(INT));
            char name[64];
            strcpy(name, expr->var_name.c_str());
            expr->domain->add_element(name, expr->lineno, T(INT));

            expr->sysType = T(INT);
            expr->l_value = 1;
        }
        else{
            //ID or function designator
            expr->sysType = e->ty;
            expr->l_value = expr->sysType->categ != FUNCTION;
        }
    }
}

bool tyCheckAssignmentExpression(TreeNode* expr){
    _Type ty;
    TreeNode *lnode, *rnode;
    lnode = expr->child;
    rnode = expr->child->sibling;
    /**
     * pre check child,
     * lnode-> rvalue, rnode->rvalue
     */
    tyCheckExpression(lnode);
    tyAdjust(lnode, 1);
    tyCheckExpression(rnode);
    tyAdjust(rnode, 1);

    if(!CanModify(lnode)){
        cout << "The left operand cannot be modified\n";
    }

    TreeNode* lopr;
    switch (expr->optype)
    {
    
    case OP_AS_ADDEQ:
        create_expr_for_assign(lopr, expr->lineno, OP_ADD, lnode, rnode);
        tyCheckAddOP(lopr);
        expr->child->sibling = lopr;
        break;
    default:
        cout << "only has += for now\n";
        break;
    }
    ty = expr->child->sysType;
    if(!CanAssign(expr->child->sibling, ty)){
        cout << "Wrong Assignment\n";
    }
    else{
        Cast(expr->child->sibling, ty); 
    }
    expr->sysType = ty;
    return true;
}

bool tyCheckEqualityOP(TreeNode* expr){
    _Type ty1, ty2;
    TreeNode *lnode, *rnode;
    lnode = expr->child;
    rnode = expr->child->sibling;
    /**
     * pre check child,
     * lnode-> rvalue, rnode->rvalue
     */
    tyCheckExpression(lnode);
    tyAdjust(lnode, 1);
    tyCheckExpression(rnode);
    tyAdjust(rnode, 1);


    expr->sysType = T(INT);
    ty1 = expr->child->sysType;
    ty2 = expr->child->sibling->sysType;


    if(IsArithType(ty1) && IsArithType(ty2)){
        ARITH_CONVERSION(expr);
        expr->sysType = T(INT);
        //FoldConstant(expr);
        return true;
    }
    else{
        cout << "Error or pointer doesn't support in tyCheckEqualityOP\n";
        exit(0);
    }
}

bool tyCheckUnaryExpression(TreeNode* expr){

}
bool tyCheckMultiplicativeOP(TreeNode* expr){
    TreeNode *ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    if(expr->optype != OP_MOD &&IsArithType(ln->sysType) && IsArithType(rn->sysType)){
        goto ok;
    }
    if(expr->optype == OP_MOD &&IsIntType(ln->sysType) && IsIntType(rn->sysType)){
        goto ok;
    }
    cout << "error or inner bug in tyCheckMultiplicativeOP\n";
    exit(1);
ok:
    ARITH_CONVERSION(expr);
    //FoldConstant(expr);
    return true;
}
bool tyCheckAddOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    _Type ty1, ty2;

    if(ln->optype == OP_CONST){
        expr->swapchild();
    }
    //get childs again, because sequence may change
    ln = expr->child;
    rn = ln->sibling;

    ty1 = ln->sysType;
    ty2 = rn->sysType;
    if(IsArithType(ty1) && IsArithType(ty2)){
        ARITH_CONVERSION(expr);
        //FoldConstant(expr);
        return true;
    }
    if(ISObjevtPtr(ty2) && IsIntType(ty1)){
        expr->swapchild();
        ty1 = expr->child->sysType;
        ty2 = expr->child->sibling->sysType;
        goto left_is_ptr;
    }
    if(ISObjevtPtr(ty1) &&  IsIntType(ty2)){
left_is_ptr:
        cout << "not implemented yet Check line 884\n";
        exit(1);
    }

    cout << "inner error in tyCheckAddOP \n";
    exit(1);
}

bool tyCheckSubOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;

    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    _Type ty1, ty2;

    if(ln->optype == OP_CONST){
        expr->swapchild();
    }
    //get childs again, because sequence may change
    ln = expr->child;
    rn = ln->sibling;

    ty1 = ln->sysType;
    ty2 = rn->sysType;
    if(IsArithType(ty1) && IsArithType(ty2)){
        ARITH_CONVERSION(expr);
        //FoldConstant(expr);
        return true;
    }

}

bool tyCheckShiftOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    if(IsIntType(ln->sysType) && IsIntType(rn->sysType)){
        DoIntegerPromotion(ln);
        DoIntegerPromotion(rn);
        expr->sysType = ln->sysType;

        //FoldConstant(expr);
        return true;
    }

    cout << "inner error of tyCheckShiftOP\n";
    exit(1);
}

bool tyCheckRelationalOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    _Type ty1, ty2;
    ty1 = ln->sysType;
    ty2 = rn->sysType;
    //default
    expr->sysType = T(INT);

    if(IsArithType(ty1) && IsArithType(ty2)){
        ARITH_CONVERSION(expr);
        //SET AGAIN BECAUSE ARITH_CONVERSION MAY CHANGE IT
        expr->sysType = T(INT);
        //FoldConstant(expr);
        return true;
    }

    if(ISObjevtPtr(ty1) && ISObjevtPtr(ty2) && 
    IsCompatibleType(UnQualify(ty1->bty), UnQualify(ty2->bty))){
        return true;
    }
    
    cout << "didn't implemented relation op check between ptrs of incomplete type\n";
    cout << "error in tyCheckRelationalOP\n";
}

/**
 * $
 * |
 * ^
 */
bool tyCheckBitwiseOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    if(IsIntType(ln->sysType)&& IsIntType(rn->sysType)){
        ARITH_CONVERSION(expr);
        //FoldConstant(expr);
        return true;
    }
    cout << "inner error in tyCheckBitwiseOP\n";
    exit(1);
}

/**
 * ||
 * &&
 */
bool tyCheckLogicalOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    if(IsScalarType(ln->sysType) && IsScalarType(rn->sysType)){
        expr->sysType = T(INT);
        //FoldConstant(expr);
        return true;
    }
    cout << "inner error in tyCheckLogicalOP\n";
    exit(1);
}

bool tyCheckConditionalExpression(TreeNode*expr){
    cout << "not implemented yet\n";
    exit(1);
}

/**
 * a++ a-- --a ++a 
 * transform a++, ++a to a += 1
 * -- the same, 
 * should be different but 
 */
bool tyTransformIncrement(TreeNode*expr){
    //build a new Const 1
    TreeNode* one = new TreeNode(expr->lineno, NODE_CONST);
    one->int_val = 1;
    one->type = TYPE_INT;
    one->sysType = T(INT);
    tyCheckPrimaryExpression(one);
    
    // Node one is already checked
    expr->addChild(one);

    // check "a"
    if(!tyCheckExpression(expr->child))return false;
    expr->sysType = expr->child->sysType;
    return true;
}



/*******************************************************

	void f(void){
	}
	int main(){
		while(f){	------------>  f is a FUNCTION, not scalar-type, 
				//  we have to adjust f to POINTER(FUNCTION) here
		}
	}
 *******************************************************/

/************************************************************
	Create a AstExpression Node whose op is OP_CAST.
 ************************************************************/
void CastExpression(TreeNode* expr, _Type ty){
    TreeNode* orinode = new TreeNode(0, NODE_EXPR);
    expr->copyto(orinode);
    orinode->father = expr;
    expr->child = orinode;
    expr->nodeType = NODE_EXPR;
    expr->optype = OP_CAST;
    expr->sysType = ty;
}

void Cast(TreeNode* expr, _Type ty){
    int scode = TypeCode(expr->sysType);
	int dcode = TypeCode(ty);

    //void 
    if (dcode == V){
        CastExpression(expr, ty);
        return;
    }
    //same space
    if(scode < F4 && dcode < F4 && scode / 2 ==dcode / 2){
        int scateg = expr->sysType->categ;
        int dcateg = ty->categ;
        if(scateg != dcateg && scateg >= INT && scateg < DOUBLE){
            CastExpression(expr, ty);
        }

        /**
         * etc. CHAR => UNSIGNED CHAR
         */
        expr->sysType = ty;
        return;
    }

    /**
     * 而图 4.2.22 第 11 至 16 行的代码则相对比较微妙,下面,让我们结合一个具体的例子来
        解释这些代码,如图 4.2.23 所示。在 UCC 编译器中,参与算术运算的 char 或 short 都会被
        先提升为 int 类型,再进行算术运算,例如对图 4.2.23 第 8 行的算术右移来说,short 类型的
        操作数 s 会先被转型为 int,如第 19 至 20 行的语法树(cast int s)所示,之后再把 int 型的结点
        按照第 8 行的 C 语句的要求转型为 unsigned int。由于 int 和 unsigned int 同样占 4 个字节,
        如果没有图 4.2.22 第 11 至 16 行的代码,则我们不会调用 CastExpression 函数去构造一个
        OP_CAST 运算的语法树结点,而只是把 s>>1 对应结点的类型设置为 unsigned int,但是图
        4.2.23 第 8 行的(int)转型又会把 s >> 1 对应结点的类型设置为 int。在 UCC 编译器的汇编代
        码生成时,例如 ucl\x86.c 的函数 EmitAssign (IRInst inst)中,我们是根据中间代码 inst 的类
        型来决定选用 sar 还是 shr 指令,而 inst 的类型又来源于语法树结点 s>>1 的类型,我们在讨
        论中间代码生成的函数 TranslateBinaryExpression()时就能看到这一点。这会导致我们错误地
        把 s >>1 结点的类型当作有符号数 int,从而在代码生成时选用算术右移指令 sar,这会产生
        错误的结果。
     */
    if(scode < I4){
        CastExpression(expr, T(INT));
    }
    if(!scode == dcode){
        if(dcode < I4){
            CastExpression(expr, T(INT));
        }
        CastExpression(expr, ty);
    }
    return;
}

TreeNode* tyCheckPostfixExpression(TreeNode*expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    
    switch (expr->optype)
    {
    case OP_OFFSET_ACCESS:

        tyCheckExpression(ln);
        tyAdjust(ln, 1);
        tyCheckExpression(rn);
        tyAdjust(rn, 1);

        if (ISObjevtPtr(ln->sysType) && IsIntType(rn->sysType)){
            expr->sysType = ln->sysType->bty;
            expr->l_value = 1;
            DoIntegerPromotion(rn);
            ln->sibling = rn = ScalePointerOffset(rn, expr->sysType->size);
            if(!sysTyIsArr(ln->typeMark) && ln->sysType->categ != ARRAY){
                TreeNode *deref, *addexpr;
                deref = new TreeNode(ln->lineno, NODE_EXPR);
                addexpr = new TreeNode(ln->lineno, NODE_EXPR);
                deref->optype = OP_UNA_DEREF;
                deref->sysType = ln->sysType->bty;
                deref->addChild(addexpr);

                addexpr->optype = OP_ADD;
                addexpr->sysType = ln->sysType;
                addexpr->addChild(ln);
                addexpr->addChild(rn);
                expr->child = 0;
                return deref;
            }
        }
        return expr;

    case OP_POSTSELFDEC:
    case OP_POSTSELFINC:
        tyTransformIncrement(expr);
        return expr;
    default:
        cout << "haven't made record member operators\n";
        break;
    }
}


bool tyAdjust(TreeNode* n, int rvalue){
    int qual = 0;
    //if this node is treated as rvalue
    if(rvalue){
        qual = n->sysType->qual;
        n->sysType = UnQualify(n->sysType);
        n->l_value = 0;
    }

    if(n->sysType->categ == FUNCTION){
        n->sysType = PointerTo(n->sysType);

        n->typeMark = sysTyClear(n->typeMark);
        n->typeMark = sysTyIsFunc(n->typeMark);
    }
    else if(n->sysType->categ == ARRAY){
        n->sysType = PointerTo(Qualify(qual, n->sysType));
        n->l_value = 0;
        /*************************************
			"abc" = "123";		// illegal
			(1)
			OP_STR	---->  OP_ID,	lvalue is 1
			here, we have to set lvalue to 0 explicitely
			(2)	for an id of array type, its lvalue is first set to 
				1 in CheckPrimaryExpression(AstExpression expr).				
		 *************************************/
        n->typeMark = sysTyClear(n->typeMark);
        n->typeMark = sysTyIsArr(n->typeMark);
    }
    return n;
}

void DoIntegerPromotion(TreeNode* n){
    if (n->sysType->categ < INT){
        Cast(n, T(INT));
    }
    return;
}

inline void TreeNode::swapchild(){
    TreeNode* t = child;
    child = child->sibling;
    child->sibling = t;
    t->sibling = 0;
}

static TreeNode* ScalePointerOffset(TreeNode* offset, int scale){
    TreeNode* expr = new TreeNode(offset->lineno, NODE_EXPR);
    expr->sysType = offset->sysType;
    expr->optype = OP_MUL;
    expr->addChild(offset);
    TreeNode* sn = new TreeNode(offset->lineno, NODE_CONST);
    sn->sysType = offset->sysType;
    sn->optype = OP_CONST;
    sn->int_val = scale;

    expr->addChild(sn);

    return expr;
}

static int CanModify(TreeNode* expr){
    return (expr->l_value && !(expr->sysType->qual & SHIFT_CONST));
}