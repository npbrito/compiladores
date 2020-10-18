/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#ifndef MISC_H_
#define MISC_H_

#include "hash.h"
#include "list.h"

/* Other functions that help store values. */

#define NAT_VAR 0
#define NAT_VET 1
#define NAT_FUN 2
#define NAT_INT 3
#define NAT_FLOAT 4
#define NAT_TRUE 5
#define NAT_FALSE 6
#define NAT_CHAR 7
#define NAT_STR 8
#define CMD 9
#define EXP 10
#define INP 11
#define OUT 12
#define SL 13
#define SR 14
#define RET 15
#define BREAK 16
#define CONT 17
#define ASS 18
#define FLOW 19
#define PARAM 20

void store_identificador(hash_element**, lexeme_t*);

void store_nature(hash_element**, int nature);

void store_vet_size(hash_element** id_stored, int size);

void store_function_elem(hash_element**);

void store_param(hash_element**, ElementList*);

int id_nature(StackNode*, char* );

int search_type(StackNode *, char *);

void check_parameters(StackNode* ,hash_element* ,node_t * );

int check_input_output(StackNode *, hash_element *);

int get_decl_args(StackNode * stack, char * name);

parameter* fun_table_type_decl(StackNode *, char *);

int check_fun_args(ElementList*);

int cont_call_args(node_t*, int*);

void store_literal(hash_element** id_stored, lexeme_t* id, int nature);

int get_param_type_list(node_t* node, ElementList** root);

hash_element *store_lit(lexeme_t *, int );

#endif // MISC_H_