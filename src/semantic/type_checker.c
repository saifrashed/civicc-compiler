/**
 * @file
 *
 * This file contains the code for the Typechecker traversal.
 * The traversal has the uid: TC
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"

void TCinit() { return; }
void TCfini() { return; }

/**
 * @fn TCassign
 */
node_st *TCassign(node_st *node)
{

    // Traverse Varlet and infer type

    // Traverse expression and infer type

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCwhile(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfundef
 */
node_st *TCdowhile(node_st *node)
{

    // Traverse cond and infer type
    // Must match bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    // INDUCTION VARIABEL IS REMOVED

    // Traverse stop and infer type
    // Must match num

    // Traverse step and infer type
    // Must match num

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCreturn
 */
node_st *TCreturn(node_st *node)
{
    // Traverse expressison

    // Infer type

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCcast
 */
node_st *TCcast(node_st *node)
{

    // We infer the type based on the type being cast. Bool, Int and Float are compatible with eachother.

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfuncall
 */
node_st *TCfuncall(node_st *node)
{

    // We find the function definition node.

    // Iterate through each argument and parameter pair, and compare their types.
    // If any pair has different types, then the types don't match and we sent an error.

    // If successfull we infer type of FUNDEF_TYPE(STE_DECL(FUNCALL_ENTRY(node)))

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvar(node_st *node)
{

    // We infer type of VARDECL_TYPE(STE_DECL(VAR_ENTRY(node)))

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCvar
 */
node_st *TCvarlet(node_st *node)
{

    // We infer type of VARDECL_TYPE(STE_DECL(VAR_ENTRY(node)))

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCarrexpr
 */
node_st *TCarrexpr(node_st *node)
{
    // We save the type of first element

    // Loop through all expressions.

    // We infer type num or float if all expressions are one of two.

    // We sent error if any other expressions mistmatches on type

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCbinop
 */
node_st *TCbinop(node_st *node)
{

    // Traverse left

    // Get inferred type

    // Traverse right

    // Get inferred type

    // We infer type num if both sides are num

    // We infer type float if both sides are float

    // Else we sent error

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCmonop
 */
node_st *TCmonop(node_st *node)
{
    // Traverse operand

    // Get inferred type

    // We infer the type bool when negation with bool.

    // We infer the type num or float when unary minus with num or float

    // Else we sent error

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCfloat
 */
node_st *TCfloat(node_st *node)
{
    // We infer the type CT_float

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCbool
 */
node_st *TCbool(node_st *node)
{

    // We infer the type CT_bool

    TRAVchildren(node);

    return node;
}

/**
 * @fn TCnum
 */
node_st *TCnum(node_st *node)
{

    // We infer the type CT_num

    TRAVchildren(node);

    return node;
}

// /**
//  * Returns the type as a character.
//  **/
// char *get_type(node_st *expr, node_st *symtbl)
// {
//     // If type is constant
//     // If type is var (look up in table)
//     // If type is binop
//     // if expression has dimensions it an array of certain type

//     char *type = NULL;
//     switch (NODE_TYPE(expr))
//     {
//     case NT_NUM:
//         type = "int";
//         break;
//     case NT_FLOAT:
//         type = "float";
//         break;
//     case NT_BOOL:
//         type = "bool";
//         break;
//     case NT_VAR:
//         switch (STE_TYPE(NBlookup(symtbl, VAR_NAME(expr))))
//         {
//         case CT_bool:
//             type = "bool";
//             break;
//         case CT_float:
//             type = "float";
//             break;
//         case CT_int:
//             type = "int";
//             break;
//         }
//         break;
//     }
//     return type;
// }
