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