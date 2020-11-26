#include "tree.h"

int TreeNode::_now_id = 0;
#define func_all_children(childptr, func) \
    if(!childptr) cout << "none"; \
    while(childptr){                \
        func(childptr);\
        childptr = childptr->sibling;\
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
    cout << endl;
    struct TreeNode* childptr = child;
    all_children_call(childptr, printAST);
}



// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONST:
            break;
        case NODE_VAR:
            break;
        case NODE_EXPR:
            break;
        case NODE_STMT:
            break;
        case NODE_TYPE:
            break;
        default:
            break;
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
