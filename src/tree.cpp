#include "tree.h"
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
    }else{
        //cout << "addding child"<<child->nodeID <<" to "<<nodeID<<endl;
        this->child = child;
    }
    
}

void TreeNode::addSibling(TreeNode* sibling){
    //cout << "adding sibling "<< sibling->nodeID << " to "<< this->nodeID <<endl;
    TreeNode* start = this->sibling;
    TreeNode* tail = nullptr;
    if (!start){
        this->sibling = sibling;
        return;
    }
    get_tail(start, tail, sibling);
    tail->sibling = sibling;
}

TreeNode::TreeNode(int lineno, NodeType type):lineno(lineno), nodeType(type){
    genNodeId();    //assign a ID for node
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
                cout << "string";
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
        case NODE_FOR:
            cout << "[iteration for]";
            break;
        case NODE_WHILE:
            cout << "[iteration while]";
            break;
        case NODE_DO_WHILE:
            cout << "[iteration do while]";
            break;
        case NODE_BREAK:
            cout << "[BREAK]";
            break;
        case NODE_CONTINUE:
            cout << "[CONTINUE]";
            break;
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
    case STMT_BLOCK:
        cout << "block";
        break;
    case STMT_SKIP:
        cout << "skip";
        break;
    case STMT_DECL:
        cout << "declaration";
        break;
    case STMT_COMPOUND:
        cout << "compound";
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

_Type TreeNode::NODE_DECL_Dump(_Type typeSp){
    if(typeSp && (this->nodeType == NODE_DECLARATOR)){
        if (this->child->nodeType == NODE_VAR){
            cout << this->child->var_name<< " is set to type @" << typeSp << endl; 
        }
        return typeSp;
    }
    _Type retType;
    //ARRAY
    if (this->nodeType == NODE_TYPE &&
             this->type->type == VALUE_ARRAY){
            //递归
            cout << "got array \n";
            retType = ArrayOf(5, typeSp);
            return this->child->NODE_DECL_Dump(retType);
        }
    if (this->nodeType == NODE_VAR){
        cout << this->var_name<< " is set to type @" << typeSp << endl; 
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
                retType = ExtendVarNode->child->NODE_DECL_Dump(retType);
            }else if (ExtendVarNode->nodeType == NODE_PT_DECLARATOR){
                _Type pointered = PointerTo(typeSp);
                //递归
                retType = ExtendVarNode->child->NODE_DECL_Dump(pointered);
            }
        }
        if (init_or_no_init_node->nodeType == NODE_DECL_VARS){
            cout << "NODE_DECL_VARS\n";
            ExtendVarNode = init_or_no_init_node->child;
            if (!ExtendVarNode) return NULL;
            if (ExtendVarNode->nodeType == NODE_DECLARATOR){
                //这里找到了
                retType = typeSp;
                retType = ExtendVarNode->child->NODE_DECL_Dump(retType);
            }
            else if (ExtendVarNode->nodeType == NODE_PT_DECLARATOR){
                _Type pointered = PointerTo(typeSp);
                //递归
                retType = ExtendVarNode->child->NODE_DECL_Dump(pointered);
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
        _Type t = decl_node->NODE_DECL_Dump(typeSp);
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
        cout << t->size<<endl;
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
    while(paranode){
        _Type paratype = NULL;
        if (paranode->nodeType == NODE_PARA_DECL){
            paratype = paranode->child->NODE_DECL_SPCT_Dump(paratype);
            paratype = paranode->child->sibling->NODE_DECL_Dump(paratype);
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

        _FunctionType func_ret_type = (_FunctionType)malloc(sizeof(struct functionType));
        memset(func_ret_type, 0, sizeof(struct functionType));
        func_ret_type->categ = FUNCTION;
        if (!(spcf->nodeType == NODE_DECL_SPCF)){
            cout << nodeID << " wrong\n"; 
            return;
        }
        cout << "get function specifier\n";
        func_ret_type->bty = spcf->NODE_DECL_SPCT_Dump(func_ret_type->bty);

        cout << "get function params\n";
        if (!(dcl_and_paras->nodeType == NODE_DECL_FUNC)){
            cout << nodeID << " wrong\n"; 
            return;
        }
        func_ret_type->bty = dcl_and_paras->child->NODE_DECL_Dump(func_ret_type->bty);
        func_ret_type = dcl_and_paras->child->sibling->NODE_PARA_LIST_Dump(func_ret_type);
        cout << func_ret_type << " func set\n"; 
        return;
    }
    TreeNode* c = this->child;
    while(c){
        c->funcTypeDump();
        c = c->sibling;
    }
    return;
}