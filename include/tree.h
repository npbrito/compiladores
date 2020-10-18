/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#define MAX_CHILDREN   8 // Technically max is 5, but just to be sure

union Literal {
    int d;
    float f;
    bool b;
    char *s;
};

typedef struct {
    int line;
    int type;
    char *name;
    union Literal val;
} lexeme_t;

typedef struct node_t {
    lexeme_t *lex_value;
    int node_type;
    struct node_t *children[MAX_CHILDREN];
} node_t;

node_t *create_node(int type,lexeme_t *lex_value, int N, ...);
node_t *add_node(node_t *parent, node_t *child);
void destroy_node(node_t *tree);
void destroy_lexeme(lexeme_t *lex_value);

#endif // TREE_H
