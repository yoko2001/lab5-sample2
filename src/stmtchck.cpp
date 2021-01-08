#include"stmtchck.h"
static struct CURRENT_STATUS CURRENTST;

bool tyCheckCompoundStatement(TreeNode* stmt);
bool tyCheckForStatement(TreeNode* stmt);
bool tyCheckContinueStatement(TreeNode* stmt);
bool tyCheckReturnStatement(TreeNode* stmt);
bool tyCheckBreakStatement(TreeNode* stmt);
bool tyCheckLoopStatement(TreeNode* stmt);
bool tyCheckSelectStatement(TreeNode* stmt);
bool tyCheckExpressionStatement(TreeNode* stmt);
bool tyCheckIOStatement(TreeNode* stmt);
bool tyCheckStatement(TreeNode* stmt){
    //cout << "cheking stmt :" << stmt->nodeID << endl;
    if(stmt->nodeType == NODE_STMT){
        switch(stmt->stype){
            case STMT_DECL:
                break;
            case STMT_COMPOUND:
                tyCheckCompoundStatement(stmt);
                break;
            case STMT_SKIP:
                break;
            case STMT_FOR:
            case STMT_FOR_NONE:
                tyCheckForStatement(stmt);
                break;
            case STMT_CONTINUE:
                tyCheckContinueStatement(stmt);
                break;
            case STMT_RETURN:
                tyCheckReturnStatement(stmt);
                break;
            case STMT_BREAK:
                tyCheckBreakStatement(stmt);
                break;
            case STMT_WHILE:
            case STMT_DO_WHILE:
                tyCheckLoopStatement(stmt);
                break;
            case STMT_SELECT:
                tyCheckSelectStatement(stmt);
                break;
            case STMT_EXPRESSION:
                //cout << "ckpt expr stmt " << stmt->nodeID << endl;
                tyCheckExpressionStatement(stmt);
                //cout << "ckpt expr stmt finish" << stmt->nodeID << endl;
                break;
            case STMT_SCANF:
            case STMT_PRINTF:
                tyCheckIOStatement(stmt);
                break;
            default:
                cout << "this kind of statement check unrealized: nodeID: " << stmt->nodeID << endl;
        }
        return true;
    }else{
        cout << stmt->nodeType<<endl;
        cout << "shouldn't call tyCheckStatement here\n";
        return false;
    }
}
bool tyCheckIOStatement(TreeNode* stmt){
    TreeNode* format, * opd;
    format = stmt->child;
    opd = format->sibling;

    if(stmt->stype == STMT_SCANF){
        assert(opd != NULL);
    }

    if(!format->isConstStr()){
        cout << "scanf | printf parameter error" << endl;
        return false;
    }
    cout << "tyCheckIOStatement " << opd->nodeID << endl;
    return tyCheckExpression(opd);
}
bool tyCheckCompoundStatement(TreeNode* stmt){
    TreeNode* compound = stmt->child;
    //cout <<"compound "<< stmt->nodeID << endl;
    TreeNode* ch = compound->child;
    //return 0;
    while(ch){
        //cout << "compound's son " << ch->nodeID << endl;
        tyCheckStatement(ch);
        ch = ch->sibling;
    }
    //cout << "[compound]\n";
}

bool tyCheckForStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) && ((stmt->stype == STMT_FOR) || (stmt->stype == STMT_FOR_NONE)));
    CURRENTST.breakable.push_back(stmt);
    CURRENTST.loops.push_back(stmt);

    TreeNode* initexpr, *condexpr, *incexpr;
    initexpr = stmt->child;
    condexpr = initexpr->sibling;
    incexpr = condexpr->sibling;

    if(initexpr->nodeType == NODE_EXPR){
        cout << "initexpr "<< initexpr->nodeID << endl;
        tyCheckExpression(initexpr);
    }
    if(condexpr->nodeType == NODE_EXPR){
        tyCheckExpression(condexpr);
        tyAdjust(condexpr, 1);
        if(! IsScalarType(condexpr->sysType)){
            cout << stmt->lineno<< "error, tyCheckForStatement: The second expression in for statement shall be scalar type." << endl;
        }
    }
    if(incexpr->nodeType == NODE_EXPR){
        tyCheckExpression(incexpr);
    }
    TreeNode* lpstmt = incexpr->sibling;
    if(lpstmt){
        cout << "loop part " <<lpstmt->nodeID << endl;
        tyCheckStatement(lpstmt);
    }

    CURRENTST.loops.pop_back();
    CURRENTST.breakable.pop_back();

    return true;
}

