 /* Natália Brito | 00274727 */
 /* Yuri Jaschek  | 00231592 */

%{

#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "hash.h"
#include "stack.h"
#include "list.h"
#include "misc.h"

void yyerror(char const *s);
void replace_name(lexeme_t *lex, const char *str);
extern int yylex(void);
extern int yylineno;
extern void *arvore;
StackNode* global_scope = NULL;
ElementList* var_list = NULL;
hash_element* stored_element = NULL;
hash_element* stored_fun = NULL;
extern HashTable * table;

%}

%union {
    lexeme_t *lex_value;
    node_t *tree_node;
    int type;
}

/* Tokens */

%token <type> TK_PR_INT
%token <type> TK_PR_FLOAT
%token <type> TK_PR_BOOL
%token <type> TK_PR_CHAR
%token <type> TK_PR_STRING
%token <lex_value> TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token <lex_value> TK_PR_WHILE
%token TK_PR_DO
%token <lex_value> TK_PR_INPUT
%token <lex_value> TK_PR_OUTPUT
%token <lex_value> TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token <lex_value> TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token <lex_value> TK_PR_BREAK
%token <lex_value> TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT
%token <lex_value> TK_OC_LE
%token <lex_value> TK_OC_GE
%token <lex_value> TK_OC_EQ
%token <lex_value> TK_OC_NE
%token <lex_value> TK_OC_AND
%token <lex_value> TK_OC_OR
%token <lex_value> TK_OC_SL
%token <lex_value> TK_OC_SR
%token <lex_value> TK_LIT_INT
%token <lex_value> TK_LIT_FLOAT
%token <lex_value> TK_LIT_FALSE
%token <lex_value> TK_LIT_TRUE
%token <lex_value> TK_LIT_CHAR
%token <lex_value> TK_LIT_STRING
%token <lex_value> TK_IDENTIFICADOR
%token <lex_value> '!'
%token <lex_value> '{'
%token <lex_value> '}'
%token <lex_value> '#'
%token <lex_value> '%'
%token <lex_value> '&'
%token <lex_value> '*'
%token <lex_value> '+'
%token <lex_value> '-'
%token <lex_value> '/'
%token <lex_value> '<'
%token <lex_value> '='
%token <lex_value> '>'
%token <lex_value> '?'
%token <lex_value> '^'
%token <lex_value> '|'
%token <lex_value> '['
%token TOKEN_ERRO
// To differentiate between func call with no params and a simple identifier
%token TYPE_FUNC_CALL

%right '?' ':'
%left TK_OC_AND
%left TK_OC_OR
%left '|'
%left '&'
%left TK_OC_EQ TK_OC_NE
%left TK_OC_GE TK_OC_LE '>' '<'
%left TK_OC_SR TK_OC_SL
%left '+' '-'
%left '*' '/' '%'
%left '^'
%right '!' '#'
%left "("

// START
%type <tree_node> Start
%type <tree_node> Program
// BASIC DEFINITIONS
%type <tree_node> ID
%type <tree_node> FunID
%type <tree_node> IDArray
%type <tree_node> Lit
%type <tree_node> Int
%type <type> TypeBase
%type <type> TypeStaticConst
%type <type> TypeStatic
// FUNCTIONS AND VARIABLES
%type <tree_node> FuncDecl
%type <tree_node> ParamsDecl
%type <tree_node> ParamDeclList
%type <tree_node> ParamDecl
%type <tree_node> FuncCall
%type <tree_node> ParamsCall
%type <tree_node> ParamCallList
%type <lex_value> GlobalVarDecl
%type <lex_value> GlobalVarList
%type <lex_value> GlobalVar
%type <tree_node> LocalVarDecl
%type <tree_node> LocalVarList
%type <tree_node> LocalVar
// EXPRESSIONS
%type <tree_node> Expr
%type <tree_node> UnaryExpr
%type <tree_node> UnarySet
// COMMANDS
%type <tree_node> Cmd
%type <tree_node> CmdBlock
%type <tree_node> CmdSeq
%type <tree_node> Assignment
%type <tree_node> ControlFlow
%type <tree_node> If
%type <tree_node> Else
%type <tree_node> For
%type <tree_node> While

%locations
%define parse.error verbose

%start Start

%%

/*********
 * START *
 *********/
Init: %empty {push(&global_scope, hash_create());}
    ;
End: %empty {hash_print(top(global_scope));}
Start: Init Program End { arvore = $2; }
    ;
