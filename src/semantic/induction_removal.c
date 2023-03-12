/**
 * @file
 *
 * This file contains the code for the InductionRemoval traversal.
 * The traversal has the uid: IR
 */

#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h>
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "ccngen/trav.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include <time.h>

void IRinit() { return; }
void IRfini() { return; }

/**
 * Adds a new symbol table entry (STE) to the specified symbol table.
 * The new STE contains information about an identifier, including its type and associated AST node.
 *
 * @param symtbl A pointer to the symbol table to add the new STE to.
 * @param identifier A string containing the identifier for the new STE.
 * @param type The type of the new STE.
 * @param link A pointer to the AST node associated with the new STE.
 *
 * @return A pointer to the new STE node if storing succeeds, or NULL if storing fails.
 **/
node_st *IRstore(node_st *symtbl, char *identifier, enum Type type, node_st *link)
{
    if (!symtbl || !identifier || !link)
    { // check for null pointers
        return NULL;
    }

    node_st *tail = SYMTBL_HEAD(symtbl);
    if (tail)
    { // if the symbol table already has entries, find the tail
        while (STE_NEXT(tail))
        {
            tail = STE_NEXT(tail);
        }
    }
    else
    { // otherwise, set the head
        SYMTBL_HEAD(symtbl) = ASTste(NULL, identifier, type, link);
        return symtbl;
    }

    STE_NEXT(tail) = ASTste(NULL, identifier, type, link); // add new entry to the tail
    return symtbl;
}

/**
 * Generates a random suffix of the specified size.
 * The probability of a collision with an existing suffix is approximately 5.5*10^-15 or 0.000000000000055%.
 *
 * @param size The size of the suffix to generate.
 *
 * @return A pointer to a string containing the random suffix.
 **/
char *IRrandsuffix(size_t size)
{
    char *newstr = malloc(size + 11); // Allocate memory for the new string
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
    if (newstr)
    {
        newstr[0] = '_'; // Set the first character to '_'

        for (size_t n = 1; n < size + 10; n++)
        {
            int key = rand() % (int)(sizeof charset - 1);
            newstr[n] = charset[key];
        }
        newstr[size + 10] = '\0';
    }
    return newstr;
}

/**
 * @fn IRprogram
 */
node_st *IRprogram(node_st *node)
{
    struct data_ir *data = DATA_IR_GET();

    data->current_scope = node;

    TRAVchildren(node);

    return node;
}

/**
 * @fn IRfundef
 */
node_st *IRfundef(node_st *node)
{
    struct data_ir *data = DATA_IR_GET();

    node_st *outer = data->current_scope;

    // Set this node as the current scope
    data->current_scope = node;

    TRAVchildren(node);

    // Reset the parent node as the current scope
    data->current_scope = outer;

    return node;
}

/**
 * @fn IRfor
 */
node_st *IRfor(node_st *node)
{

    TRAVchildren(node); // First traverse inner loops

    if (FOR_START_EXPR(node) != NULL) // If the for variable has not been removed we start the proces for removal.
    {

        // Get current scope
        struct data_ir *data = DATA_IR_GET();

        printf("IRfor \n");

        node_st *outer_scope = data->current_scope;

        // Generate unique suffix for variable name
        char *suffix = IRrandsuffix(10);

        // Create variable declaration for induction variable, if present
        char *name = FOR_VAR(node);
        node_st *value = FOR_START_EXPR(node);
        if (name != NULL && value != NULL)
        {
            // Create new vardecl node for induction variable
            char *new_name = STRcat(name, suffix);
            node_st *new_decl = ASTvardecl(NULL, value, NULL, new_name, CT_int);

            // Add new declaration to end of variable declarations in outer function body
            node_st *tail = FUNBODY_DECLS(FUNDEF_BODY(outer_scope));
            if (tail != NULL)
            {
                while (VARDECL_NEXT(tail))
                {
                    tail = VARDECL_NEXT(tail);
                }
                VARDECL_NEXT(tail) = new_decl;
            }
            else
            {
                FUNBODY_DECLS(FUNDEF_BODY(outer_scope)) = new_decl;
            }

            // Store new declaration in symbol table for outer function
            IRstore(FUNDEF_SYMTBL(outer_scope), new_name, VARDECL_TYPE(new_decl), new_decl);
        }

        // Set search and suffix members of data_ir to appropriate values
        data->search = FOR_VAR(node);
        data->suffix = suffix;

        // Traverse children of input node
        TRAVchildren(node);

        // Remove start expression and induction variable from input node
        FOR_START_EXPR(node) = NULL;
        FOR_VAR(node) = NULL;

        // Reset search and suffix members of data_ir
        data->search = NULL;
        data->suffix = NULL;
    }

    return node;
}

/**
 * @fn IRvarlet
 */
node_st *IRvarlet(node_st *node)
{
    // Get current search and replace information
    struct data_ir *data = DATA_IR_GET();

    // If identifier matches current induction variable, add suffix to identifier name

    if (STReq(VARLET_NAME(node), data->search))
    {
        char *new_name = STRcat(VARLET_NAME(node), data->suffix);
        VARLET_NAME(node) = new_name;
    }

    // Traverse children of input node
    TRAVchildren(node);

    return node;
}

/**
 * @fn IRvar
 */
node_st *IRvar(node_st *node)
{
    // Get current search and replace information
    struct data_ir *data = DATA_IR_GET();

    // If identifier matches current induction variable, add suffix to identifier name
    if (STReq(VAR_NAME(node), data->search))
    {
        char *new_name = STRcat(VAR_NAME(node), data->suffix);
        VAR_NAME(node) = new_name;
    }

    // Traverse children of input node
    TRAVchildren(node);

    return node;
}
