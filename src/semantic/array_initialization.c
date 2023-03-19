
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

node_st *find_last_for_loop(node_st *forloop)
{
    node_st *temp = forloop;
    while (FOR_BLOCK(temp) != NULL)
    {
        temp = STMTS_STMT(FOR_BLOCK(temp));
    }
    return temp;
}

void AIforloop(node_st *forloop, char *name)
{
    if (FOR_VAR(forloop) == NULL && FOR_START_EXPR(forloop) == NULL && FOR_STOP(forloop) == NULL)
    { // If initial for loop has to be configed.
        FOR_VAR(forloop) = generate_temp_name();
        FOR_START_EXPR(forloop) = ASTnum(0);
        FOR_STOP(forloop) = ASTvar(NULL, name);
    }
    else
    { // We create a new for loop and add in inside.
        node_st *last_for_loop = find_last_for_loop(forloop);
        FOR_BLOCK(last_for_loop) = ASTstmts(ASTfor(ASTnum(0), ASTvar(NULL, name), NULL, NULL, generate_temp_name()), NULL);
    }
}
node_st *append_var(node_st *list, char *var)
{
    if (list == NULL)
    {
        return ASTexprs(ASTvar(NULL, var), NULL);
    }
    else
    {
        node_st *temp = list;
        while (EXPRS_NEXT(temp) != NULL)
        {
            temp = EXPRS_NEXT(temp);
        }
        EXPRS_NEXT(temp) = ASTexprs(ASTvar(NULL, var), NULL);
        return list;
    }
}

node_st *AIforloop_indices(node_st *forloop)
{
    node_st *temp = forloop;
    node_st *indices = NULL;

    while (FOR_BLOCK(temp) != NULL)
    {
        char *induc = STRcpy(FOR_VAR(temp));
        indices = append_var(indices, induc);
        temp = STMTS_STMT(FOR_BLOCK(temp));
    }

    char *induc = STRcpy(FOR_VAR(temp));
    indices = append_var(indices, induc);

    return indices;
}

void AIforloop_assignment(node_st *forloop, char *var, char *exprs)
{

    if (FOR_BLOCK(forloop) != NULL)
    {
        node_st *temp = forloop;

        while (FOR_BLOCK(temp) != NULL)
        {
            temp = STMTS_STMT(FOR_BLOCK(temp));
        }

        FOR_BLOCK(temp) = ASTstmts(ASTassign(ASTvarlet(AIforloop_indices(forloop), var), ASTvar(NULL, exprs)), NULL);
    }
    else
    {
        FOR_BLOCK(forloop) = ASTstmts(ASTassign(ASTvarlet(AIforloop_indices(forloop), var), ASTvar(NULL, exprs)), NULL);
    }
}

void AIarrexpr_to_assignment(char *var, node_st *fundef, node_st *arrexpr, int level, int *indices)
{
    if (!arrexpr)
        return;

    node_st *temp = ARREXPR_EXPRS(arrexpr);
    int index = 0;

    while (temp != NULL)
    {
        if (NODE_TYPE(EXPRS_EXPR(temp)) == NT_ARREXPR) // Recursively process nested array expressions
        {
            indices[level] = index;
            AIarrexpr_to_assignment(var, fundef, EXPRS_EXPR(temp), level + 1, indices);
            index++;
        }

        if (NODE_TYPE(EXPRS_EXPR(temp)) == NT_FLOAT)
        {
            indices[level] = index;

            node_st *exprs = NULL;

            for (int i = 0; i <= level; i++)
            {
                if (exprs == NULL)
                {
                    exprs = ASTexprs(ASTnum(indices[i]), NULL);
                }
                else
                {
                    exprs = ASTexprs(ASTnum(indices[i]), exprs);
                }
            }

            FUNBODY_STMTS(FUNDEF_BODY(fundef)) = ASTstmts(ASTassign(ASTvarlet(exprs, STRcpy(var)), EXPRS_EXPR(temp)), FUNBODY_STMTS(FUNDEF_BODY(fundef)));

            index++;
        }

        if (NODE_TYPE(EXPRS_EXPR(temp)) == NT_NUM)
        {
            indices[level] = index;

            node_st *exprs = NULL;

            for (int i = 0; i <= level; i++)
            {
                if (exprs == NULL)
                {
                    exprs = ASTexprs(ASTnum(indices[i]), NULL);
                }
                else
                {
                    exprs = ASTexprs(ASTnum(indices[i]), exprs);
                }
            }

            FUNBODY_STMTS(FUNDEF_BODY(fundef)) = ASTstmts(ASTassign(ASTvarlet(exprs, STRcpy(var)), EXPRS_EXPR(temp)), FUNBODY_STMTS(FUNDEF_BODY(fundef)));

            index++;
        }

        temp = EXPRS_NEXT(temp);
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

        node_st *allocate = ASTfuncall(NULL, "__allocate");      // To build the allocate function
        node_st *forloop = ASTfor(NULL, NULL, NULL, NULL, NULL); // To build the forloop statement

        while (dimension != NULL)
        {
            char *name = generate_temp_name();
            node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));

            AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, AIadd_before(FUNDEF_BODY(node), STE_DECL(lookup), ASTvardecl(NULL, EXPRS_EXPR(dimension), NULL, name, CT_int))));

            EXPRS_EXPR(dimension) = ASTvar(NULL, STRcpy(name));

            AIallocate(allocate, name);
            AIforloop(forloop, name);

            dimension = EXPRS_NEXT(dimension);
        }

        if (VARDECL_INIT(declaration) != NULL) // Right hand side
        {
            if (NODE_TYPE(VARDECL_INIT(declaration)) != NT_ARREXPR) // If we want to apply nested for loop assignment
            {
                char *name = generate_temp_name();
                node_st *lookup = AIlookup(FUNDEF_SYMTBL(node), VARDECL_NAME(declaration));

                AIsymtbl_attachbefore(FUNDEF_SYMTBL(node), lookup, ASTste(NULL, name, CT_int, AIadd_before(FUNDEF_BODY(node), STE_DECL(lookup), ASTvardecl(NULL, VARDECL_INIT(declaration), NULL, name, CT_int))));

                AIforloop_assignment(forloop, VARDECL_NAME(declaration), name);

                // Add for loop to statement
                FUNBODY_STMTS(FUNDEF_BODY(node)) = ASTstmts(forloop, FUNBODY_STMTS(FUNDEF_BODY(node)));
            }

            if (NODE_TYPE(VARDECL_INIT(declaration)) == NT_ARREXPR) // If we want to apply scalar assignment.
            {
                // Array expression to set of assignments

                int indices[10]; // Replace MAX_DIMENSIONS with the maximum number of dimensions you expect
                AIarrexpr_to_assignment(VARDECL_NAME(declaration), node, VARDECL_INIT(declaration), 0, indices);
            }
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
