/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "misc.h"
#include "list.h"
#include "semantic.h"
#include "hash.h"

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
    fun->function_args = args_cont;
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
            fun->function_param[i].name = param->name;
            fun->function_param[i].type = param->type;
            i++;
        }
    }
    *stored_fun = fun;
}

int id_nature(StackNode *stack, char *name)
{
    HashTable *table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->nature;
        if (index < HASH_SIZE)
        {
            index++;
        }
        else
        {
            index = 0;
        }
        elements_searched++;
    }
    // depois procura no escopo local
    table = top(stack);
    elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->nature;
        if (index < HASH_SIZE)
        {
            index++;
        }
        else
        {
            index = 0;
        }
        elements_searched++;
    }
}
parameter *fun_table_type_decl(StackNode *stack, char *name)
{
    HashTable *table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->function_param;
        if (index < HASH_SIZE)
        {
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

int search_type(StackNode *stack, char *name)
{
    HashTable *table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->type;
        if (index < HASH_SIZE)
        {
            index++;
        }
        else
        {
            index = 0;
        }
        elements_searched++;
    }
    // depois procura no escopo local
    table = top(stack);
    elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->type;
        if (index < HASH_SIZE)
        {
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

void check_parameters(StackNode *global_scope, hash_element *stored_fun, node_t *param_call)
{
    int call_args = 0;
    cont_call_args(param_call, &call_args);
    int decl_args = get_decl_args(global_scope, stored_fun->name);
    if (decl_args != call_args)
    {
        print_ERR_NUM_ARGS(stored_fun, decl_args, call_args);
    }
    ElementList *list = NULL;
    get_param_type_list(param_call, &list);
    // verificar na tabla hash
    parameter *typedecl = fun_table_type_decl(global_scope, stored_fun->name);
    for (int i = 0; i < decl_args; i++)
    {
        hash_element *topel = top_element(list);
        int typecall;
        if (topel->nature < 3)
        {
            typecall = search_type(global_scope, topel->name);
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
            typecall = search_type(global_scope, stored_elem->name);
        }
        if (typecall == 258 || typecall == 259)
        {
            return -1;
        }
    return typecall;
}

int get_decl_args(StackNode *stack, char *name)
{
    HashTable *table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value->function_args;
        if (index < HASH_SIZE)
        {
            index++;
        }
        else
        {
            index = 0;
        }
        elements_searched++;
        fprintf(stderr, " %d \n\n", elements_searched);
    }
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
        break;
    case NAT_FLOAT:
        sprintf(name, "%f", id->val.f);
        break;
    case NAT_TRUE:
        sprintf(name, "true");
        break;
    case NAT_FALSE:
        sprintf(name, "false");
        break;
    case NAT_CHAR:
        sprintf(name, "%s", id->val.s);
        break;
    case NAT_STR:
        sprintf(name, "%s", id->val.s);
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
        element->type = 258;
        break;
    case NAT_FLOAT:
        sprintf(name, "%f", lit->val.f);
        element->type = 259;
        break;
    case NAT_TRUE:
        sprintf(name, "true");
        element->type = 260;
        break;
    case NAT_FALSE:
        sprintf(name, "false");
        element->type = 260;
        break;
    case NAT_CHAR:
        sprintf(name, "%s", lit->val.s);
        element->type = 261;
        break;
    case NAT_STR:
        sprintf(name, "%s", lit->val.s);
        element->type = 262;
        break;
    }
    element->name = name;
    element->line = lit->line;
    element->val = lit->val;

    return element;
}