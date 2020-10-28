/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "element_stack.h"
#include "hash.h"

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
hash_element* top_element(ElementList* root){
    return root->element; 
}

void push_param(ElementList** root, hash_element* data, int type){
    ElementList* topNode = create_stack_list(&data);
    // Empurra a raiz pra baixo do novo elemento da pilha
    topNode->element->type = type;
    topNode->element->type_size = calc_type_size(type);

    topNode->next = *root;
    *root = topNode;
}

void push_exp(ElementList** root, hash_element* data){
    ElementList* topNode = create_stack_list(&data);

    // Empurra a raiz pra baixo do novo elemento da pilha
    topNode->next = *root;
    *root = topNode;
}

ElementList* reverse_list(ElementList *list){
    ElementList* aux = NULL;    
     while(!isEmpty_stack_list(list)){
         push_element(&aux, pop_element(&list));
     }
    return aux;   
}