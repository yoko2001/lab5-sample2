#ifndef __EXPR_CHECK__
#define __EXPR_CHECK__

#include"tree.h"
#include"domain.h"
#include"error.h"
bool tyCheckExpression(TreeNode* init);
void Cast(TreeNode* expr, _Type ty);
#endif