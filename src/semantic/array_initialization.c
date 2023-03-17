
/**
 * @file
 *
 * This file contains the code for the ArrayInitialization traversal.
 * The traversal has the uid: AI
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"

void AIinit() { return; }
void AIfini() { return; }

node_st *AIlookup(node_st *symtbl, char *identifier)
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

char *generate_temp_name()
{
    static int counter = 1; // Keep track of the number of times the function is called
    const char *prefix = "temp_";
    size_t name_length = strlen(prefix) + 10; // Allocate enough space for the prefix, counter, and null terminator
    char *temp_name = (char *)malloc(name_length);

    if (temp_name == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    snprintf(temp_name, name_length, "%s%d", prefix, counter);
    counter++;

    return temp_name;
}

/**
 * @fn AIprogram
 */
node_st *AIprogram(node_st *node)
{
    // Set the current scope of the program's data to be the node being traversed
    struct data_ai *data = DATA_AI_GET();
    data->current_scope = node;

    // Traverse the children of the current node
    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = node;

    // Return the current node
    return node;
}

node_st *AIsymtbl_attachbefore(node_st *symtbl, node_st *ste, node_st *new_ste)
{
    node_st *entry = SYMTBL_HEAD(symtbl);
    node_st *previous = NULL;

    while (entry != NULL && STE_NAME(entry) != STE_NAME(ste))
    {
        previous = entry;
        entry = STE_NEXT(entry);
    }

    if (entry != NULL)
    {
        // The desired vardecl is found
        if (previous == NULL)
        {
            // The found declaration is the first one

            SYMTBL_HEAD(symtbl) = new_ste;

            STE_NEXT(new_ste) = ste;
        }
        else
        {

            STE_NEXT(previous) = new_ste;

            STE_NEXT(new_ste) = ste;
        }
    }
    else
    {
        // The desired vardecl was not found
        return NULL;
    }

    return NULL;
}

node_st *AIadd_before(node_st *funbody, node_st *before, node_st *new)
{

    node_st *entry = FUNBODY_DECLS(funbody);
    node_st *previous = NULL;

    while (entry != NULL && VARDECL_NAME(entry) != VARDECL_NAME(before))
    {
        previous = entry;
        entry = VARDECL_NEXT(entry);
    }

    if (entry != NULL)
    {
        // The desired vardecl is found
        if (previous == NULL)
        {

            VARDECL_NEXT(new) = before;

            FUNBODY_DECLS(funbody) = new;

            return new;
        }
        else
        {
            VARDECL_NEXT(previous) = new;

            VARDECL_NEXT(new) = entry;

            return new;
        }
    }
    return NULL;
}

void AIallocate(node_st *allocate, char *name)
{
    node_st *args = FUNCALL_ARGS(allocate);

    if (args == NULL)
    { // There are no arguments
        FUNCALL_ARGS(allocate) = ASTexprs(ASTvar(NULL, name), NULL);
    }

    if (args != NULL)
    {
        node_st *temp = FUNCALL_ARGS(allocate);

        while (EXPRS_NEXT(temp) != NULL)
        {
            temp = EXPRS_NEXT(temp);
        }

        EXPRS_NEXT(temp) = ASTexprs(ASTvar(NULL, name), NULL);
    }
}

/**
 * @fn AIfundef
 */
node_st *AIfundef(node_st *node)
{
    struct data_ai *data = DATA_AI_GET();

    node_st *outer = data->current_scope;

    if (FUNDEF_BODY(node) == NULL) // Check if this function actually has a body.
    {
        return node;
    }

    // Set this node as the current scope
    data->current_scope = node;

    // SYSTEMTIC TRAVERSAL

    node_st *declaration = FUNBODY_DECLS(FUNDEF_BODY(node));

    while (declaration != NULL)
    {
        if (VARDECL_DIMS(declaration) == NULL)
        { // Exit operation if var declaration has no dimension.
            declaration = VARDECL_NEXT(declaration);
            continue;
        }

        /**
         * PROCESS
         **/

        node_st *dimension = VARDECL_DIMS(declaration);

        node_st *allocate = ASTfuncall(NULL, "__allocate");

        while (dimension != NULL)
        {
            char *name = generate_temp_name();
            node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));

            AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, AIadd_before(FUNDEF_BODY(node), STE_DECL(lookup), ASTvardecl(NULL, EXPRS_EXPR(dimension), NULL, name, CT_int))));

            EXPRS_EXPR(dimension) = ASTvar(NULL, STRcpy(name));

            AIallocate(allocate, name);

            dimension = EXPRS_NEXT(dimension);
        }

        if (VARDECL_INIT(declaration) != NULL) // Right hand side
        {
            char *name = generate_temp_name();
            node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));

            AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, AIadd_before(FUNDEF_BODY(node), STE_DECL(lookup), ASTvardecl(NULL, VARDECL_INIT(declaration), NULL, name, CT_int))));
        }

        // Assign with an allocate function
        VARDECL_INIT(declaration) = CCNcopy(allocate);

        /**
         * END PROCESS
         **/

        declaration = VARDECL_NEXT(declaration);
    }

    // END

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

// while (dimension != NULL) // Left hand side
// {
//     char *name = generate_temp_name();
//     node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));
//     node_st *newnode = ASTvardecl(NULL, CCNcopy(EXPRS_EXPR(dimension)), NULL, name, CT_int);

