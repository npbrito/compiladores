/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"
#include "semantic.h"
#include "misc.h"

void print_ERR_DECLARED(hash_element *id, int line)
{
    fprintf(stderr, "Line %d \033[1;31m ERR_DECLARED:\033[0m previous declaration of \033[1m'%s'\033[0m at line %d.\n", id->line, id->name, line);
    exit(ERR_DECLARED);
}

void print_ERR_UNDECLARED(hash_element *id)
{
    switch (id->nature)
    {
    case NAT_VAR:
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m variable \033[1m'%s'\033[0m not declared.\n", id->line, id->name);
        break;
    case NAT_VET:
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m vector \033[1m'%s'\033[0m not declared.\n", id->line, id->name);
        break;
    case NAT_FUN:
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m function \033[1m'%s'\033[0m not declared.\n", id->line, id->name);
        break;

    default:
        fprintf(stderr, "Line %d \033[1;31m ERR_UNDECLARED:\033[0m \033[1m'%s'\033[0m not declared.\n", id->line, id->name);

        break;
    }
    exit(ERR_UNDECLARED);
}

void print_ERR_VARIABLE(hash_element *id, int previous_nature)
{

    switch (previous_nature)
    {
    case NAT_VET:
        fprintf(stderr, "Line %d \033[1;31m ERR_VECTOR:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VARIABLE\033[0m but was delcared as\033[1;32m VECTOR.\033[0m\n", id->line, id->name);
        exit(ERR_VECTOR);
        break;
    case NAT_FUN:
        fprintf(stderr, "Line %d \033[1;31m ERR_FUNCTION:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VARIABLE\033[0m but was delcared as\033[1;32m FUNCTION.\033[0m\n", id->line, id->name);
        exit(ERR_FUNCTION);
        break;
    }
    exit(ERR_VARIABLE);
}
void print_ERR_VECTOR(hash_element *id, int previous_nature)
{
    switch (previous_nature)
    {
    case NAT_VAR:
        fprintf(stderr, "Line %d \033[1;31m ERR_VARIABLE:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VECTOR\033[0m but was delcared as\033[1;32m VARIABLE.\033[0m\n", id->line, id->name);
        exit(ERR_VARIABLE);
        break;
    case NAT_FUN:
        fprintf(stderr, "Line %d \033[1;31m ERR_FUNCTION:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m VECTOR\033[0m but was delcared as\033[1;32m FUNCTION.\033[0m\n", id->line, id->name);
        exit(ERR_FUNCTION);
        break;
    }
    exit(ERR_VECTOR);
}
void print_ERR_FUNCTION(hash_element *id, int previous_nature)
{
    switch (previous_nature)
    {
    case NAT_VET:
        fprintf(stderr, "Line %d \033[1;31m ERR_VECTOR:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m FUNCTION\033[0m but was delcared as\033[1;32m VECTOR.\033[0m\n", id->line, id->name);
        exit(ERR_VECTOR);
        break;
    case NAT_VAR:
        fprintf(stderr, "Line %d \033[1;31m ERR_VARIABLE:\033[0m identifier \033[1m'%s'\033[0m used as\033[1;31m FUNCTION\033[0m but was delcared as\033[1;32m VARIABLE.\033[0m\n", id->line, id->name);
        exit(ERR_VARIABLE);
        break;
    }
    
}

void print_ERR_NUM_ARGS(hash_element *id, int args_decl, int args_call)
{
    if (args_call > args_decl){
        fprintf(stderr, "Line %d \033[1;31m ERR_EXCESS_ARGS:\033[0m to much arguments on call of \033[1m'%s'\033[0m \033[1;31m %d\033[0m excess arguments.\n", id->line, id->name, args_call - args_decl);
      exit(ERR_EXCESS_ARGS);
    }
    
    if (args_call < args_decl){
        fprintf(stderr, "Line %d \033[1;31m ERR_MISSING_ARGS:\033[0m to few arguments on call of \033[1m'%s'\033[0m:\033[1;31m %d\033[0m missing arguments.\n", id->line, id->name, args_decl - args_call);
      exit(ERR_MISSING_ARGS);
    }


}

void print_ERR_WRONG_TYPE_ARGS(hash_element *id, int dectype, char *paramname, int paramtype)
{
    fprintf(stderr, "Line %d \033[1;31m ERR_WRONG_TYPE_ARGS:\033[0m ", id->line);
    fprintf(stderr, "on call of \033[1m'%s'\033[0m ", id->name);
    fprintf(stderr, "%s is ", paramname);
    fprintf(stderr, "\033[1;31m %s\033[0m, ", args_type(paramtype));
    fprintf(stderr, "but expected \033[1;32m%s.\033[0m\n", args_type(dectype));
    exit(ERR_WRONG_TYPE_ARGS);
}

void print_ERR_WRONG_PAR_INPUT(hash_element *id, int type)
{
    fprintf(stderr, "Line %d \033[1;31m ERR_WRONG_PAR_INPUT:\033[0m ", id->line);
    fprintf(stderr, "input expected \033[1;32mint\033[0m or \033[1;32mfloat\033[0m but is\033[1;31m %s\033[0m.\n", args_type(type));
    exit(ERR_WRONG_PAR_INPUT);
}

void print_ERR_WRONG_PAR_OUTPUT(hash_element *id, int type)
{
    fprintf(stderr, "Line %d \033[1;31m ERR_WRONG_PAR_OUTPUT:\033[0m ", id->line);
    fprintf(stderr, "output expected \033[1;32mint\033[0m or \033[1;32mfloat\033[0m but is\033[1;31m %s\033[0m.\n", args_type(type));
    exit(ERR_WRONG_PAR_OUTPUT);
}

void print_ERR_WRONG_EXP_TYPES(int line, char* name1, int type1, char* name2 ,int type2){
    fprintf(stderr, "Line %d \033[1;31mERR_WRONG_TYPE:\033[0m mismatch of types \033[1;31m%s\033[0m %s and \033[1;31m%s\033[0m %s in expression.\n" ,line ,args_type(type1), name1 ,args_type(type2), name2);
    exit(ERR_WRONG_TYPE);
}
void print_ERR_WRONG_PAR_RETURN(hash_element* fun,int type, int line){
    fprintf(stderr, "Line %d \033[1;31mERR_WRONG_PAR_RETURN:\033[0m return of \033[1m'%s'\033[0m expects \033[1;32m%s\033[0m but is \033[1;31m%s\033[0m.\n" ,line,fun->name, args_type(fun->type) ,args_type(type));
    exit(ERR_WRONG_PAR_RETURN);
}

void print_ERR_WRONG_ASS_TYPE(int line, int type, int wrongtype){
    fprintf(stderr, "Line %d \033[1;31mERR_WRONG_TYPE:\033[0m result of expression is \033[1;31m%s\033[0m but should be \033[1;32m%s\033[0m.\n" ,line, args_type(wrongtype) ,args_type(type));
    exit(ERR_WRONG_TYPE);
}

void print_ERR_CHAR_TO_X(int line, char *name, int wrongtype){
    fprintf(stderr, "Line %d \033[1;31mERR_CHAR_TO_X:\033[0m \033[1m'%s'\033[0m can not be converted to \033[1;31m%s\033[0m because is a \033[1;32mchar\033[0m.\n" ,line,name ,args_type(wrongtype));
    exit(ERR_CHAR_TO_X);
}

void print_ERR_STRING_TO_X(int line, char *name, int wrongtype){
    fprintf(stderr, "Line %d \033[1;31mERR_STRING_TO_X:\033[0m \033[1m'%s'\033[0m can not be converted to \033[1;31m%s\033[0m because is a \033[1;32mstring\033[0m.\n" ,line,name ,args_type(wrongtype));
    exit(ERR_STRING_TO_X);
}

char *args_type(int type)
{
    switch (type)
    {
    case 258:
        return "int";
    case 259:
        return "float";
    case 260:
        return "bool";
    case 261:
        return "char";
    case 262:
        return "string";
    }
}