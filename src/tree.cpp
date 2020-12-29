#include "tree.h"
#include "error.h"
#include "exprchck.h"
#include "stmtchck.h"
extern TreeNode* null_node;

int TreeNode::_now_id = 0;
#define func_all_children(childptr, func) \
    if(!childptr) cout << "none"; \
    while(childptr){                \
        func(childptr);\
        childptr = childptr->sibling;\
    }           

#define if_exists_print_special(node) \
    if (this->child){   \
        this->child->printSpecialInfo(); \
    }\
    else { \
        cout << "none"; \
    }

#define all_children_call(childptr, func)\
    while(childptr){\
        childptr->func();\
        childptr = childptr->sibling;\
    }

#define get_tail(startptr, tailptr, association)\
    tailptr = startptr;\
    while(startptr){\
        tailptr = startptr;\
        startptr = startptr->association;\
    }

void TreeNode::addChild(TreeNode* child) {
    
    assert(child!=nullptr);
    //cout << "add child\n";
    if (this->child){
        //cout << "addding child"<< child->nodeID <<" to" <<nodeID<<endl;
        this->child->addSibling(child);
        child->father = this;
    }else{
        //cout << "addding child"<<child->nodeID <<" to "<<nodeID<<endl;
        this->child = child;
        child->father = this;
    }

    TreeNode* c = child;
    while(c){
        c->father = this;
        c = c->sibling;
    }
    
}

void TreeNode::addSibling(TreeNode* sibling){
    //cout << "adding sibling "<< sibling->nodeID << " to "<< this->nodeID <<endl;
    TreeNode* start = this->sibling;
    TreeNode* tail = nullptr;
    if (!start){
        this->sibling = sibling;
        sibling->father = this->father;
        return;
    }
    get_tail(start, tail, sibling);
    tail->sibling = sibling;
    sibling->father = this->father;
}

void TreeNode::copyto(TreeNode* nn){
    nn->sysType = sysType;
    nn->type = type;
    nn->typeMark = typeMark;
    nn->var_name = var_name;
    nn->nodeID = nodeID;
    nn->nodeType = nodeType;
    nn->optype = optype;
    nn->p_val = p_val;
    nn->sibling = sibling;
    nn->str_val = str_val;
    nn->stype = stype;
    nn->lineno = lineno;
}

TreeNode::TreeNode(int lineno, NodeType type):lineno(lineno), nodeType(type){
    genNodeId();    //assign a ID for node
    this->sysType = NULL;
    //_now_id = 0;
    //cout << "build success,type: " <<nodeType2String(type)<<endl; 
}

void TreeNode::genNodeId() {
    nodeID = _now_id++;
   //cout<<_now_id<<endl;
}

void TreeNode::printNodeInfo() {
    cout << "lno@:"  << setw(4) << lineno ; 
    cout << "  @" << nodeID;
    cout << setw(15) <<nodeType2String(nodeType) ;
}

void TreeNode::printChildrenId() {
    struct TreeNode* childptr;
    childptr = this->child;
    if(!childptr) return;
    cout << "[ ";
    func_all_children(childptr, __printNodeId);
    cout << " ]";
}

void TreeNode::__printNodeId(TreeNode* tn){
    cout << "@" << tn->nodeID << " ";
}

void TreeNode::printAST() {
    printNodeInfo();
    printChildrenId();
    printSpecialInfo();
    cout << endl;
    struct TreeNode* childptr = child;
    all_children_call(childptr, printAST);
}



// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_VAR:
            cout << " variable: "<< this->var_name;
            break;
        
        case NODE_CONST:
            if (!this->type){
                cout << "[error]";
            }
            else if (this->type == TYPE_INT){

                cout<< " val: " << this->int_val;
            }
            else if (this->type == TYPE_BOOL){
                cout << " val: " <<this->b_val;
            }
            else if (this->type == TYPE_ARRAY){
                cout << "array of: ";
                //if_exists_print_special(this->child);
            }
            else if (this->type == TYPE_POINTER){
                cout << "pointer of: ";
                //if_exists_print_special(this->sibling);
            }else if (this->type == TYPE_STRING){
                cout << " : "<<this->str_val;
            }else if (this->type == TYPE_SIGNED){
                cout << "signed";
            }else if (this->type == TYPE_UNSIGNED){
                cout << "unsigned";
            }else if (this->type == TYPE_CONST){
                cout << "const";
            }else{
                cout << "lost";
            }
            break;
        case NODE_EXPR:
            print_expr_info();
            break;
        case NODE_STMT:
            print_stme_info();
            break;
        case NODE_TYPE:
            //cout << "???\n";
            print_type_info();
            break;
        case NODE_DECL_INIT:
            cout << "[initializer]";
            break;
        // case NODE_FOR:
        //     cout << "[iteration for]";
        //     break;
        // case NODE_WHILE:
        //     cout << "[iteration while]";
        //     break;
        // case NODE_DO_WHILE:
        //     cout << "[iteration do while]";
        //     break;
        // case NODE_BREAK:
        //     cout << "[BREAK]";
        //     break;
        // case NODE_CONTINUE:
        //     cout << "[CONTINUE]";
        //     break;
        case NODE_OP:
            cout << "[operator]";
            break;
        case NODE_ASSI:
            cout << "=";
            break;
        default:
            break;
    }
}

void TreeNode::print_stme_info(){
    if (!this->stype){
        return;
    }
    switch (this->stype)
    {
    case STMT_SELECT:
        cout << "select";
        break;
    case STMT_SKIP:
        cout << "skip";
        break;
    case STMT_DECL:
        cout << "declaration";
        break;
    case STMT_COMPOUND:
        cout << "compound";
        break;
    case STMT_WHILE:
        cout << "while";
        break;
    case STMT_DO_WHILE:
        cout << "do while";
        break;
    case STMT_FOR:
        cout << "for";
        break;
    case STMT_FOR_NONE:
        cout << "for NULL";
        break;
    case STMT_BREAK:
        cout << "[BREAK]";
        break;
    case STMT_RETURN:
        cout << "[RETURN]";
        break;
    case STMT_CONTINUE:
        cout << "[CONTINUE]";
        break; 
    case STMT_EXPRESSION:
        cout<< "EXPRESSION";
        break;
    default:
        break;
    }
}
void TreeNode::print_expr_info(){
    if(this->nodeType != NODE_EXPR) return;

    switch (this->optype)
    {
    case OP_ASSIGN:
        cout << "=";
        break;
    case OP_OFFSET_ACCESS:
        cout << "[]";
        break;
    case OP_ADD:
        cout << "+";
    default:
        break;
    }
}

void TreeNode::print_type_info(){
    if(!(this->nodeType == NODE_TYPE)) return;
   
    cout << this->type->getTypeInfo();
    if (this->type && this->child && this->type == TYPE_ARRAY){ 
        this->child->print_type_info();
    }
}
string TreeNode::sType2String(StmtType type) {
    return "?";
}



string TreeNode::nodeType2String (NodeType type){
    string ret = "";
    switch (type)
    {
    case NODE_CONST:
        ret = "NODE_CONST";
        break;
    case NODE_STMT:
        ret = "NODE_STMT";
        break;
    case NODE_EXPR:
        ret = "NODE_EXPR";
        break;
    case NODE_VAR:
        ret = "NODE_VAR";
        break;
    case NODE_PROG:
        ret = "NODE_PROG";
        break;
    case NODE_DECL:
        ret = "FATHER_DECL";
        break;
    case NODE_INIT_DECL_VARS:
        ret = "NODE_INIT_DECL_VARS";
        break;
    case NODE_DECL_VARS:
        ret = "NODE_DECL_VARS";
        break;
    case NODE_DECL_FUNC:
        ret = "NODE_DECL_FUNC";
        break;
    case NODE_EXTERN_DECL:
        ret = "NODE_EXTERN_DECL";
        break;
    case NODE_EXTERN_FUNC_DECL:
        ret = "NODE_EXTERN_FUNC_DECL";
        break;
    case NODE_DECL_LIST:
        ret = "NODE_DECL_LIST";
        break;
    case NODE_PT_DECLARATOR:
        ret = "PT_DECL_NODE";
        break;
    case NODE_DECLARATOR:
        ret = "direct DECLARATOR";
        break;
    case NODE_PARA_DECL_LIST:
        ret = "PARA_LIST_NODE";
        break;
    case NODE_PARA_DECL:
        ret = "PARA_NODE";
        break;
    case NODE_DECL_SPCF:
        ret = "NODE_DECL_SPCF";
        break;
    default:
        break;
    }
    return ret;
}

