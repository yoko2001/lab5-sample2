#include"inter.h"

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

static void AddPredecessor(BBlock to, BBlock from){
    CFGEdge e;
    e = (CFGEdge) malloc(sizeof(struct cfgedge));
    e->bb = from;
    
    //add edge an edge from "from" to pred list of "to"
    e->next = to->preds;
    to->preds = e;
    to->npred++;
}