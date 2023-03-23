
/**
 * @file
 *
 * This file contains the code for the ParameterPassing traversal.
 * The traversal has the uid: PP
 */

#include <stdio.h>
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void PPinit() { return; }
void PPfini() { return; }

node_st *PPlookup(node_st *symtbl, char *identifier)
{
    // Check if the symbol table and identifier are not null
    if (symtbl == NULL || identifier == NULL)
    {
        return NULL;
    }

    // Traverse the symbol table hierarchy
    node_st *temp = symtbl;
    while (temp != NULL)
    {
        // Check if the identifier exists in the current symbol table
        node_st *entry = SYMTBL_HEAD(temp);
        while (entry != NULL)
        {
            if (STReq(STE_NAME(entry), identifier) == true)
            {
                return entry;
            }
            entry = STE_NEXT(entry);
        }

        // Move to the outer symbol table
        node_st *outer = SYMTBL_OUTER(temp);
        if (outer != NULL)
        {
            temp = outer;
            continue;
        }

        // No more outer symbol tables, exit the loop
        break;
    }

    // If the identifier is not found, return null
    return NULL;
}

node_st *PPadd_before_param(node_st *fundef, char *search, char *identifier)
{

    node_st *temp = FUNDEF_PARAMS(fundef);

    node_st *previous = NULL;
    node_st *current = NULL;
    node_st *new = ASTparam(NULL, NULL, identifier, CT_int);

    if (temp == NULL)
    {
        return NULL; // Empty parameter list, nothing to do
    }

    while (temp != NULL)
    {

        if (STReq(PARAM_NAME(temp), search))
        {
            // Found the desired parameter
            current = temp;
            break; // Exit the loop
        }

        previous = temp; // Update the previous node
        temp = PARAM_NEXT(temp);
    }

    if (previous == NULL)
    {
        // The first parameter is the one we're searching for
        // We need to add the new parameter as the first one
        PARAM_NEXT(new) = current;
        FUNDEF_PARAMS(fundef) = new;

        return FUNDEF_PARAMS(fundef);
    }
    else
    {
        // Add the new parameter between the previous and current nodes
        PARAM_NEXT(new) = current;
        PARAM_NEXT(previous) = new;

        return PARAM_NEXT(previous);
    }
}

/**
 * @fn PPprogram
 */
node_st *PPprogram(node_st *node)
{
    struct data_pp *data = DATA_PP_GET();

    data->current_scope = node;

    TRAVchildren(node);

    return node;
}

/**
 * @fn PPfundef
 */
node_st *PPfundef(node_st *node)
{

    struct data_pp *data = DATA_PP_GET();
    node_st *outer = data->current_scope;

    node_st *temp_param = FUNDEF_PARAMS(node);

    while (temp_param != NULL)
    {

        if (PARAM_DIMS(temp_param) != NULL)
        { // This parameter has dimensions
            node_st *temp_dim = PARAM_DIMS(temp_param);

            while (temp_dim != NULL)
            {
                node_st *ste = PPlookup(FUNDEF_SYMTBL(node), IDS_NAME(temp_dim));

                node_st *param = PPadd_before_param(node, STRcpy(PARAM_NAME(temp_param)), STRcpy(IDS_NAME(temp_dim)));

                // We link the ste with the actual parameter
                STE_DECL(ste) = param;

                temp_dim = IDS_NEXT(temp_dim);
            }
        }

        temp_param = PARAM_NEXT(temp_param);
    }

    data->current_scope = node;

    TRAVchildren(node);

    data->current_scope = outer;

    return node;
}

/**
 * @fn PPbool
 */
node_st *PPfuncall(node_st *node)
{

    struct data_pp *data = DATA_PP_GET();
    node_st *outer = data->current_scope;
    node_st *temp_arg = FUNCALL_ARGS(node);

    while (temp_arg != NULL)
    {

        if (NODE_TYPE(EXPRS_EXPR(temp_arg)) == NT_VAR)
        {
            node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), VAR_NAME(EXPRS_EXPR(temp_arg)));

            node_st *decl = STE_DECL(ste);

            if (NODE_TYPE(decl) == NT_PARAM)
            {
                printf("NT_PARAM\n");
            }

            if (NODE_TYPE(decl) == NT_GLOBDECL)
            {
                printf("NT_GLOBDECL\n");
            }

            if (NODE_TYPE(decl) == NT_VARDECL)
            {
                printf("NT_VARDECL\n");

                // Als het een var is dan koppelen we deze nieuwe argument met de STE.
            }

            if (NODE_TYPE(decl) == NT_GLOBDEF)
            {
                printf("NT_GLOBDEF\n");

                // Als het een var is dan koppelen we deze nieuwe argument met de STE.
            }
        }

        temp_arg = EXPRS_NEXT(temp_arg);
    }

    TRAVchildren(node);

    return node;
}

