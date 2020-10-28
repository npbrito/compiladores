 /* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "parser.tab.h"

int set_lex_value(int token)
{
    char *str;
    yylval.lex_value = (lexeme_t*)malloc(sizeof(lexeme_t));
    if (!yylval.lex_value) {
        return token;
    }
    memset(yylval.lex_value, 0, sizeof(lexeme_t));
    yylval.lex_value->type = token;
    yylval.lex_value->line = yylineno;
    switch (token) {
        case TK_LIT_INT:
            sscanf(yytext, "%d", &yylval.lex_value->val.d);
            break;
        case TK_LIT_FLOAT:
            sscanf(yytext, "%f", &yylval.lex_value->val.f);
            break;
        case TK_LIT_TRUE:
        case TK_LIT_FALSE:
            yylval.lex_value->val.b = token == TK_LIT_TRUE;
            break;
        case TK_LIT_CHAR:
            str = strdup(yytext+1);
            str[strlen(str)-1] = '\0';
            yylval.lex_value->val.c = str;
            break;
        case TK_LIT_STRING:
            str = strdup(yytext+1);
            str[strlen(str)-1] = '\0';
            yylval.lex_value->val.s = str;
            break;
        default:
            yylval.lex_value->name = strdup(yytext);
            break;
    }
    return token;
}

%}

%option yylineno
%x multilinecomment

/* Auxiliary definitions */
ALPHABETIC   [a-zA-Z_]
NUMERIC      [0-9]
ALPHANUMERIC {NUMERIC}|{ALPHABETIC}
SIGN         [-+]

/* Literals definitions */
INTEGER   {NUMERIC}+
FLOAT     {INTEGER}\.{INTEGER}([eE]{SIGN}?{INTEGER})?
CHARACTER '[^'\n]'
STRING    \"[^"\n]*\"
STRINGLF  \"[^"]*\n

/* Others */
IDENTIFIER {ALPHABETIC}{ALPHANUMERIC}*


%%

    /* Reserved keywords */
"int"       { return TK_PR_INT;                     }
"float"     { return TK_PR_FLOAT;                   }
"bool"      { return TK_PR_BOOL;                    }
"char"      { return TK_PR_CHAR;                    }
"string"    { return TK_PR_STRING;                  }
"if"        { return set_lex_value(TK_PR_IF);       }
"then"      { return TK_PR_THEN;                    }
"else"      { return TK_PR_ELSE;                    }
"while"     { return set_lex_value(TK_PR_WHILE);    }
"do"        { return TK_PR_DO;                      }
"input"     { return set_lex_value(TK_PR_INPUT);    }
"output"    { return set_lex_value(TK_PR_OUTPUT);   }
"return"    { return set_lex_value(TK_PR_RETURN);   }
"const"     { return TK_PR_CONST;                   }
"static"    { return TK_PR_STATIC;                  }
"foreach"   { return TK_PR_FOREACH;                 }
"for"       { return set_lex_value(TK_PR_FOR);      }
"switch"    { return TK_PR_SWITCH;                  }
"case"      { return TK_PR_CASE;                    }
"break"     { return set_lex_value(TK_PR_BREAK);    }
"continue"  { return set_lex_value(TK_PR_CONTINUE); }
"class"     { return TK_PR_CLASS;                   }
"private"   { return TK_PR_PRIVATE;                 }
"public"    { return TK_PR_PUBLIC;                  }
"protected" { return TK_PR_PROTECTED;               }
"end"       { return TK_PR_END;                     }
"default"   { return TK_PR_DEFAULT;                 }

    /* Composite operators */
"<=" { return set_lex_value(TK_OC_LE);  }
">=" { return set_lex_value(TK_OC_GE);  }
"==" { return set_lex_value(TK_OC_EQ);  }
"!=" { return set_lex_value(TK_OC_NE);  }
"&&" { return set_lex_value(TK_OC_AND); }
"||" { return set_lex_value(TK_OC_OR);  }
"<<" { return set_lex_value(TK_OC_SL);  }
">>" { return set_lex_value(TK_OC_SR);  }

    /* Comment handling */
"//"[^\n]*
"/*" BEGIN(multilinecomment);
<multilinecomment>[^*]*
<multilinecomment>"*"+[^*/\n]*
<multilinecomment>"*"+"/" { BEGIN(INITIAL); }

    /* Special characters */
[-!#%&*+/<=>?^[|] { return set_lex_value(yytext[0]); }
[]$(),.:;@\`{}~]  { return yytext[0]; }

    /* Literals */
{INTEGER}   { return set_lex_value(TK_LIT_INT);    }
{FLOAT}     { return set_lex_value(TK_LIT_FLOAT);  }
"true"      { return set_lex_value(TK_LIT_TRUE);   }
"false"     { return set_lex_value(TK_LIT_FALSE);  }
{CHARACTER} { return set_lex_value(TK_LIT_CHAR);   }
{STRING}    { return set_lex_value(TK_LIT_STRING); }

    /* Identifier */
{IDENTIFIER} { return set_lex_value(TK_IDENTIFICADOR); }

    /* Ignore separators */
[ \t\r\n]*

    /* Catch errors */
({INTEGER}|{FLOAT}){ALPHABETIC}* { return TOKEN_ERRO; }
{STRINGLF} { return TOKEN_ERRO; }

    /* If didn't match anything, return error */
. { return TOKEN_ERRO; }


%%
