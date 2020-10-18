/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#ifndef HASH_H_
#define HASH_H_

#include "tree.h"

// Hash table size 
#define HASH_SIZE 10

typedef struct parameter
{
    char* name;
    int type;
} parameter;

// Store the values of the hash table elements
typedef struct hash_element{
    // Non-function
    char* name;
    int line;
    int nature;
    int type;
    int type_size;
    int vet_size;
    union Literal val;
    // For functions
    int function_args;
    parameter* function_param;

} hash_element;

// A table that contains: a key and an element
typedef struct HashTable{
    int key;
    int occuped;
    hash_element * value;

} HashTable;

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

/* Returns the element at the bottom of the stack */
HashTable* bottom(StackNode*);

/* Create a empty hash table */
HashTable* hash_create();

void hash_insert(HashTable**, hash_element*, int type);

/* Search if element exist in a table */
int hash_search(StackNode*, char*);

/* Print a entire hash table */
void hash_print(HashTable*);

/* Calculates a insertion location */
int calc_index(char*);

/* Return the sizeof of that type */
int calc_type_size(int);

char * get_lit_name(hash_element *newElement);


#endif // HASH_H_