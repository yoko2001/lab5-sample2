#ifndef __STMT_CHCK__
#define __STMT_CHCK__
#include"tree.h"
#include"domain.h"
#include"error.h"
#include"exprchck.h"
bool tyCheckStatement(TreeNode* stmt);

struct CURRENT_STATUS{
    vector<TreeNode*> loops;
    vector<TreeNode*> breakable;
    bool has_return;
};
#endif