/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "misc.h"
#include "element_stack.h"
#include "semantic.h"
#include "hash.h"
#include "parser.tab.h"

void store_identificador(hash_element **id_stored, lexeme_t *id)
{
    hash_element *aux = (hash_element *)malloc(sizeof(hash_element));
    aux->name = id->name;
    aux->line = id->line;
    aux->type = id->type;
    aux->val = id->val;

    *id_stored = aux;
}

void store_nature(hash_element **id_stored, int nature)
{
    hash_element *aux = *id_stored;
    aux->nature = nature;
    *id_stored = aux;
}

void store_vet_size(hash_element **id_stored, int size)
{
    hash_element *aux = *id_stored;
    aux->vet_size = size;
    *id_stored = aux;
}

void store_function_elem(hash_element **fun_stored)
{
    hash_element *aux = (hash_element *)malloc(sizeof(hash_element));
    aux = *fun_stored;
    aux->nature = NAT_FUN;

    // Parametros
    *fun_stored = aux;
}

void store_param(hash_element **stored_fun, ElementList *param_list)
{

    ElementList *aux = NULL;
    hash_element *fun = *stored_fun;
    hash_element *param;
    parameter *param_aux = (parameter *)malloc(sizeof(parameter));
    int args_cont = 0;
    // Salvando os parâmetros e contando
    while (!isEmpty_stack_list(param_list))
    {
        push_element(&aux, pop_element(&param_list));
        args_cont++;
    }
    fun->args_n = args_cont;
    /*if(top_e->name == NULL){
    fprintf(stderr, "param list = NULL \n");}*/
    if (args_cont > 0)
    {
        // Adcionando os parametros na lista da função
        fun->function_param = (parameter *)calloc(args_cont, sizeof(parameter));
        int i = 0;
        while (!isEmpty_stack_list(aux) && i < args_cont)
        {
            param = pop_element(&aux);
            push_element(&param_list, param);
            fun->function_param[i].name = param->name;
            fun->function_param[i].type = param->type;
            i++;
        }
    }
    *stored_fun = fun;
}

void check_parameters(StackNode *global_scope, hash_element *stored_fun, node_t *param_call)
{
    int call_args = 0;
    cont_call_args(param_call, &call_args);
    hash_element* function_declared = hash_search(global_scope, stored_fun->name, true);
    if (function_declared->args_n != call_args)
    {
        print_ERR_NUM_ARGS(stored_fun, function_declared->args_n, call_args);
    }
    ElementList *list = NULL;
    get_param_type_list(param_call, &list);
    // verificar na tabla hash
    parameter *typedecl = hash_search(global_scope, stored_fun->name, true)->function_param;
    for (int i = 0; i < function_declared->args_n; i++)
    {
        hash_element *topel = top_element(list);
        int typecall;
        if (topel->nature < 3)
        {
            typecall = hash_search(global_scope, topel->name, true)->type;
        }
        else
        {
            typecall = topel->type;
        }
        if (typedecl[i].type != typecall)
        {
            print_ERR_WRONG_TYPE_ARGS(stored_fun, typedecl[i].type, topel->name, typecall);
        }
        pop_element(&list);
    }
}

int check_input_output(StackNode *global_scope, hash_element *stored_elem)
{
        int typecall;
        if (stored_elem->nature < 3)
        {
            typecall = hash_search(global_scope, stored_elem->name, true)->type;
        }
        if (typecall == 258 || typecall == 259)
        {
            return -1;
        }
    return typecall;
}

int cont_call_args(node_t *list, int *args)
{
    if (list == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            node_t *child = list->children[i];
            cont_call_args(child, args);
        }
        *args += 1;
    }
}

void store_literal(hash_element **id_stored, lexeme_t *id, int nature)
{
    hash_element *aux = (hash_element *)malloc(sizeof(hash_element));
    char *name = malloc(1000);
    switch (nature)
    {
    case NAT_INT:
        sprintf(name, "%d", id->val.d);
        aux->type = TK_PR_INT;
        break;
    case NAT_FLOAT:
        sprintf(name, "%f", id->val.f);
        aux->type = TK_PR_FLOAT;
        break;
    case NAT_TRUE:
        sprintf(name, "true");
        aux->type = TK_PR_BOOL;
        break;
    case NAT_FALSE:
        sprintf(name, "false");
        aux->type = TK_PR_BOOL;
        break;
    case NAT_CHAR:
        sprintf(name, "%s", id->val.c);
        aux->type = TK_PR_CHAR;
        break;
    case NAT_STR:
        sprintf(name, "%s", id->val.s);
        aux->type = TK_PR_STRING;
        break;
    }
    aux->name = name;
    aux->line = id->line;
    aux->nature = nature;
    aux->val = id->val;
    *id_stored = aux;
}

