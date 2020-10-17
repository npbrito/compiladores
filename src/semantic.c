/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"

void print_ERR_DECLARED(hash_element* id, int line){
    fprintf(stderr, "Line %d \033[1;31m ERR_DECLARED:\033[0m previous declaration of \033[1m'%s'\033[0m at line %d.\n", id->line, id->name, line );
}

void print_ERR_UNDECLARED(hash_element* id, int line){
    fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m \033[1m'%s'\033[0m not declared.\n", line, id->name );
}