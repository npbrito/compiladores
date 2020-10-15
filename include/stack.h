/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

#ifndef STACK_H_
#define STACK_H_

#include "hash.h"

/* The stacks will represent the different scopes.
 * Each element of the stack will be a hash table that represents the
 * symbol table. */
typedef struct StackNode { 
    HashTable* symbol_table; 
    struct StackNode* next; 
} StackNode; 

/* Initialize a stack */
StackNode *create_stack(HashTable**);

/* Check if the stack is empty */
int isEmpty( StackNode*);

/* Add an item to the stack */
void push(StackNode**, HashTable*);

/* Removes the item from the top of the stack */
HashTable* pop(StackNode**);

/* Returns the element at the top of the stack */
HashTable* top(StackNode*);

#endif //STACK_H_