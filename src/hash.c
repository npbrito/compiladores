/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"
#include "misc.h"
#include "parser.tab.h"

StackNode *create_stack(HashTable **new_data)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    stackNode->symbol_table = *new_data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, HashTable *data)
{
    StackNode *topNode = create_stack(&data);
    // Empurra a raiz pra baixo do novo elemento da pilha
    topNode->next = *root;
    *root = topNode;
}

HashTable *pop(StackNode **root)
{
    if (isEmpty(*root))
        return NULL;
    StackNode *temp = *root;
    *root = (*root)->next;
    HashTable *popped = temp->symbol_table;
    free(temp);
    return popped;
}

HashTable *top(StackNode *root)
{
    return root->symbol_table;
}

HashTable *bottom(StackNode *root)
{
    StackNode *last_stack = NULL;
    HashTable *last_table = NULL;
    // desempilahndo até o ultimo elemento
    int i = 0;
    while (!isEmpty(root))
    {
        push(&last_stack, pop(&root));
    }
    last_table = top(last_stack);
    // empilhando
    while (!isEmpty(last_stack))
    {
        push(&root, pop(&last_stack));
    }
    return last_table;
}

//--------------------------------------------------------

int stored_nature = 0;

HashTable *hash_create()
{
    HashTable *table = (HashTable *)calloc(HASH_SIZE, sizeof(HashTable));
    if (!table)
    {
        puts("Unable to allocate memory");
        exit(1);
    }
    // Initialize INDEXES
    for (int i = 0; i < HASH_SIZE; i++)
    {
        table[i].key = -1;
    }
    table[0].occuped = 0;
    return table;
}

void hash_insert(HashTable **root, hash_element *newElement, int type)
{
    HashTable *table = *root;
    // Check if table is full
    if (table->occuped < HASH_SIZE)
    {

        int index = 1;
        // identificadores

        char *varname = newElement->name;

        index = calc_index(varname);
        switch (newElement->nature)
        {
        case 0:
        case 1:
        case 2:
            table->occuped++;
            while (table[index].value != NULL)
            {
                index++;
            }
            break;
        default:
            while (table[index].value != NULL)
            {
                if (strcmp(table[index].value->name, varname) == 0)
                {
                    break;
                }
                index++;
            }
            break;
        }

        table[index].key = index;
        table[index].value = newElement;
        table[index].value->type = type;

        if (newElement->nature == NAT_VET)
        {
            table[index].value->type_size = newElement->vet_size * calc_type_size(type);
        }
        else
        {
            if (newElement->nature == NAT_STR){
            table[index].value->type_size = strlen(varname)*calc_type_size(type);
            }
            else
            {
            
            table[index].value->type_size = calc_type_size(type);
            }
            
        }
    }
    else
    {
        fprintf(stderr, "Insufficient memory to allocate '%s'\n", newElement->name);
    }
    *root = table;
}

hash_element* hash_search(StackNode *stack, char *name)
{
    // primeiro procurano escopo global
    HashTable *table = bottom(stack);
    int index = calc_index(name);
    int elements_searched = 0;
    while (table[index].value != NULL && elements_searched < HASH_SIZE)
    {
        if (strcmp(name, table[index].value->name) == 0)
            return table[index].value;
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
            return table[index].value;
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
    return NULL;
}

void hash_print(HashTable *table)
{
    int i;
    fprintf(stderr, "\n=========================================================================================\n");
    for (i = 0; i < HASH_SIZE; i++)
    {
        if (table[i].key >= 0)
        {
            fprintf(stderr, "[%d]\t| NAME %s \t", table[i].key, table[i].value->name);
            fprintf(stderr, "| LOCATION %d \t| NATURE %d\t", table[i].value->line, table[i].value->nature);
            fprintf(stderr, "| TYPE %d \t | TYPE SIZE %d \t\n", table[i].value->type, table[i].value->type_size);
        }
        else
        {
            fprintf(stderr, "[%d]\t| EMPTY \n", i);
        }
    }
    fprintf(stderr, "=========================================================================================\n");
}

int calc_index(char str[])
{
    /* Calculation method of:
     * https://cp-algorithms.com/string/string-hashing.html */
    int hash_index = 1;
    int p_pow = 1;
    int count;
    for (count = 0; count < strlen(str); count++)
    {
        hash_index = (hash_index + (str[count] - 'a' + 1) * p_pow) % HASH_SIZE;
        p_pow = (p_pow * 31) % HASH_SIZE;
    }
    return (hash_index - 1 < 0) ? 0 : hash_index - 1;
}

int calc_type_size(int type)
{
    int size = 0;
    switch (type)
    {
    case 258:
        size = 4;
        break;
    case 259:
        size = 8;
        break;
    case 260:
        size = 1;
        break;
    case 261:
        size = 1;
        break;
    case 262:
        size = 1;
        break;
    }
    return size;
}