_Type TreeNode::NODE_DECL_Dump(_Type typeSp, char* func_name){
    
    //parameters
    if(typeSp && (this->nodeType == NODE_DECLARATOR)){
        if (this->child->nodeType == NODE_VAR){ 
            strcpy(func_name, (child->var_name).c_str());
            //cout << child->var_name.c_str() << endl;
            if (this->father->domain)
                this->father->domain->add_element(func_name, this->lineno, typeSp);
            //cout << func_name << " is set to type @" << typeSp << endl; 
            //cout << this->father->domain->domainid << " " << this->nodeID <<" " <<this->lineno<<" ckpt1\n";
        }
        return typeSp;
    }
    _Type retType;

    //ARRAY
    if (this->nodeType == NODE_TYPE &&
    this->type->type == VALUE_ARRAY){
        //递归
        int len = this->child->sibling->int_val;
        if (this->child->sibling->nodeType != NODE_CONST){
            cout << "havn't implement const fold, calculate it yourself";
            exit(1);
        }
        cout << "got array len " << len << "of size: " << typeSp->size<<endl;
        retType = ArrayOf(len, typeSp);
        return this->child->NODE_DECL_Dump(retType, func_name);
    }

    if (this->nodeType == NODE_VAR){
        //cout << this->var_name<< " return type set to type @" << typeSp << endl; 
        //cout << "ckpt2\n";
        if (!func_name) cout << "???\n";
        strcpy(func_name, (this->var_name).c_str());
        if(this->father->domain && !(this->father->nodeType == NODE_DECL_FUNC)){
            this->father->domain->add_element(func_name, this->lineno, typeSp);
            //cout << "XXX" << endl;
        }
        return typeSp;
    }
    if (((this->nodeType != NODE_DECL) || (typeSp == NULL) )){
        cout << "wrong call NODE_DECL_Dump" << this->nodeID <<" "<<typeSp<< endl;
        return typeSp;
    }
    TreeNode* init_or_no_init_node = this->child;
    TreeNode* ExtendVarNode = NULL;
    
    retType = typeSp;
    cout <<  this->nodeID <<endl;

    if (init_or_no_init_node){
        if (init_or_no_init_node->nodeType == NODE_INIT_DECL_VARS){
            cout << "NODE_INIT_DECL_VARS\n";
            //POINTER
            ExtendVarNode = init_or_no_init_node->child;
            if (!ExtendVarNode) return NULL;
            if (ExtendVarNode->nodeType == NODE_DECLARATOR){
                //这里找到了
                retType = typeSp;
                retType = ExtendVarNode->child->NODE_DECL_Dump(retType, func_name);
            }else if (ExtendVarNode->nodeType == NODE_PT_DECLARATOR){
                _Type pointered = PointerTo(typeSp);
                //递归
                retType = ExtendVarNode->child->NODE_DECL_Dump(pointered, func_name);
            }
        }
        if (init_or_no_init_node->nodeType == NODE_DECL_VARS){
            cout << "NODE_DECL_VARS\n";
            ExtendVarNode = init_or_no_init_node->child;
            if (!ExtendVarNode) return NULL;
            if (ExtendVarNode->nodeType == NODE_DECLARATOR){
                //这里找到了
                retType = typeSp;
                retType = ExtendVarNode->child->NODE_DECL_Dump(retType, func_name);
            }
            else if (ExtendVarNode->nodeType == NODE_PT_DECLARATOR){
                _Type pointered = PointerTo(typeSp);
                printf("pointer\n");
                //递归
                retType = ExtendVarNode->child->NODE_DECL_Dump(pointered, func_name);
            }
        }
        //ARRAY
    }
    return retType;
}