Program: %empty                    { $$ = NULL;             }
       | GlobalVarDecl ';' Program { $$ = $3;               }
       | FuncDecl Program          { $$ = add_node($1, $2); }
       ;

/*********************
 * BASIC DEFINITIONS *
 *********************/

ID: TK_IDENTIFICADOR { store_identificador(&stored_element, $1); 
                        $$ = create_node($1, 0);
                    }
  ;
IDArray: ID              { $$ = $1;                             }
       | ID '[' Expr ']' { replace_name($2, "[]");
                           $$ = create_node($2, 2, $1, $3);}
       ;
FunID: TK_IDENTIFICADOR { store_identificador(&stored_fun, $1); 
                        $$ = create_node($1, 0);
                    }

Lit: TK_LIT_INT    { $$ = create_node($1, 0);}
   | TK_LIT_FLOAT  { $$ = create_node($1, 0);}
   | TK_LIT_TRUE   { $$ = create_node($1, 0);}
   | TK_LIT_FALSE  { $$ = create_node($1, 0);}
   | TK_LIT_CHAR   { $$ = create_node($1, 0);}
   | TK_LIT_STRING { $$ = create_node($1, 0);}
   ;
Int: TK_LIT_INT { $$ = create_node($1, 0); }
   ;

/*********
 * TYPES *
 *********/

TypeBase: 
          TK_PR_INT    {$$ = TK_PR_INT;}
        | TK_PR_FLOAT  {$$ = TK_PR_FLOAT;}
        | TK_PR_BOOL   {$$ = TK_PR_BOOL;}
        | TK_PR_CHAR   {$$ = TK_PR_CHAR;}
        | TK_PR_STRING {$$ = TK_PR_STRING;}
        ;
TypeStatic: TypeBase              {}
          | TK_PR_STATIC TypeBase {}
          ;
TypeConst: TypeBase             {}
         | TK_PR_CONST TypeBase {}
         ;
TypeStaticConst: TypeBase                          {}
               | TK_PR_STATIC TypeBase             {}
               | TK_PR_CONST TypeBase              {}
               | TK_PR_STATIC TK_PR_CONST TypeBase {}
               ;

/***************************
 * FUNCTIONS AND VARIABLES *
 ***************************/

/* Function declaration */
FuncDecl: TypeStatic FunID '(' ParamsDecl ')' CmdBlock { 
                                                    $$ = add_node($2, $6); 
                                                    store_function_elem(&stored_fun);
                                                    HashTable *table = top(global_scope);
                                                    hash_insert(&table, stored_fun, $1);
                                                    }
        ;
ParamsDecl: %empty        {}
          | ParamDeclList {}
          ;
ParamDeclList: ParamDecl                   {}
             | ParamDecl ',' ParamDeclList {}
             ;
ParamDecl: TypeConst ID { destroy_node($2); 
                    store_nature(&stored_element, NAT_VAR);
                    push_element(&var_list, stored_element);}
         ;

/* Function call */
FuncCall: ID '(' ParamsCall ')' { ($1)->lex_value->type = TYPE_FUNC_CALL; $$ = add_node($1, $3); }
        ;
ParamsCall: %empty        { $$ = NULL; }
          | ParamCallList { $$ = $1;   }
          ;
ParamCallList: Expr                   { $$ = $1;               }
             | Expr ',' ParamCallList { $$ = add_node($1, $3); }
             ;

/* Global variable declaration */
GlobalVarDecl: TypeStatic GlobalVarList { HashTable *table = top(global_scope);
                                            while(!isEmpty_stack_list(var_list)){
                                            hash_element* element = pop_element(&var_list);
                                            hash_insert(&table, element, $1);}
                                        }
             ;
GlobalVarList: GlobalVar                   {}
             | GlobalVar ',' GlobalVarList {}
             ;
GlobalVar: ID      {store_nature(&stored_element, NAT_VAR);
                    push_element(&var_list, stored_element);}
         | ID '[' TK_LIT_INT ']' {store_nature(&stored_element, NAT_VET);
         store_vet_size(&stored_element, $3->val.d); 
         push_element(&var_list, stored_element);}
         ;

/* Local variable declaration */
LocalVarDecl: 
             TypeStaticConst LocalVarList { $$ = $2; 
                                        HashTable *table = top(global_scope);
                                        while(!isEmpty_stack_list(var_list)){
                                            hash_element* element = pop_element(&var_list);
                                            hash_insert(&table, element, $1);
                                        }
             }
            ;