int get_param_type_list(node_t *node, ElementList **root)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            node_t *child = node->children[i];
            get_param_type_list(child, root);
        }
        hash_element *param = (hash_element *)malloc(sizeof(hash_element));
        if (node->node_type < 2)
        {
            param->name = node->lex_value->name;
            param->line = node->lex_value->line;
            param->val = node->lex_value->val;
            param->type = node->lex_value->type;
        }
        else
        {
            if (node->node_type >= 3 && node->node_type < 9)
            {
                param = store_lit(node->lex_value, node->node_type);
                param->nature = node->node_type;
            }
        }

        push_element(root, param);
    }
}

hash_element *store_lit(lexeme_t *lit, int node_type)
{
    hash_element* element = (hash_element*)malloc(sizeof(hash_element));
    char *name = malloc(1000);
    switch (node_type)
    {
    case NAT_INT:
        sprintf(name, "%d", lit->val.d);
        element->type = TK_PR_INT;
        break;
    case NAT_FLOAT:
        sprintf(name, "%f", lit->val.f);
        element->type = TK_PR_FLOAT;
        break;
    case NAT_TRUE:
        sprintf(name, "true");
        element->type = TK_PR_BOOL;
        break;
    case NAT_FALSE:
        sprintf(name, "false");
        element->type = TK_PR_BOOL;
        break;
    case NAT_CHAR:
        sprintf(name, "%s", lit->val.c);
        element->type = TK_PR_CHAR;
        break;
    case NAT_STR:
        sprintf(name, "%s", lit->val.s);
        element->type = TK_PR_STRING;
        break;
    }
    element->name = name;
    element->line = lit->line;
    element->val = lit->val;

    return element;
}

int check_exp_type(ElementList* exp_list, StackNode* stack){
    hash_element * element;
    int type_return;
    int first_type, sec_type; 
    // invertendo lista
    exp_list = reverse_list(exp_list);
    // pegando o primeiro elemento da expressão
    char* first_name;
    if(exp_list != NULL){
    element = pop_element(&exp_list);
    first_name = element->name;
    first_type = hash_search(stack, element->name, true)->type;
    type_return = first_type;
    
    }
    while (!isEmpty_stack_list(exp_list))
        {
            element = pop_element(&exp_list);
            sec_type = hash_search(stack, element->name, true)->type;
            if (first_type == TK_PR_INT || first_type == TK_PR_FLOAT || first_type == TK_PR_BOOL){
                if(sec_type >260){
                    // tipo incopativel char ou string
                    if(sec_type == TK_PR_STRING)
                    print_ERR_STRING_TO_X(element->line, element->name, first_type);
                    if(sec_type == TK_PR_CHAR)
                    print_ERR_CHAR_TO_X(element->line, element->name, first_type);
                    //print_ERR_WRONG_EXP_TYPES(element->line,first_name,first_type, element->name,sec_type);
                }
                else{
                    if(sec_type == TK_PR_FLOAT && type_return != TK_PR_FLOAT){
                        type_return = TK_PR_FLOAT;
                    }
                    else
                    {
                        if(sec_type == TK_PR_INT && type_return != TK_PR_FLOAT){
                        type_return = TK_PR_INT;
                        }
                        else{
                            if(sec_type == TK_PR_INT && (type_return != TK_PR_FLOAT || type_return != TK_PR_INT)){
                                type_return = TK_PR_BOOL;
                            }
                        }

                    }
                    
                }
            }else
            {
                if(first_type != sec_type){
                    print_ERR_WRONG_EXP_TYPES(element->line,first_name,first_type, element->name,sec_type);
                }
                type_return = first_type;
            }
            
        }
    return type_return;
}
