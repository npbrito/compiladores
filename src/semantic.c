/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"
#include "semantic.h"
#include "misc.h"

void print_ERR_DECLARED(hash_element* id, int line){
    fprintf(stderr, "Line %d \033[1;31m ERR_DECLARED:\033[0m previous declaration of \033[1m'%s'\033[0m at line %d.\n", id->line, id->name, line );
}

void print_ERR_UNDECLARED(hash_element* id){
    switch (id->nature)
    {
    case NAT_VAR: 
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m variable \033[1m'%s'\033[0m not declared.\n", id->line, id->name );
        break;
    case NAT_VET: 
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m vector \033[1m'%s'\033[0m not declared.\n", id->line, id->name );
        break;
    case NAT_FUN: 
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m function \033[1m'%s'\033[0m not declared.\n", id->line, id->name );
        break;
    
    default:fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m \033[1m'%s'\033[0m not declared.\n", id->line, id->name );

        break;
    }
}


void print_ERR_VARIABLE(hash_element* id, int previous_nature){

    switch (previous_nature){
        case NAT_VET:
        fprintf(stderr, "Line %d \033[1;31m ERR_VARIABLE:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VARIABLE\033[0m but was delcared as\033[1;32m VECTOR.\033[0m\n", id->line, id->name );
        break;
        case NAT_FUN:
        fprintf(stderr, "Line %d \033[1;31m ERR_VARIABLE:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VARIABLE\033[0m but was delcared as\033[1;32m FUNCTION.\033[0m\n", id->line, id->name );
        break;
    }
}
void print_ERR_VECTOR(hash_element* id, int previous_nature){
    switch (previous_nature){
        case NAT_VAR:
        fprintf(stderr, "Line %d \033[1;31m ERR_VECTOR:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VECTOR\033[0m but was delcared as\033[1;32m VARIABLE.\033[0m\n", id->line, id->name );
        break;
        case NAT_FUN:
        fprintf(stderr, "Line %d \033[1;31m ERR_VECTOR:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VECTOR\033[0m but was delcared as\033[1;32m FUNCTION.\033[0m\n", id->line, id->name );
        break;
    }
}
void print_ERR_FUNCTION(hash_element* id, int previous_nature){
    switch (previous_nature){
        case NAT_VET:
        fprintf(stderr, "Line %d \033[1;31m ERR_FUNCTION:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m FUNCTION\033[0m but was delcared as\033[1;32m VECTOR.\033[0m\n", id->line, id->name );
        break;
        case NAT_VAR:
        fprintf(stderr, "Line %d \033[1;31m ERR_FUNCTION:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m FUNCTION\033[0m but was delcared as\033[1;32m VARIABLE.\033[0m\n", id->line, id->name );
        break;
    }
}

void print_ERR_NUM_ARGS(hash_element* id, int args_decl, int args_call){
        if (args_call > args_decl)
        fprintf(stderr, "Line %d \033[1;31m ERR_EXCESS_ARGS:\033[0m to much arguments on call of \033[1m'%s'\033[0m. \033[1;31m %d\033[0m excess arguments.\n", id->line, id->name, args_call-args_decl);
        if (args_call < args_decl)
        fprintf(stderr, "Line %d \033[1;31m ERR_MISSING_ARGS:\033[0m to few arguments on call of \033[1m'%s'\033[0m. \033[1;31m %d\033[0m missing arguments.\n", id->line, id->name, args_decl-args_call);

    
}
