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
    default:
        break;
    }
    return ret;
}