bool tyCheckContinueStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) && (stmt->stype == STMT_CONTINUE));

    if (CURRENTST.loops.size() > 0){
        stmt->p_val = (void*)CURRENTST.loops.back();
    }else{
        cout << stmt->lineno<< "error, tyCheckContinueStatement: The continue should be in a loop." << endl;
        return false;
    }
    return true;
}
extern _FunctionType currentfty;
bool tyCheckReturnStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) && (stmt->stype == STMT_RETURN));
    assert(currentfty != NULL);
    _Type rty = currentfty->bty;    //get return type
    CURRENTST.has_return = true;
    TreeNode* ret = stmt->child;
    if(ret){
        tyCheckExpression(ret);
        tyAdjust(ret, 1);
        if(rty->categ == VOID){
            cout <<ret->lineno<< " tyCheckForStatement: Void function should not return value" << endl;
            return false;
        }

        if(!CanAssign(ret, rty)){
            cout << ret->lineno<< " tyCheckForStatement: Incompatible return value" << endl;
            return false;
        }

        Cast(ret, rty);
        //cout << "[return] check past\n";
        return true;
    } 

    if (rty->categ != VOID){
        cout << ret->lineno<<" Warning The function should return a value." << endl;
    }
    //cout << "[return] check past\n";
    return true;
}

bool tyCheckBreakStatement(TreeNode* stmt){
     assert((stmt->nodeType == NODE_STMT) && (stmt->stype == STMT_BREAK));

    if (CURRENTST.breakable.size() > 0){
        stmt->p_val = (void*)CURRENTST.breakable.back();
    }else{
        cout << stmt->lineno<< " error, tyCheckBreakStatement: The break should be in a loop." << endl;
        return false;
    }
    return true;
}

bool tyCheckLoopStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) && ((stmt->stype == STMT_WHILE || (stmt->stype == STMT_DO_WHILE))));
    CURRENTST.breakable.push_back(stmt);
    CURRENTST.loops.push_back(stmt);

    TreeNode* expr, *lpstmt;
    expr = stmt->child;
    lpstmt = expr->sibling;

    tyCheckExpression(expr);
    tyAdjust(expr, 1);
    if(!IsScalarType(expr->sysType)){
        cout << stmt->lineno << " error tyCheckLoopStatement: The expression in do or while statement shall be scalar type." << endl;
    }
    tyCheckStatement(lpstmt);

    CURRENTST.breakable.pop_back();
    CURRENTST.loops.pop_back();

    return true;
}

bool tyCheckSelectStatement(TreeNode* stmt){
    assert((stmt->nodeType == NODE_STMT) && (stmt->stype == STMT_SELECT));
    TreeNode* expr, *tstmt, *fstmt;
    expr = stmt->child;
    tstmt = expr->sibling;
    fstmt = tstmt->sibling;
    cout << "expr: "<< expr->nodeID << " t: " << tstmt->nodeID << " f: " << fstmt->nodeID << endl;
    tyCheckExpression(expr);
    tyAdjust(expr, 1);
    if(!IsScalarType(expr->sysType)){
        cout << stmt->lineno << " error tyCheckLoopStatement: The expression in if statement shall be scalar type." << endl;
    }

    tyCheckStatement(tstmt);
    if(fstmt != NULL){
        tyCheckStatement(fstmt);
    }

    return true;
}

bool tyCheckExpressionStatement(TreeNode* stmt){
    if(stmt->child){
        tyCheckExpression(stmt->child);
    }
    return true;
}
