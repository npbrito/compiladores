#ifndef SEMANTIC_H_
#define SEMANTIC_H_

#include "hash.h"

// DECLARAÇÕES NA TABELA
#define ERR_UNDECLARED       10
#define ERR_DECLARED         11
// CASO A VARIAVEL TENHA INDEXAÇÃO
#define ERR_VARIABLE         20
// CASO O VET NÃO TENHA INDEXAÇÃO
#define ERR_VECTOR           21
// CASO A CHAMADA DE FUNÇÃO NÃO SEJA COMO CHAMADA DE FUNÇÃO 
#define ERR_FUNCTION         22
// TIPO DIFERENTE DO VALOR ATRIBUIDO
#define ERR_WRONG_TYPE       30
#define ERR_CHAR_TO_X        32
// ERRO EM STRING E CONVERSÃO DE STRING
#define ERR_STRING_TO_X      31
#define ERR_STRING_SIZE      33
// PARAMETROS DE FUNÇÕES
#define ERR_MISSING_ARGS     40
#define ERR_EXCESS_ARGS      41
#define ERR_WRONG_TYPE_ARGS  42
// ERROS DE PALAVRAS RESERVADAS
#define ERR_WRONG_PAR_INPUT  50
#define ERR_WRONG_PAR_OUTPUT 51
#define ERR_WRONG_PAR_RETURN 52
#define ERR_WRONG_PAR_SHIFT  53

void print_ERR_DECLARED(hash_element* ,int);
void print_ERR_UNDECLARED(hash_element* id, int line);

#endif // SEMANTIC_H_