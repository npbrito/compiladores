/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

#ifndef LIST_H_
#define LSIT_H_

#include "hash.h"

/* The stacks will represent the different scopes.
 * Each element of the stack will be a hash table that represents the
 * symbol table. */
typedef struct ElementList { 
    hash_element* element; 
    struct ElementList* next; 
} ElementList; 

/* Initialize a stack */
ElementList *create_stack_list(hash_element**);

/* Check if the stack is empty */
int isEmpty_stack_list( ElementList*);

/* Add an item to the stack */
void push_element(ElementList**, hash_element*);

/* Removes the item from the top of the stack */
hash_element* pop_element(ElementList**);

/* Returns the element at the top of the stack */
hash_element* top_element(ElementList*);

#endif //LIST_H_