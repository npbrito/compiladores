/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "parser.tab.h"

node_t *create_node(int type,lexeme_t *lex_value, int N, ...)
{
    node_t *ans = (node_t*)malloc(sizeof(node_t));
    if (!ans) {
        return NULL;
    }
    memset(ans, 0, sizeof(node_t));
    ans->lex_value = lex_value;
    ans->node_type = type;
    if (N > 0) {
        va_list args;
        va_start(args, N);
        for (int i=0; i<N; i++) {
            ans->children[i] = va_arg(args, node_t*);
        }
        va_end(args);
    }
    return ans;
}

node_t *add_node(node_t *parent, node_t *child)
{
    int idx = -1;
    while(parent->children[++idx] && idx < MAX_CHILDREN);
    if (idx < MAX_CHILDREN) {
        parent->children[idx] = child;
    }
    return parent;
}

void destroy_node(node_t *tree)
{
    if (!tree) return;
    for (int i=0; i<MAX_CHILDREN; i++) {
        destroy_node(tree->children[i]);
        tree->children[i] = NULL;
    }
    destroy_lexeme(tree->lex_value);
    tree->lex_value = NULL;
    free(tree);
}

void destroy_lexeme(lexeme_t *lex_value)
{
    if (!lex_value) return;
    if (lex_value->type == TK_LIT_STRING || lex_value->type == TK_LIT_CHAR) {
        free(lex_value->val.s);
        lex_value->val.s = NULL;
    }
    free(lex_value->name);
    lex_value->name = NULL;
    free(lex_value);
}

static void print_node(node_t *tree, bool relation)
{
    if (!tree) return;
    if (!relation) {
        lexeme_t *lex = tree->lex_value;
        printf("%p [label=\"", tree);
        switch (lex->type) {
        case TK_LIT_INT:     printf("%d", lex->val.d); break;
        case TK_LIT_FLOAT:   printf("%f", lex->val.f); break;
        case TK_LIT_FALSE:   printf("false"); break;
        case TK_LIT_TRUE:    printf("true"); break;
        case TK_LIT_CHAR:
        case TK_LIT_STRING:  printf("%s", lex->val.s); break;
        case TYPE_FUNC_CALL: printf("call ");
        default:             printf("%s", lex->name); break;
        }
        printf("\"];\n");
    }
    for (int i=0; i<MAX_CHILDREN; i++) {
        node_t *child = tree->children[i];
        if (!child) continue;
        if (relation) {
            printf("%p, %p\n", tree, child);
        }
        print_node(child, relation);
    }
}

void libera (void *arvore)
{
    destroy_node((node_t*)arvore);
}

void exporta (void *arvore)
{
    print_node((node_t*)arvore, true);
    print_node((node_t*)arvore, false);
}
