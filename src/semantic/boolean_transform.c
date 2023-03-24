
/**
 * @file
 *
 * This file contains the code for the BooleanTransform traversal.
 * The traversal has the uid: BT
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

/**
 * @fn BTbinop
 */
node_st *BTbinop(node_st *node)
{
    TRAVchildren(node);

    if (BINOP_OP(node) == BO_and) // Boolean conjunction
    {
        node_st *ternary = ASTternary(BINOP_LEFT(node), BINOP_RIGHT(node), ASTbool(false));
        node = CCNcopy(ternary);
    }

    if (BINOP_OP(node) == BO_or) // Boolean disjunction
    {
        node_st *ternary = ASTternary(BINOP_LEFT(node), ASTbool(true), BINOP_RIGHT(node));
        node = CCNcopy(ternary);
    }

    return node;
}