// if (PARAM_DIMS(decl) != NULL)
//                 { // This argument has dimensions
//                     node_st *temp_dim = PARAM_DIMS(decl);

//                     while (temp_dim != NULL)
//                     {
//                         node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), IDS_NAME(temp_dim));

//                         // // We link the ste with the actual parameter
//                         node_st *new = PPadd_before_arg(node, temp_arg, CCNcopy(ASTexprs(ASTvar(NULL, IDS_NAME(temp_dim)), NULL)));

//                         VAR_ENTRY(EXPRS_EXPR(new)) = ste;

//                         temp_dim = IDS_NEXT(temp_dim);
//                     }
//                 }

//  struct data_pp *data = DATA_PP_GET();
//     node_st *outer = data->current_scope;

//     // Look up function declaration

//     node_st *temp_arg = FUNCALL_ARGS(node);

//     while (temp_arg != NULL)
//     {

//         if (NODE_TYPE(EXPRS_EXPR(temp_arg)) == NT_VAR)
//         {
//             node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), VAR_NAME(EXPRS_EXPR(temp_arg)));

//             node_st *decl = STE_DECL(ste);

//             if (NODE_TYPE(decl) == NT_PARAM)
//             {
//                 if (PARAM_DIMS(decl) != NULL)
//                 { // This argument has dimensions
//                     node_st *temp_dim = PARAM_DIMS(decl);

//                     while (temp_dim != NULL)
//                     {
//                         node_st *ste = PPlookup(FUNDEF_SYMTBL(outer), IDS_NAME(temp_dim));

//                         // // We link the ste with the actual parameter
//                         node_st *new = PPadd_before_arg(node, temp_arg, CCNcopy(ASTexprs(ASTvar(NULL, IDS_NAME(temp_dim)), NULL)));

//                         VAR_ENTRY(EXPRS_EXPR(new)) = ste;

//                         temp_dim = IDS_NEXT(temp_dim);
//                     }
//                 }
//             }
//         }

//         temp_arg = EXPRS_NEXT(temp_arg);
//     }

//     // Look up variable declaration

//  node_st *temp_param = FUNDEF_PARAMS(node);

//     while (temp_param != NULL)
//     {

//         if (PARAM_DIMS(temp_param) != NULL)
//         { // This parameter has dimensions
//             node_st *temp_dim = PARAM_DIMS(temp_param);

//             while (temp_dim != NULL)
//             {
//                 node_st *ste = PPlookup(FUNDEF_SYMTBL(node), IDS_NAME(temp_dim));

//                 node_st *new = PPadd_before_param(node, temp_param, CCNcopy(ASTparam(NULL, NULL, IDS_NAME(temp_dim), CT_int)));

//                 // // We link the ste with the actual parameter
//                 // STE_DECL(ste) = new;

//                 temp_dim = IDS_NEXT(temp_dim);
//             }
//         }

//         temp_param = PARAM_NEXT(temp_param);
//     }

// node_st *PPadd_before_arg(node_st *funcall, node_st *before, node_st *new)
// {
//     node_st *entry = FUNCALL_ARGS(funcall);
//     node_st *previous = NULL;

//     while (entry != NULL)
//     {

//         if (VAR_NAME(EXPRS_EXPR(entry)) == VAR_NAME(EXPRS_EXPR(before)))
//         {
//             printf("FOUND");
//             break;
//         }

//         previous = entry;
//         entry = EXPRS_NEXT(entry);
//     }

//     if (entry != NULL)
//     {
//         // The desired vardecl is found
//         if (previous == NULL)
//         {
//             EXPRS_NEXT(new) = before;
//             FUNCALL_ARGS(funcall) = new;
//             return new;
//         }
//         else
//         {
//             EXPRS_NEXT(previous) = new;
//             EXPRS_NEXT(new) = entry;
//             return new;
//         }
//     }
//     return NULL;
// }