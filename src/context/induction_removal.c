/**
 * @file
 *
 * This file contains the code for the InductionRemoval traversal.
 * The traversal has the uid: IR
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

void IRinit() { return; }
void IRfini() { return; }

/**
 * @fn IRfor
 */
node_st *IRfundef(node_st *node)
{
    TRAVchildren(node);

    return node;
}

/**
 * @fn IRfor
 */
node_st *IRfor(node_st *node)
{
    // struct data_st *data = DATA_ST_GET();

    // node_st *outer = data->current_scope; // we get the current scope.

    // char *name = FOR_VAR(node);
    // node_st *value = FOR_START_EXPR(node);

    // if (name != NULL && value != NULL) // If the forloop induction variable is still present.
    // {

    //     node_st *newDecl = ASTvardecl(NULL, value, NULL, name, CT_int);

    //     node_st *tail = FUNBODY_DECLS(FUNDEF_BODY(outer));

    //     if (tail != NULL) // There are already variable declarations present.
    //     {
    //         while (VARDECL_NEXT(tail))
    //         {
    //             tail = VARDECL_NEXT(tail);
    //         }

    //         VARDECL_NEXT(tail) = newDecl;
    //     }

    //     if (tail == NULL) // There are no variable declarations present.
    //     {
    //         FUNBODY_DECLS(FUNDEF_BODY(outer)) = newDecl;
    //     }

    //     FOR_START_EXPR(node) = NULL;
    //     FOR_VAR(node) = NULL;

    //     TRAVchildren()
    // }

    // printf("STfor %s\n", name);

    TRAVchildren(node);

    return node;
}
