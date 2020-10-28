/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

%{

#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "hash.h"
#include "element_stack.h"
#include "misc.h"
#include "semantic.h"

void yyerror(char const *s);
void replace_name(lexeme_t *lex, const char *str);
extern int yylex(void);
extern int yylineno;
extern void *arvore;
StackNode* global_scope = NULL;
ElementList* var_list = NULL;
ElementList* param_list = NULL;
hash_element* stored_element = NULL;
hash_element* stored_IDArray = NULL;
hash_element* stored_literal = NULL;
hash_element* stored_fundecl = NULL;
hash_element* stored_fun = NULL;

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
%type <type> TypeConst
// FUNCTIONS AND VARIABLES
%type <tree_node> FuncDecl
%type <tree_node> FuncHead
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
%type <tree_node> FunCmdBlock
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
End: %empty {}
Start: Init Program End { arvore = $2; }
    ;
Program: %empty                    { $$ = NULL;             }
       | GlobalVarDecl ';' Program { $$ = $3;               }
       | FuncDecl Program          { $$ = add_node($1, $2); 
}
       ;

/*********************
 * BASIC DEFINITIONS *
 *********************/

ID: TK_IDENTIFICADOR { store_identificador(&stored_element, $1); 
                        $$ = create_node(NAT_VAR,$1, 0);
                    }
  ;
IDArray: ID              { $$ = $1;  
                         store_nature(&stored_element, NAT_VAR);
                            hash_element* element = hash_search(global_scope, stored_element->name, true);
                             stored_IDArray = stored_element;
                            if(element == NULL){
                                print_ERR_UNDECLARED(stored_element);
                            }
                            else{
                                if(element->nature != 0)
                                {
                                    print_ERR_VARIABLE(stored_element, element->nature);
                                }
                            }
                        }
       | ID '[' Expr ']' { 
                            replace_name($2, "[]");
                            $$ = create_node(NAT_VET,$2, 2, $1, $3);
                            store_nature(&stored_element, NAT_VET);
                            hash_element * element = hash_search(global_scope, stored_element->name, true);
                            stored_IDArray = stored_element;
                            pop_element(&param_list);
                            if(element == NULL){
                                print_ERR_UNDECLARED(stored_element);
                            }
                            else{
                                if(element->nature != 1)
                                {
                                    print_ERR_VECTOR(stored_element, element->nature);
                                }
                            }
                            }
       ;
FunID: TK_IDENTIFICADOR { store_identificador(&stored_fun, $1); 
                        $$ = create_node(NAT_VET,$1, 0);
                    }

Lit: TK_LIT_INT    { $$ = create_node(NAT_INT,$1, 0);
                    store_literal(&stored_literal, $1, NAT_INT);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_INT);

                    }
   | TK_LIT_FLOAT  { $$ = create_node(NAT_FLOAT,$1, 0);
                    store_literal(&stored_literal, $1, NAT_FLOAT);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_FLOAT);
}
   | TK_LIT_TRUE   { $$ = create_node(NAT_TRUE,$1, 0);
                    store_literal(&stored_literal, $1, NAT_TRUE);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_BOOL);}
   | TK_LIT_FALSE  { $$ = create_node(NAT_FALSE,$1, 0);
                     store_literal(&stored_literal, $1, NAT_FALSE);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_BOOL);}
   | TK_LIT_CHAR   { $$ = create_node(NAT_CHAR,$1, 0);
                    store_literal(&stored_literal, $1, NAT_CHAR);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_CHAR);}
   | TK_LIT_STRING { $$ = create_node(NAT_STR,$1, 0);
                    store_literal(&stored_literal, $1, NAT_STR);
                    HashTable * table = top(global_scope);
                    hash_insert(&table, stored_literal,TK_PR_STRING);
                    }
   ;
Int: TK_LIT_INT { $$ = create_node(NAT_INT,$1, 0); }
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
FuncDecl: FuncHead FunCmdBlock {
                            add_node($1, $2); }
                            ;
FuncHead: TypeStatic FunID '(' ParamsDecl ')'  {    
                                                    stored_fundecl = stored_fun;
                                                    store_function_elem(&stored_fun);
                                                    HashTable * table = top(global_scope);
                                                    hash_element* element = hash_search(global_scope, stored_fun->name, true);
                                                    if (element == NULL){
                                                    store_param(&stored_fun,param_list);
                                                    hash_insert(&table, stored_fun, $1);

                                                    }                                            
                                                    else{
                                                    // NÃO COLOCAR NA ÁRVORE CASO TIVER ERRO
                                                    print_ERR_DECLARED(stored_fun ,element->line);
                                            }
                                            $$ = $2;   
}
        ;