_Type TreeNode::NODE_DECL_SPCT_Dump(_Type typeSp){
    if(this->nodeType != NODE_DECL_SPCF){
        cout << "wrong call NODE_DECL_SPCT_Dump "<<this->nodeID << endl;
        return typeSp;
    }
    TreeNode* specifier = this->child;
    _Type retType = NULL;
    int _unsigned = 0;
    int _const = 0;
    while(specifier && specifier->nodeType == NODE_TYPE){
        if (specifier->type->type == VALUE_CONST){
            _const = 1;
        }
        if (specifier->type->type == VALUE_UNSIGNED){
            _unsigned = 1;
        }
        if (specifier->type->type == VALUE_SIGNED){
            _unsigned = 0;
        }
        if (specifier->type->type == VALUE_VOID){
            if (retType) {
                cout << "ERROR more than one type\n";
                return retType; //
            }
            int mark = 0;
            if (_const) mark+=SHIFT_CONST;
            retType = T(VOID);
            retType = Qualify(mark, retType); 
        }
        if (specifier->type->type == VALUE_INT){
            if (retType) {
                cout << "ERROR more than one type\n";
                return retType; //
            }
            int mark = 0;
            if (_const) mark+=SHIFT_CONST;
            if (_unsigned) retType = T(UINT);
            else retType = T(INT);
            retType = Qualify(mark, retType);
        }
        if (specifier->type->type == VALUE_CHAR){
            if (retType) {
                cout << "ERROR more than one type\n";
                return retType; //
            }
            int mark = 0;
            if (_const) mark+=SHIFT_CONST;
            if (_unsigned) retType = T(UCHAR);
            else retType = T(CCHAR);
            retType = Qualify(mark, retType);
        }
        specifier = specifier->sibling;
    }
    return retType;
}

_Type TreeNode::NODE_DECL_LIST_Dump(_Type typeSp){
    if(!(this->nodeType == NODE_DECL_LIST)){
        cout << "should't call NODE_DECL_LIST_Dump";
        return NULL;
    }
    TreeNode* decl_node = this->child;  //FATHER NODE_DECL
    while(decl_node){
        char* tmp = (char*)malloc(sizeof(__u_char) * MAX_ID_LEN);
        tmp[0] = '\0';
        _Type t = decl_node->NODE_DECL_Dump(typeSp, tmp);
        cout << "decl node's size of type is: " << t->size<<endl;
        decl_node = decl_node->sibling;
    }
    return typeSp;
}

_Type TreeNode::NODE_STMT_Dump(){
    if(!(this->nodeType == NODE_STMT)){
        cout << "should't call NODE_STMT_Dump: " <<this->nodeID << endl;
        return NULL;
    }
    _Type t = NULL;
    //check specifier and declaration
    if(this->child && this->child->sibling){
        t = this->child->NODE_DECL_SPCT_Dump(t);
        cout << "basic size of type is: " << t->size<<endl;
        //cout << "list dump: \n";
        this->child->sibling->NODE_DECL_LIST_Dump(t);
    }
    return t;
}

void TreeNode::typeDump(){
    if ((this->nodeType == NODE_STMT) && (this->stype == STMT_DECL)){
        this->NODE_STMT_Dump();
        return;
    }
    if (this->child){
        TreeNode* c = this->child;
        while(c){
            c->typeDump();
            c = c->sibling;
        }
    }
    return;
}
_FunctionType TreeNode::NODE_PARA_LIST_Dump(_FunctionType fty){
    if(!(this->nodeType == NODE_PARA_DECL_LIST)){
        cout << "should't call NODE_PARA_LIST_Dump: " <<this->nodeID << endl;
    }
    TreeNode* paranode = this->child;
    char tmp[100];
    while(paranode){
        _Type paratype = NULL;
        if (paranode->nodeType == NODE_PARA_DECL){
            paratype = paranode->child->NODE_DECL_SPCT_Dump(paratype);
            if(paranode->child->sibling)
                paratype = paranode->child->sibling->NODE_DECL_Dump(paratype, tmp);
            cout << "para size: " << paratype->size<<endl;
        }
        fty->param_types.push_back(paratype);
        paranode = paranode->sibling;
    }
    return fty;
}