//     new_vardecls = AIadd(new_vardecls, newnode);                                             // We add them to the function
//     AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, newnode)); // We add them to the symbol table

//     EXPRS_EXPR(dimension) = ASTvar(NULL, STRcpy(name));

//     dimension = EXPRS_NEXT(dimension);
// }

// if (VARDECL_INIT(declaration) != NULL) // Right hand side
// {
//     char *name = generate_temp_name();
//     node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));
//     node_st *newnode = ASTvardecl(NULL, CCNcopy(VARDECL_INIT(declaration)), NULL, name, CT_int);

//     new_vardecls = AIadd(new_vardecls, newnode);
//     AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, newnode)); // We add them to the symbol table

//     VARDECL_INIT(declaration) = ASTvar(NULL, STRcpy(name));
// }

// node_st *AIdims_to_vardecls(node_st *exprs)
// {
//     node_st *expression = exprs;
//     char *name = generate_temp_name();

//     node_st *vardecls = ASTvardecl(expression, NULL, NULL, name, CT_int);

//     expression = EXPRS_NEXT(expression);

//     while (expression != NULL)
//     {
//         node_st *old = CCNcopy(vardecls); // We copy the old row of vardecls
//         node_st *name = generate_temp_name();

//         vardecls = ASTvardecl(expression, NULL, old, name, CT_int); // We add them to the list

//         expression = EXPRS_NEXT(expression);
//     }

//     return vardecls;
// }

// node_st *AIexpr_to_vardecl(node_st *expr)
// {
//     node_st *expression = expr;
//     char *name = generate_temp_name();

//     node_st *vardecls = ASTvardecl(expression, NULL, NULL, name, CT_int);

//     return vardecls;
// }

// node_st *AIadd_to_stmts(node_st *stmts, node_st *new)
// {
//     if (stmts != NULL)
//     {
//         node_st *temp = stmts;

//         while (temp != NULL && STMTS_NEXT(temp) != NULL)
//         {
//             temp = STMTS_NEXT(temp);
//         }

//         STMTS_NEXT(temp) = new;

//         return stmts;
//     }
//     else
//     {
//         return new;
//     }
// }

// node_st *AIvardecls_tail(node_st *vardecls)
// {

//     node_st *vardecl = vardecls;

//     while (VARDECL_NEXT(vardecl) != NULL)
//     {
//         vardecl = VARDECL_NEXT(vardecl);
//     }

//     return vardecl;
// }

// node_st *AIste_tail(node_st *ste_list)
// {
//     node_st *ste = ste_list;

//     while (STE_NEXT(ste) != NULL)
//     {
//         ste = STE_NEXT(ste);
//     }

//     return ste;
// }

// void *AIrename_dims(node_st *exprs, node_st *vardecls)
// {
//     node_st *expressions = exprs;
//     node_st *declarations = vardecls;

//     while (expressions != NULL && declarations != NULL)
//     {
//         EXPRS_EXPR(expressions) = ASTvar(NULL, VARDECL_NAME(declarations));

//         expressions = EXPRS_NEXT(expressions);
//         declarations = VARDECL_NEXT(declarations);
//     }
// }

// void *AIrename_expr(node_st *expr, node_st *vardecl)
// {
//     node_st *expression = expr;
//     node_st *declaration = vardecl;

//     VARDECL_INIT(expression) = ASTvar(NULL, VARDECL_NAME(declaration));
// }

// node_st *AIvardecl_attach_head(node_st *vardecls, node_st *vardecl)
// {
//     VARDECL_NEXT(vardecl) = vardecls;

//     return vardecl;
// }

// void *AIvardecls_attachbefore(node_st *prevlist, node_st *find, node_st *newvardecls)
// {
//     node_st *entry = prevlist;
//     node_st *previous = NULL;

//     while (entry != NULL && VARDECL_NAME(entry) != VARDECL_NAME(find))
//     {
//         previous = entry;
//         entry = VARDECL_NEXT(entry);
//     }

//     if (entry != NULL)
//     {
//         // The desired vardecl is found
//         if (previous == NULL)
//         {
//             node_st *tail = AIvardecls_tail(newvardecls);

//             VARDECL_NEXT(tail) = find;
//         }
//         else
//         {
//             VARDECL_NEXT(entry) = newvardecls;

//             node_st *tail = AIvardecls_tail(newvardecls);

//             VARDECL_NEXT(tail) = find;
//         }
//     }
//     else
//     {
//         // The desired vardecl was not found
//         return NULL;
//     }
// }

// node_st *AIvardecls_to_ste(node_st *vardecls)
// {
//     node_st *declarations = vardecls;

//     node_st *ste = ASTste(NULL, VARDECL_NAME(declarations), VARDECL_TYPE(declarations), declarations);

//     declarations = VARDECL_NEXT(declarations);

//     while (declarations != NULL)
//     {
//         node_st *old = CCNcopy(ste); // We copy the old row of stes

//         ste = ASTste(old, VARDECL_NAME(declarations), VARDECL_TYPE(declarations), declarations); // We add them to the list

//         declarations = VARDECL_NEXT(declarations);
//     }

//     return ste;
// }

// node_st *AIcreateallocate(node_st *vardecls)
// {
// }