ParamsDecl: %empty        {}
          | ParamDeclList {}
          ;
ParamDeclList: ParamDecl                   {}
             | ParamDecl ',' ParamDeclList {}
             ;
ParamDecl: TypeConst TK_IDENTIFICADOR { store_identificador(&stored_element,$2);
                    store_nature(&stored_element, NAT_VAR);
                    push_param(&param_list, stored_element, $1);}
         ;

/* Function call */
FuncCall: FunID '(' ParamsCall ')' { 
                                store_nature(&stored_fun, NAT_FUN);
                                hash_element * element = hash_search(global_scope, stored_fun->name, true);                               
                                if(element == NULL){
                                print_ERR_UNDECLARED(stored_fun);
                                }
                                else{
                                if(element->nature != 2)
                                {
                                    print_ERR_FUNCTION(stored_fun, element->nature);
                                }
                                }
                                check_parameters(global_scope,stored_fun ,$3);
                               
                                ($1)->lex_value->type = TYPE_FUNC_CALL; $$ = add_node($1, $3); 
                                }
        ;
ParamsCall: %empty        { $$ = NULL; }
          | ParamCallList { $$ = $1;   }
          ;
ParamCallList: Expr                   { $$ = $1;               }
             | Expr ',' ParamCallList { $$ = add_node($1, $3); }
             ;

/* Global variable declaration */
GlobalVarDecl: TypeStatic GlobalVarList {  HashTable * table = top(global_scope);
                                            while(!isEmpty_stack_list(var_list)){
                                            hash_element* var = pop_element(&var_list);
                                            hash_element* element = hash_search(global_scope, var->name, true);
                                            if(element == NULL){
                                            hash_insert(&table, var, $1);
                                            }
                                            else{
                                                print_ERR_DECLARED(var ,element->line);
                                                }
                                            }
                                            var_list = NULL;
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
             HashTable * table = top(global_scope);
                                        while(!isEmpty_stack_list(var_list)){
                                            hash_element* var = pop_element(&var_list);
                                            hash_element * element = hash_search(global_scope, var->name, false);
                                            if(element == NULL){
                                            hash_insert(&table, var, $1);}
                                            else{
                                                print_ERR_DECLARED(var ,element->line);
                                            }
                                        }
                                        var_list = NULL;
             }
            ;
LocalVarList: LocalVar                  { $$ = $1;                                     }
            | LocalVar ',' LocalVarList { $$ = ($1) == NULL ? ($3) : add_node($1, $3); }
            ;
