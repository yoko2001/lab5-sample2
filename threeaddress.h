#ifndef __THREE_ADDRESS__
#define __THREE_ADDRESS__

#include"pch.h"
#include"tree.h"
enum tri_addr_inst_type{
    assign_two_ops_one_oprt,    //x = y op z  [x, y, z]
    assign_one_op_one_oprt,     //x = op y [x, y, 0]
    assign_one_op_zero_oprt,    //x = y    [x, y, 0]
    goto_L,         //goto L               [0, 0, L]
    if_true_jump,   //if x goto L          [x, 0, L]
    if_false_jump,  //if not x goto L      [x, 0, L]
    if_rel_jump,    //if(x relop y) goto L [x, y, L]
    parameter,   //paraeter x => [x, 0, 0]
    call_p_n,    //(y) = p(p1,p2, ..pn) => [(y), p, n]
    index_right, //a = b[i] => [a, b, i]
    index_left,  //a[i] = b => [a,  i, b]
    ref,        //a = &b   => [a, b, 0]
    deref_left, //*a = b   => [a, b, 0]         
    deref_right,//a = *b   => [a, b, 0]
};
typedef struct _tri_addr_node{
    int traID;
    int nodeID; //原treeNode的id
    tri_addr_inst_type inst;
    OperatorType op;
    int arg1;
    int arg2;
    int result;
}tri_addr_node;



#endif