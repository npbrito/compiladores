/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"
#include "parser.tab.h"

int stored_nature = 0;

HashTable* hash_create(){
    HashTable* table = (HashTable*)calloc(HASH_SIZE, sizeof(HashTable));
    if (!table) {
        puts("Unable to allocate memory");
        exit(1);
    }
    // Initialize INDEXES
    for(int i = 0; i < HASH_SIZE; i++){
        table[i].key = -1;
    }
    table[0].occuped = 0;
    return table;
}

void hash_insert(HashTable** root, hash_element* newElement, int type){
    HashTable* table = *root;
    // Check if table is full
    if(table->occuped < HASH_SIZE){
    int index = 1;
    char* varname = newElement->name;

    table->occuped++;
    
    index = calc_index(varname);
    
    while (table[index].value != NULL)
    {
        index++;
    }
    table[index].key = index;
    
    table[index].value = newElement;
    table[index].value->type = type;
    table[index].value->type_size = calc_type_size(type);

    *root = table;
    }
    else{
        fprintf(stderr,"Insufficient memory to allocate '%s'\n", newElement->name);
    }
}

int hash_search(HashTable* table, char* name){
   int index = calc_index(name);
   int elements_searched = 0;
   while(table[index].value != NULL && elements_searched < HASH_SIZE){
        if(strcmp(name, table[index].value->name) == 0)
            return 1 ;
        if(index < HASH_SIZE){
            index++;
        }
        else
        {
            index = 0;
        }
            elements_searched++;        
   }
    return 0; 
}

void hash_print(HashTable* table){
    int i;
    fprintf(stderr,"\n=========================================================================================\n");
    for(i=0; i<HASH_SIZE; i++){
        if(table[i].key >=0 ){
            fprintf(stderr, "[%d]\t| NAME %s \t",table[i].key, table[i].value->name);
            fprintf(stderr, "| LOCATION %d \t| NATURE %d\t",table[i].value->line, table[i].value->nature);
            fprintf(stderr, "| TYPE %d \t | TYPE SIZE %d \t\n",table[i].value->type, table[i].value->type_size);
        }
        else{
        fprintf(stderr, "[%d]\t| EMPTY \n", i);   
        }
    
    }
	fprintf(stderr,"=========================================================================================\n");    
        
}

int calc_index(char str[]){
    /* Calculation method of:
     * https://cp-algorithms.com/string/string-hashing.html */
    int hash_index = 1;
    int p_pow = 1;
    int count;
    for(count = 0; count < strlen(str); count++){
        hash_index = (hash_index + (str[count] - 'a' + 1) * p_pow) % HASH_SIZE;
        p_pow = (p_pow * 31) % HASH_SIZE;
    }
    return (hash_index - 1 < 0)? 0 : hash_index - 1;
}

int calc_type_size(int type){
    int size = 0;
    switch (type)
    {
    case TK_PR_INT: size = sizeof(int);
        break;
    case TK_PR_FLOAT: size = sizeof(float);
        break;
    case TK_PR_BOOL:  size = sizeof(bool);
        break;
    case TK_PR_CHAR: size = sizeof(char);
        break;
    case TK_PR_STRING: size = sizeof(char*);
        break;
    }
    return size;
} 

hash_element* store_identificador(lexeme_t* id){
    hash_element* stored = (hash_element*)malloc(sizeof(hash_element));
    stored->name = id->name;
    stored->line = id->line;
    stored->type = id-> type;
    if(stored->nature == 3){
       stored->args = 0;
    }
    return stored;
}

void store_nature(hash_element** stored, int nature){
        hash_element* aux = *stored;
        aux->nature = nature;
        *stored = aux;
}
