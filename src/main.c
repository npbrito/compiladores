/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "stack.h"
#include "tree.h"

extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
void exporta (void *arvore);
void libera (void *arvore);

int main(int argc, char **argv){


  int ret = yyparse(); 
  exporta (arvore);
  libera(arvore);
  arvore = NULL;
  yylex_destroy();

   /*
   // HASH TABLE USAGE
    HashTable* table;
   
    table = hash_create();
    
    lexeme_t* fisrt = (lexeme_t*)malloc(sizeof(lexeme_t));
    fisrt->line = 1;
    fisrt->type = 261;
    fisrt->name = "firstVar";

    if(!hash_search(table, fisrt->name))
    hash_insert(&table, fisrt);

    // STACK USAGE
    StackNode* root = create_stack(&table);
    
    table = hash_create();

    push(&root, table);

    if(!hash_search(top(root), fisrt->name)){
    printf("nop\n");}
    else{
    hash_print(top(root));
    }

    pop(&root);

    if(!hash_search(top(root), fisrt->name)){
    printf("nop\n");}
    else{
    hash_print(top(root));}
    */
    return ret; 
}