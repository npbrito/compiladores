/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "misc.h"

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