LocalVar: 
        TK_IDENTIFICADOR                      { store_identificador(&stored_element, $1); $$ = NULL;
                                                store_nature(&stored_element, NAT_VAR);
                                                push_element(&var_list, stored_element);}
        | ID TK_OC_LE IDArray { $$ = create_node(NAT_VAR,$2, 2, $1, $3);
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
        | ID TK_OC_LE Lit     { $$ = create_node(NAT_VAR,$2, 2, $1, $3); 
                                store_nature(&stored_element, NAT_VAR);
                                push_element(&var_list, stored_element);}
        ;

/***************
 * EXPRESSIONS *
 ***************/

Expr: UnaryExpr              { $$ = $1;                             }
    | UnarySet               { $$ = $1;                             }
    | Expr '+' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '-' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '*' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '/' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '%' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '|' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '&' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '^' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '<' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '>' Expr          { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_EQ Expr     { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_NE Expr     { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_LE Expr     { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_GE Expr     { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_AND Expr    { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr TK_OC_OR Expr     { $$ = create_node(EXP,$2, 2, $1, $3);     }
    | Expr '?' Expr ':' Expr { replace_name($2, "?:");
                               $$ = create_node(EXP,$2, 3, $1, $3, $5); }
    | '(' Expr ')'           { $$ = $2;                             }
    ;
UnaryExpr: IDArray  { $$ = $1; push_exp(&param_list, stored_IDArray);}
         | Lit      { $$ = $1; push_exp(&param_list, stored_literal);}
         | FuncCall { $$ = $1; push_exp(&param_list, stored_fun);}
         ;
UnarySet: '+' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '-' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '!' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '&' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '*' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '?' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '#' UnaryExpr UnarySet { $$ = create_node(EXP,$1, 1, $2, $3); }
        | '+' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '-' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '!' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '&' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '*' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '?' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        | '#' UnaryExpr          { $$ = create_node(EXP,$1, 1, $2);     }
        ;

/************
 * COMMANDS *
 ************/
CreateScope: '{' { push(&global_scope, hash_create());}
            ;
CreateFunScope: '{' { push(&global_scope, hash_create());
                            HashTable * table = top(global_scope);
                            while(!isEmpty_stack_list(param_list)){
                            hash_element* param_element = pop_element(&param_list);
                            hash_insert(&table, param_element, param_element->type);
                            }
                            param_list = NULL; }
            ;
DestroyScope: '}' {pop(&global_scope);}
                ;

Cmd: LocalVarDecl            { $$ = $1;                         }
   | Assignment              { $$ = $1;                         }
   | TK_PR_INPUT IDArray     { $$ = create_node(INP,$1, 1, $2);     
                              int ok = check_input_output(global_scope, stored_element);
                              if(ok != -1)
                              {
                                  print_ERR_WRONG_PAR_INPUT(stored_element, ok);
                              }}
   | TK_PR_OUTPUT IDArray    { $$ = create_node(OUT,$1, 1, $2);     
                                int ok = check_input_output(global_scope, stored_element);
                              if(ok != -1)
                              {
                                  print_ERR_WRONG_PAR_OUTPUT(stored_element, ok);
                              }}
   | TK_PR_OUTPUT Lit        { $$ = create_node(OUT,$1, 1, $2);     }
   | CmdBlock                { $$ = $1;                         }
   | FuncCall                { $$ = $1;                         }
   | IDArray TK_OC_SL Int    { $$ = create_node(SL,$2, 2, $1, $3); }
   | IDArray TK_OC_SR Int    { $$ = create_node(SR,$2, 2, $1, $3); }
   | TK_PR_RETURN Expr       { $$ = create_node(RET,$1, 1, $2);     
                                int line = top_element(param_list)->line;
                                int type =  check_exp_type(param_list, global_scope);
                                param_list = NULL;
                                if(type != stored_fundecl->type){
                                    if(!((type <=260) && (stored_fundecl->type <=260)))
                                    print_ERR_WRONG_PAR_RETURN(stored_fundecl,type, line);
                                }}
   | TK_PR_BREAK             { $$ = create_node(BREAK,$1, 0);         }
   | TK_PR_CONTINUE          { $$ = create_node(CONT,$1, 0);         }
   | ControlFlow             { $$ = $1;                         }
   ;
CmdBlock: CreateScope CmdSeq DestroyScope { $$ = $2;}
        ;

FunCmdBlock: CreateFunScope CmdSeq DestroyScope { $$ = $2;}
        ; 
CmdSeq: %empty          { $$ = NULL;                                   }
      | Cmd ';' CmdSeq  { $$ = ($1) == NULL ? ($3) : add_node($1, $3); }
      ;

 /*Assignment */
Assignment: IDArray '=' Expr { 
    $$ = create_node(ASS,$2, 2, $1, $3); 
    int IDtype = hash_search(global_scope, stored_IDArray->name, true)->type;
    int exp_type = check_exp_type(param_list, global_scope);
    if(IDtype == TK_PR_STRING && exp_type != TK_PR_STRING){
            print_ERR_STRING_TO_X(stored_IDArray->line, stored_IDArray->name, exp_type);  }
            
    else{
        if(IDtype != TK_PR_STRING && exp_type == TK_PR_STRING){
            print_ERR_STRING_TO_X(stored_IDArray->line, stored_IDArray->name, exp_type);}
    else{
        if(IDtype == TK_PR_CHAR && exp_type != TK_PR_CHAR){
            print_ERR_CHAR_TO_X(stored_IDArray->line, stored_IDArray->name, exp_type);
        }
    else{
             if(IDtype != exp_type){
             if(!((IDtype <=260) && (exp_type <=260))){
                print_ERR_WRONG_ASS_TYPE(stored_element->line, IDtype,exp_type);
        }}
    }}
    }
    param_list = NULL;
};

/* Control flow */
ControlFlow: If      { $$ = $1; }
           | For     { $$ = $1; }
           | While   { $$ = $1; }
           ;
If: TK_PR_IF '(' Expr ')' CmdBlock Else { $$ = create_node(FLOW,$1, 3, $3, $5, $6); }
  ;
Else: %empty              { $$ = NULL; }
    | TK_PR_ELSE CmdBlock { $$ = $2;   }
    ;
For: TK_PR_FOR '(' Assignment ':' Expr ':' Assignment ')' CmdBlock { $$ = create_node(FLOW,$1, 4, $3, $5, $7, $9); }
   ;
While: TK_PR_WHILE '(' Expr ')' TK_PR_DO CmdBlock { $$ = create_node(FLOW,$1, 2, $3, $6); }
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
