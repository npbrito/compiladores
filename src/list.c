/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list.h"



// Stack to create lists of variables
ElementList *create_stack_list(hash_element** new_element){
    ElementList* stackNode = (ElementList*)malloc(sizeof(ElementList)); 
    stackNode->element = *new_element; 
    stackNode->next = NULL; 
    return stackNode; 
}

int isEmpty_stack_list(ElementList* root) 
{ 
    return !root; 
} 

void push_element(ElementList** root, hash_element* data){
    ElementList* topNode = create_stack_list(&data);
    // Empurra a raiz pra baixo do novo elemento da pilha
    topNode->next = *root;
    *root = topNode;
}

hash_element * pop_element(ElementList** root){
    if (isEmpty_stack_list(*root)) 
        return NULL; 
    ElementList* temp = *root; 
    *root = (*root)->next; 
    hash_element* popped = temp->element; 
    free(temp); 
    return popped; 
}