LocalVarList: LocalVar                  { $$ = $1;                                     }
            | LocalVar ',' LocalVarList { $$ = ($1) == NULL ? ($3) : add_node($1, $3); }
            ;
LocalVar: 
        TK_IDENTIFICADOR                      { store_identificador(&stored_element, $1); $$ = NULL;
                                                store_nature(&stored_element, NAT_VAR);
                                                push_element(&var_list, stored_element);}
        | ID TK_OC_LE IDArray { $$ = create_node($2, 2, $1, $3);
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
        | ID TK_OC_LE Lit     { $$ = create_node($2, 2, $1, $3); 
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
        ;

/***************
 * EXPRESSIONS *
 ***************/

Expr: UnaryExpr              { $$ = $1;                             }
    | UnarySet               { $$ = $1;                             }
    | Expr '+' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '-' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '*' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '/' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '%' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '|' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '&' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '^' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '<' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr '>' Expr          { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_EQ Expr     { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_NE Expr     { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_LE Expr     { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_GE Expr     { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_AND Expr    { $$ = create_node($2, 2, $1, $3);     }
    | Expr TK_OC_OR Expr     { $$ = create_node($2, 2, $1, $3);     }
    | Expr '?' Expr ':' Expr { replace_name($2, "?:");
                               $$ = create_node($2, 3, $1, $3, $5); }
    | '(' Expr ')'           { $$ = $2;                             }
    ;
UnaryExpr: IDArray  { $$ = $1; }
         | Lit      { $$ = $1; }
         | FuncCall { $$ = $1; }
         ;
UnarySet: '+' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '-' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '!' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '&' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '*' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '?' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '#' UnaryExpr UnarySet { $$ = create_node($1, 1, $2, $3); }
        | '+' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '-' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '!' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '&' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '*' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '?' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        | '#' UnaryExpr          { $$ = create_node($1, 1, $2);     }
        ;

/************
 * COMMANDS *
 ************/
CreateScope: '{' { push(&global_scope, hash_create());}
            ;
DestroyScope: '}' { hash_print(top(global_scope)); pop(&global_scope);}
                ;

Cmd: LocalVarDecl            { $$ = $1;                         }
   | Assignment              { $$ = $1;                         }
   | TK_PR_INPUT IDArray     { $$ = create_node($1, 1, $2);     }
   | TK_PR_OUTPUT IDArray    { $$ = create_node($1, 1, $2);     }
   | TK_PR_OUTPUT Lit        { $$ = create_node($1, 1, $2);     }
   | CmdBlock                { $$ = $1;                         }
   | FuncCall                { $$ = $1;                         }
   | IDArray TK_OC_SL Int    { $$ = create_node($2, 2, $1, $3); }
   | IDArray TK_OC_SR Int    { $$ = create_node($2, 2, $1, $3); }
   | TK_PR_RETURN Expr       { $$ = create_node($1, 1, $2);     }
   | TK_PR_BREAK             { $$ = create_node($1, 0);         }
   | TK_PR_CONTINUE          { $$ = create_node($1, 0);         }
   | ControlFlow             { $$ = $1;                         }
   ;
CmdBlock: CreateScope CmdSeq DestroyScope { $$ = $2;}
        ;
CmdSeq: %empty          { $$ = NULL;                                   }
      | Cmd ';' CmdSeq  { $$ = ($1) == NULL ? ($3) : add_node($1, $3); }
      ;

 /*Assignment */
Assignment: IDArray '=' Expr { $$ = create_node($2, 2, $1, $3); }
          ;

/* Control flow */
ControlFlow: If      { $$ = $1; }
           | For     { $$ = $1; }
           | While   { $$ = $1; }
           ;
If: TK_PR_IF '(' Expr ')' CmdBlock Else { $$ = create_node($1, 3, $3, $5, $6); }
  ;
Else: %empty              { $$ = NULL; }
    | TK_PR_ELSE CmdBlock { $$ = $2;   }
    ;
For: TK_PR_FOR '(' Assignment ':' Expr ':' Assignment ')' CmdBlock { $$ = create_node($1, 4, $3, $5, $7, $9); }
   ;
While: TK_PR_WHILE '(' Expr ')' TK_PR_DO CmdBlock { $$ = create_node($1, 2, $3, $6); }
     ;


%%


void replace_name(lexeme_t *lex, const char *str)
{
    free(lex->name);
    lex->name = strdup(str);
}

void yyerror(char const *s)
{
    fprintf(stderr, "At line %d: %s\n", yylineno, s);
}
