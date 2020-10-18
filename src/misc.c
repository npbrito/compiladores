/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "misc.h"
#include "list.h"
#include "hash.h"

void store_identificador(hash_element** id_stored, lexeme_t* id){
    hash_element* aux = (hash_element*)malloc(sizeof(hash_element));
    aux->name = id->name;
    aux->line = id->line;
    aux->type = id-> type;
    aux->val = id->val;

    *id_stored = aux;
}

void store_nature(hash_element** id_stored, int nature){
        hash_element* aux = *id_stored;
        aux->nature = nature;
        *id_stored = aux;
}

void store_vet_size(hash_element** id_stored, int size){
        hash_element* aux = *id_stored;
        aux->vet_size = size;
        *id_stored = aux;
}

void store_function_elem(hash_element** fun_stored){
    hash_element* aux = (hash_element*)malloc(sizeof(hash_element));
    aux = *fun_stored;
    aux->nature = NAT_FUN;

    // Parametros
    *fun_stored = aux;
}

void store_param(hash_element** stored_fun, ElementList* param_list){
    ElementList * aux = NULL;
    hash_element* fun = *stored_fun;
    hash_element* param;
    parameter * param_aux = (parameter*)malloc(sizeof(parameter));
    int args_cont = 0;
    // Salvando os parâmetros e contando
    while(!isEmpty_stack_list(param_list)){
    push_element(&aux, pop_element(&param_list)); 
    args_cont++;
    }    
    fun->function_args = args_cont;
    /*if(top_e->name == NULL){
    fprintf(stderr, "param list = NULL \n");}*/
    if (args_cont > 0){
    // Adcionando os parametros na lista da função
    fun->function_param = (parameter*)calloc(args_cont, sizeof(parameter));
    int i = 0;
    while(!isEmpty_stack_list(aux) && i < args_cont){
    param = pop_element(&aux);
    fun->function_param[i].name = param->name;
    fun->function_param[i].type= param->type;
    i++;
    }}
    *stored_fun = fun;
}

int id_nature(StackNode* stack, char* name){
    HashTable * table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while(table[index].value != NULL && elements_searched < HASH_SIZE){
        if(strcmp(name, table[index].value->name) == 0)
            return table[index].value->nature;
        if(index < HASH_SIZE){
            index++;
        }
        else
        {
            index = 0;
        }
            elements_searched++;        
   }
   // depois procura no escopo local 
   table = top(stack);
     elements_searched = 0;
    while(table[index].value != NULL && elements_searched < HASH_SIZE){
        if(strcmp(name, table[index].value->name) == 0)
            return table[index].value->nature ;
        if(index < HASH_SIZE){
            index++;
        }
        else
        {
            index = 0;
        }
            elements_searched++;        
   }
}


int get_decl_args(StackNode * stack, char* name){
    HashTable * table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while(table[index].value != NULL && elements_searched < HASH_SIZE){
        if(strcmp(name, table[index].value->name) == 0)
            return table[index].value->function_args ;
        if(index < HASH_SIZE){
            index++;
        }
        else
        {
            index = 0;
        }
            elements_searched++;    
        fprintf(stderr, " %d \n\n",elements_searched);
    
   }
}

int cont_call_args(node_t* list, int *args){
    if (list == NULL){
    return 0; 
    }
    else
    {    
    for (int i=0; i<MAX_CHILDREN; i++) {
    node_t *child = list->children[i];
    cont_call_args(child, args);
    }
    *args+=1;
    }
}