/**
 * @file
 *
 * This file contains the code for the LamdaLifting traversal.
 * The traversal has the uid: LL
 *
 *
 */

#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"

void LLinit() { return; }
void LLfini() { return; }

/**
 * @fn LLfundef
 */
node_st *LLfundef(node_st *node)
{
    TRAVchildren(node);

    return node;
}