void TreeNode::funcTypeDump(){
    if((this->nodeType == NODE_EXTERN_FUNC_DECL)){
        TreeNode* spcf = this->child;
        TreeNode* dcl_and_paras = spcf->sibling->child->child;
        TreeNode* cmpd = this->child->sibling->sibling;

        _FunctionType func_ret_type = (_FunctionType)malloc(sizeof(struct functionType));
        memset(func_ret_type, 0, sizeof(struct functionType));
        func_ret_type->categ = FUNCTION;
        if (!(spcf->nodeType == NODE_DECL_SPCF)){
            cout << nodeID << " wrong\n"; 
            return;
        }

        //cout << "get function specifier\n";
        func_ret_type->bty = spcf->NODE_DECL_SPCT_Dump(func_ret_type->bty);

        //cout << "get function params\n";
        if (!(dcl_and_paras->nodeType == NODE_DECL_FUNC)){
            cout << nodeID << " wrong\n"; 
            return;
        }
        char funcname[MAX_ID_LEN] ="";
        func_ret_type->bty = dcl_and_paras->child->NODE_DECL_Dump(func_ret_type->bty, funcname);
        func_ret_type = dcl_and_paras->child->sibling->NODE_PARA_LIST_Dump(func_ret_type);
        if (func_ret_type->param_types.size() > 0) func_ret_type->hasProto = true;
        cout <<funcname<< func_ret_type << " func set\n"; 
        this->domain->father_domain->add_element(funcname, this->lineno, (_Type)func_ret_type);
        this->sysType = (_Type)func_ret_type;

        //cmpd->typeDump();
        return;
    }
    TreeNode* c = this->child;
    while(c){
        c->funcTypeDump();
        c = c->sibling;
    }
    return;
}
#define isKWNODE(nt) ((nt == NODE_CONST) || 0)
void TreeNode::domain_dump(){
    if ((this->nodeType == NODE_CONST || this->nodeType == NODE_VAR) || 
        isKWNODE(this->nodeType)) {
            if(!father){
                cout << "no father" << nodeID << endl;
                return;
            }
            domain = father->domain;
            return;
        }
    if (!this->father) {
        
        if (!(this->nodeType == NODE_PROG)){
            cout << "nofather " << nodeID << endl;
            return;
        }
    }
    if (this->nodeType == NODE_STMT && this->stype == STMT_COMPOUND && (this->father->nodeType != NODE_EXTERN_FUNC_DECL)){
        cout << "born_son_domain STMT_COMPOUND\n";
        this->domain = born_son_domain(this->father->domain);
    }
    else if (this->nodeType == NODE_EXTERN_FUNC_DECL){
        cout << "born_son_domain NODE_EXTERN_FUNC_DECL\n";
        this->domain = born_son_domain(this->father->domain);
    }
    else if (this->domain && (this->domain->type==global)){
        cout << "start domain dump\n";
        //return;
    }
    else{
        this->domain = father->domain;
    }
    TreeNode* c = this->child;
    
    while (c)
    {
        c->domain_dump();
        c = c->sibling;
        //return;
    }
    return;
}

void TreeNode::typeCheck(){
    if(!(this->nodeType == NODE_PROG)){
        cout << "only root node can call typeCheck\n";
        exit(1);
    }
    //check all EXTERN_DECLs 
    TreeNode* son = this->child;
    while(son){
        if(son->nodeType == NODE_EXTERN_DECL)
        {
            //son->tyCheckGlobalDeclaration();
            //already checked, do nothing
        }
        else if (son->nodeType == NODE_EXTERN_FUNC_DECL)
        {
            currentfty = (_FunctionType)son->sysType;
            assert(currentfty != NULL);
        }
        else{
            cout << "root node inner error, expected extern (func) delarations" << endl;
        }
        son = son->sibling;
    }
}

void TreeNode::tyCheckGlobalDeclaration(){

}

