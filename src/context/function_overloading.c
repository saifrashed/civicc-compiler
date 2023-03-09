/**
 * @file
 *
 * This file contains the code for the FunctionOverloading traversal.
 * The traversal has the uid: FO
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

void FOinit() { return; }
void FOfini() { return; }

/**
 * @fn FOfundef
 */
node_st *FOfundef(node_st *node)
{

    TRAVchildren(node);

    return node;
}
