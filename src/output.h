#ifndef __OUTPUT__
#define __OUTPUT__

#include"reg.h"
#include"tree.h"


void EmitProg(TreeNode* program);
void EmitFunction(TreeNode* func);
void SetupReg();
#endif