void TreeNode::CheckInitializerInternal(TreeNode* initializer, _Type ty){
    //ty is one of CHAR, UCHAR, INT, UINT, DOUBLE
    assert(initializer->nodeType == NODE_DECL_INIT);
    if (IsScalarType(ty)){
        //if initilizer is like  { x, x, ...} it has braces on both side
        if(initializer->child && initializer->child->nodeType == NODE_DECL_INIT){
            warning("CheckInitializerInternal", initializer->lineno, "braces around scalar initializer");
        }
        
        if(!tyCheckExpression(initializer->child)){
            error("CheckInitializerInternal", initializer->lineno, "Wrong initializer, braces around scalar");
            return;
        }
        
        if (!CanAssign(initializer->child,ty)){
            error("CheckInitializerInternal", initializer->lineno, "Wrong initializer"); 
        }
    }
}

/**
 * whether "a = b;" is legal.
 * we guarantee that a is not qualified by const
 * [IMPORTANT] call CanModify() before calling CanAssign()
 */
bool CanAssign(TreeNode* expr, _Type lty){
    _Type rty = expr->sysType;
    lty = UnQualify(lty);
    rty = UnQualify(rty);
    /**
     * record type
     */
    if(lty == rty){
        return 1;
    }
    /**
     *  arithmetic type;
     */
    if(IsArithType(lty) && IsArithType(rty)){
        return 1;
    }

    if(IsPtrType(lty) && IsPtrType(rty)){
        return 1;
    }

    if(((IsPtrType(lty) && IsIntType(rty)) || (IsPtrType(rty) && IsIntType(lty))) &&
    (lty->size == rty->size)){
        printf("[warning] conversion between int and pointer with no explicit cast\n");
        return 1;
    }


    return 0;
}
void __redefCheck(TreeNode* node);


void TreeNode::redefCheck(){
    if(father){
        if(domain != father->domain){
            __redefCheck(this);
        }
    }else{
        __redefCheck(this);
    }
    TreeNode* son = child;
    while(son){
        son->redefCheck();
        son = son->sibling;
    }
}

static bool has_redef_error = false;
void printRedefError(domain_elem e1, domain_elem e2){
    cout << "redefination detected, " << e1.s <<endl;
    cout << "first defined here: " << e1.pos << " , then defined here: " << e2.pos << endl;
}
void __redefCheck(TreeNode* node){
    domain* dm = node->domain;
    if(!dm){ 
        cout << "node " << node->nodeID << "has no domain" << endl;
        return;
    }
    int len = dm->elements.size();
    for(int i = 0; i < len; i++){
        //cout << dm->elements[i].s << endl;
        for(int j = i+1; j < len; j++){
            if (!(dm->elements[i].s == dm->elements[j].s))continue;
            printRedefError(dm->elements[i], dm->elements[j]);
            has_redef_error = true;
        }
    }
}

void __check_undef(TreeNode* node);
void TreeNode::tyCheckUndef(){
    if(nodeType == NODE_VAR){
        __check_undef(this);
    }

    TreeNode* son = child;
    while(son){
        son->tyCheckUndef();
        son = son->sibling;
    }
}
void print_undef_error(TreeNode* var){
    cout << "undefined variable: " << var->var_name << endl;
}
void __check_undef(TreeNode* node){
    assert(node->nodeType == NODE_VAR);
    domain* dm = node->domain;
    if(!dm){
        cout << "node "<<node->nodeID << " has no domain" << endl;
        return;
    }
    
    bool found = false;
    while(dm){
        //cout << "now check domain " << dm->domainid << "size" <<dm->elements.size()<<endl;
        int len = dm->elements.size();
        for(int i = 0; i < len; i++){
            if (node->var_name == dm->elements[i].s){
                found = true;
                node->sysType = dm->elements[i].ty;
                cout <<node->var_name  << " pos: "<<node->lineno << " sysType: " << node->sysType << " dm: " << dm->domainid << endl;
                break;
            }
        }
        if (found) break;
        dm = dm->father_domain;
    }
    if(!found){
        print_undef_error(node);
    }
}