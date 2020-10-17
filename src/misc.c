/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "misc.h"
#include "list.h"

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
    // Adcionando os parametros na lista da função
    fun->function_param = (parameter*)calloc(args_cont, sizeof(parameter));
   int i = 0;
    while(!isEmpty_stack_list(aux) && i < args_cont){
    param = pop_element(&aux);
    fun->function_param[i].name = param->name;
    fun->function_param[i].type= param->type;
    
    i++;
    }
    *stored_fun = fun;
}