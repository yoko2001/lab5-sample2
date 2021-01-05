#include"exprchck.h"

inline void ARITH_CONVERSION(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;
    assert(ln->sysType!=NULL);
    assert(rn->sysType != NULL);
    //cout << expr->nodeID<<endl;
    expr->sysType = CommonRealType(ln->sysType, rn->sysType);
    //cout << "CommonRealType return\n";
    Cast(ln, expr->sysType);
    Cast(rn, expr->sysType);

}
void DoIntegerPromotion(TreeNode* n);
_Type Promote(_Type ty);
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
bool tyCheckFunctionCall(TreeNode*expr);
bool tyCheckArgument(TreeNode* expr, _FunctionType ty, int argNo, bool* argFull);
static int CanModify(TreeNode* expr);
static TreeNode* ScalePointerOffset(TreeNode* expr, int scale);
/**
 * Check a NODE_EXPR or a NODE_CONST
 */
bool tyCheckExpression(TreeNode* init){
  //  assert(init->nodeID != 144 && init->nodeID != 148 && init->nodeID != 149 && init->nodeID != 150);
    if(init->nodeType == NODE_DECL_INIT)
    {
        return false;
    }
    else if(init->nodeType == NODE_EXPR)
    {
        //cout << "tyCheckExpression : " << init->nodeID <<" " << init->optype << endl;
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
                cout << "tyCheckUnaryExpression " << init->nodeID << endl;
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
                //cout << "check realtion expression" << endl;
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
            case 0:
                tyCheckExpression(init->child);
                init->sysType = init->child->sysType;
                break;
            default:
                cout << "problem nodeid: " << init->nodeID<< endl;
                error("tyCheckExpression", init->lineno, "haven't realize exprchck of this kind of operator");
        }   
    }
    else if(tyCheckPrimaryExpression(init))
    {
        return true;
    }
    else 
    {
        cout << "problem nodeid: " << init->nodeID<< endl;
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
    //cout << "enter tyCheckPrimaryExpression " << expr->nodeID << endl;
    
    if(expr->nodeType == NODE_CONST){
        //assert(expr->nodeID != 123);
        //cout << expr->nodeType << " " << expr->type->type << endl;   
        if((expr->sysType == T(INT)) || (expr->sysType == T(CCHAR))){
            expr->optype = OP_CONST;
            expr->l_value = 0;
            //assert((expr->sysType == T(INT)) || (expr->sysType == T(CCHAR)));
            //cout << "checked const int or const char\n";
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
            expr->p_val = (void*)&expr->domain->elements.back();
            expr->l_value = 1;
        }
        else{
            //ID or function designator
            expr->sysType = e->ty;
            expr->p_val = e;
            expr->l_value = expr->sysType->categ != FUNCTION;
        }
        return true;
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
    tyAdjust(lnode, 0);
    cout << "ass l "<< expr->child->nodeID <<lnode->nodeID << endl;
    tyCheckExpression(rnode) ;
    tyAdjust(rnode, 1);
    cout << "assign from: " << rnode->nodeID << " to " << lnode->nodeID << endl; 

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
    case OP_ASSIGN:
        break;
    default:
        cout << "only has += for now\n";
        break;
    }
    cout << "assigning" << expr->nodeID << endl;
    ty = expr->child->sysType;
    if(!CanAssign(expr->child->sibling, ty)){
        cout << "Wrong Assignment\n";
    }
    else{
        Cast(expr->child->sibling, ty); 
    }
    expr->sysType = ty;
    cout << "assigned" << expr->nodeID << endl;
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
    TreeNode* ch;
    _Type ty;
    cout << "enter tyCheckUnaryExpression " << expr->optype << endl;
    switch (expr->optype){
    case OP_UNA_DEREF:  //*
        ch = expr->child;
        
        tyCheckExpression(ch);
        tyAdjust(ch, 1);
        cout << "* child checked" <<endl;
        ty = ch->sysType;
        assert(ty != NULL);
        if(ch->optype == OP_UNA_REF){
            /**
             * *&a = a;
             */
            expr->child->child->sysType = ty->bty;
            expr->child->child->copyto(expr);
            expr->child = NULL;
            // cout << expr->child->child->nodeID << endl;
            // //move up child child
            // expr->father->child = expr->child->child;
            // expr->father->child->father = expr->father;
            // expr->father->child->sibling = expr->sibling;
            //expr->father = NULL;

            //delete expr
            return true;
        }
        if(IsPtrType(ty)){
            // The operand of the unary * operator shall have pointer type. 
            expr->sysType = ty->bty;
            if(IsFunctionType(expr->sysType)){
                expr->child->child->copyto(expr);
                expr->child = NULL;
                //expr->father->child = expr->child;
                // expr->father->child->father = expr->father;
                // expr->father->child->sibling = expr->sibling;
                // expr->father = NULL;
                return true;
            }

            if(expr->sysType->categ == ARRAY || sysTyIsArr(expr->child->typeMark)){
                TreeNode* one = new TreeNode(expr->lineno, NODE_CONST);
                one->int_val = 1;
                one->type = TYPE_INT;
                one->sysType = T(INT);
                tyCheckPrimaryExpression(one);
                expr->addChild(one);
                expr->optype = OP_OFFSET_ACCESS;
            }
            expr->l_value = 1;
            return true;
        }
        cout << "unary * fail" << endl;
        break;

    case OP_UNA_REF:    //&
        cout << "&" << expr->nodeID<< endl;
        ch = expr->child;
        tyCheckExpression(ch);
        assert(ch->sysType != NULL);
        //tyAdjust(ch, 1); //!!!no need for this

        ty = ch->sysType;
        if(ch->optype == OP_OFFSET_ACCESS){
            /**
             * &*a = a;
             * !!! &*ptr not a lvalue.
             */
            //move up child child
            expr->child->child->l_value = 0;
            expr->father->child = expr->child->child;
            expr->father->child->father = expr->father;
            expr->father->child->sibling = expr->sibling;
            expr->father = NULL;

            //delete expr
            return true;
        }
        if(IsFunctionType(ty) || (expr->child->l_value)){
            expr->l_value = 0;
            expr->sysType = PointerTo(ty);
            cout << "& pointer set" << endl;
            return true;
        }
        cout << "unary & fail" << endl;
        break;
    default:
        cout << "暂不支持" <<endl;
        return false;
    }
RETERROR:
    cout << "error happend in tyCheckUnaryExpression" <<endl;
    return false;
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
    //assert(expr->nodeID != 148);
    TreeNode* ln, *rn;
    ln = expr->child;
    rn = ln->sibling;

    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    _Type ty1, ty2;

    if(ln->optype == OP_CONST){
        cout << "SWAP" << endl;
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

    cout << "inner error of tyCheckShiftOP" << endl;
    exit(1);
}

bool tyCheckRelationalOP(TreeNode* expr){
    TreeNode* ln, *rn;
    ln = expr->child;
    assert(ln != NULL);
    rn = ln->sibling;
    assert(rn != NULL);
    
    tyCheckExpression(ln);
    tyAdjust(ln, 1);
    tyCheckExpression(rn);
    tyAdjust(rn, 1);

    
    _Type ty1, ty2;
    ty1 = ln->sysType;
    ty2 = rn->sysType;
    //default
    expr->sysType = T(INT);
    //cout << "both side checked\n";
    if(IsArithType(ty1) && IsArithType(ty2)){
        ARITH_CONVERSION(expr);
        //cout << "ARITH_CONVERSION return" << endl;
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
    cout << "error in tyCheckRelationalOP" << endl;
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
    
    TreeNode* casgn = new TreeNode(expr->lineno, expr->nodeType);
    casgn->addChild(expr->child);
    expr->child = casgn;
    casgn->father = expr;

    casgn->optype = (expr->optype == OP_POSTSELFINC || expr->optype == OP_PRESELFINC) ? OP_AS_ADDEQ : OP_AS_SUB_EQ;
    
    // Node one is already checked
    
    casgn->addChild(one);
    // check "a"
    if(!tyCheckExpression(casgn->child))return false;
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
    TreeNode* orinode = new TreeNode(expr->nodeID, NODE_EXPR);
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
    //cout << "casting nodeID " << expr->nodeID << "  from " << scode << " to " << dcode <<endl;
    //void 
    if (dcode == V){
        cout << "VVVV" << endl;
        CastExpression(expr, ty);
        return;
    }
    //same space
    if(scode < F4 && dcode < F4 && scode / 2 ==dcode / 2){
        int scateg = expr->sysType->categ;
        int dcateg = ty->categ;
        if(scateg != dcateg && scateg >= INT && scateg < DOUBLE){
            cout << "adding cast node" <<endl;
            CastExpression(expr, ty);
        }
        //cout << "adding / no adding cast node" << endl;
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

    cout << "bigger change in cast\n";
    exit(0);

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
        //cout << expr->nodeID << " tyCheckPostfixExpression OP_OFFSET_ACCESS" << endl;
        if (ISObjevtPtr(ln->sysType) && IsIntType(rn->sysType)){
            cout << expr->nodeID << " tyCheckPostfixExpression OP_OFFSET_ACCESS" << endl;
            expr->sysType = ln->sysType->bty;
            //if(expr->sysType == T(INT)) cout << "??????" << endl;
            expr->l_value = 1;
            DoIntegerPromotion(rn);
            //cout << expr->sysType->size<<endl;
            cout << rn << endl;
            ln->sibling = rn = ScalePointerOffset(rn, expr->sysType->size);
            cout << rn << endl;

            /**
             * int ptr**;
             * int arr[2][2];
             * ptr = arr;
             * 
             * ptr[0][0] = 1;  <== 此时会触发下面的条件，由于ptr经adjust后typemark无标记
             **/
            if(!sysTyIsArr(ln->typeMark) && ln->sysType->categ != ARRAY){
                TreeNode *deref, *addexpr;
                cout << "ptr** checkpoint" << endl;
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
                cout << "Arr access add deref" << endl;
                return deref;
            }
        }
        //cout << expr->nodeID << " tyCheckPostfixExpression OP_OFFSET_ACCESS" << endl;
        //cout << expr->sysType->size<<endl;
        return expr;

    case OP_POSTSELFDEC:
    case OP_POSTSELFINC:
        tyTransformIncrement(expr);
        return expr;
    case OP_FUNC_CALL:
        if(expr->nodeID == 144) cout << "XXXX" << endl;
        tyCheckFunctionCall(expr);
        return expr;
    default:
        cout << "haven't made record member operators\n";
        break;
    }
}


bool tyAdjust(TreeNode* n, int rvalue){
    int qual = 0;
    //if this node is treated as rvalue
    cout << "adjust  " << n->nodeID <<endl;
    assert(n->sysType != NULL);
    if(rvalue){
        qual = n->sysType->qual;
        n->sysType = UnQualify(n->sysType);
        cout << "set l_val" << endl;
        n->l_value = 0;
    }
    //cout << "adjust 2" << endl;
    //assert(n->nodeID != 138);
    if(n->sysType->categ == FUNCTION){
        n->sysType = PointerTo(n->sysType);

        n->typeMark = sysTyClear(n->typeMark);
        n->typeMark = sysTySetFunc(n->typeMark);
        cout << "adjust to func ptr id: " << n->nodeID << endl;
    }
    else if(n->sysType->categ == ARRAY){
        n->sysType = PointerTo(Qualify(qual, n->sysType->bty));
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
        //cout << "NodeId: " << n->nodeID << " point to array" << endl;
    }
    //cout << "adjust 3" << endl;
    return true;
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
    expr->printAST();
    return expr;
}

static int CanModify(TreeNode* expr){
    return (expr->l_value && !(expr->sysType->qual & SHIFT_CONST));
}

void printUndefFunc(TreeNode* expr){
    cout << "undefined function call "<< expr->var_name <<", line: " << expr->lineno << endl;
}

bool tyCheckFunctionCall(TreeNode*expr){
    TreeNode* func = expr->child;
    TreeNode* auges = func->sibling;
    cout << "enter tyCheckFunctionCall nodeid:"<<expr->nodeID << endl;
    
    if(func->nodeType != NODE_VAR){
        cout << "syntax design error" << endl;
        exit(1);
    }
    if(auges->nodeType != NODE_ARGUMENT_LIST){
        cout << "main.y error caused tyCheckFunctionCall error" << endl;
        exit(1);
    }
    
    //check if func is defined
    if(!func->sysType){
        printUndefFunc(expr);
    }
    else{
        tyAdjust(func, 1);
    }
    
    _Type ty;
    if(!(IsPtrType(func->sysType)&&IsFunctionType(func->sysType->bty)) ){
        cout <<"line: " <<expr->lineno  <<", The left op must be function or function ptr" <<endl;
        exit(1);
    }else{
        ty = func->sysType->bty;
    }
    //now ty is FUNCTION
    int argNo = 1;
    bool argfull = false;
    
    TreeNode* arg = auges->child;

    while(arg != NULL && !argfull){
        tyCheckArgument(arg, (_FunctionType)ty, argNo, &argfull);
        arg = arg->sibling;
        //cout << argfull << endl;
        argNo++;
    }
    while(arg != NULL){
        tyCheckExpression(arg);
        arg = arg->sibling;
        argNo++;
    }

    argNo--;
    if(argNo > ((_FunctionType)ty)->param_types.size()){
        if (!((_FunctionType)ty)->Ellipsis){
            cout << "function receives too many arguments, line" << expr->lineno << endl;
        }
    }
    else if (argNo < ((_FunctionType)ty)->param_types.size()){
        cout << "function receives too few arguments, line" << expr->lineno << endl;
    }

    expr->sysType = ty->bty;

    return expr;
}


bool tyCheckArgument(TreeNode* arg, _FunctionType fty, int argNo, bool* argFull){
    int parLen = fty->param_types.size();
    
    tyCheckExpression(arg);
    tyAdjust(arg, 1);
    //cout << "enter tyCheckArgument, argno: "<<argNo << ", of total: " << parLen<< endl;

    if(fty->hasProto && parLen == 0){
        *argFull = 1;
        return true;
    }
    if((argNo == parLen) && (!fty->Ellipsis)){
        //cout << "full now" << endl;
        *argFull = 1;
    }
    
    if (!fty->hasProto){
        _Type pty = Promote(arg->sysType);
        Cast(arg, pty);
        *argFull = 0;
        return true;
    }
    else if(argNo <= parLen){
       // cout << "testing next argu" << endl;
        _Type param_ty = fty->param_types[argNo-1];
        assert(param_ty != NULL);
        if(!CanAssign(arg, param_ty)) goto err;
        //cout << param_ty << endl;
        if(param_ty->categ < INT){
            Cast(arg, T(INT));
        }
        else{
            Cast(arg, param_ty);
        }   
        return true;
    }
    else{
        cout << "other situations, should't get here\n";
        exit(1);
    }
err:
    cout << arg->lineno << " id:"<<arg->nodeID << " Incompatible argument \n";
    return false;
}

_Type Promote(_Type ty){
    return ty->categ < INT ? T(INT) : ty;
}