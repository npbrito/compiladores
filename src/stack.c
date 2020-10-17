/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

StackNode *create_stack(HashTable** new_data){
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode)); 
    stackNode->symbol_table = *new_data; 
    stackNode->next = NULL; 
    return stackNode; 
}

int isEmpty(StackNode* root) 
{ 
    return !root; 
} 

void push(StackNode** root, HashTable * data){
    StackNode* topNode = create_stack(&data);
    // Empurra a raiz pra baixo do novo elemento da pilha
    topNode->next = *root;
    *root = topNode;
}

HashTable* pop(StackNode** root){
    if (isEmpty(*root)) 
        return NULL; 
    StackNode* temp = *root; 
    *root = (*root)->next; 
    HashTable* popped = temp->symbol_table; 
    free(temp); 
    return popped; 
}

HashTable* top(StackNode* root){
    return root->symbol_table; 
}

