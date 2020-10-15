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
#include "list.h"

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

    return ret; 
}