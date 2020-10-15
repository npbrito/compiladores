/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "stack.h"

int main(int argc, char **argv){
   
   // HASH TABLE USAGE
    HashTable* table;
   
    table = hash_create();
    
    hash_element* fisrt = (hash_element*)malloc(sizeof(hash_element));
    fisrt->line = 1;
    fisrt->type = 261;
    fisrt->name = "firstVar";
    fisrt->nature = 0;

    if(!hash_search(table, fisrt->name))
    hash_insert(&table, fisrt);

    // STACK USAGE
    StackNode* root = create_stack(&table);
    
    table = hash_create();

    push(&root, table);

    hash_print(top(root));

    pop(&root);

    hash_print(top(root));
    
    return 0; 
}