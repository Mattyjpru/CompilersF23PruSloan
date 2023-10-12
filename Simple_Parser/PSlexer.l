%{
#include "y.tab.h"
#include <string.h>
%}

%%
[ \t\n\r]                                                       ;
"function"                      {printf("FUNCTION-> %s\n",yytext); 
                                return K_FUNCTION;}
"integer"                       {printf("INTEGER-> %s\n",yytext);
                                return K_INTEGER;}
"print_integer"                 {printf("PRINT_INT-> %s\n",yytext);
                                return K_PRINT_INTEGER;}
"print_string"                  {printf("PRINT_STR-> %s\n",yytext);
                                return K_PRINT_STRING;}
"procedure"                     {printf("PROCEDURE-> %s\n",yytext);
                                return K_PROCEDURE;}
"program"                       {printf("PROGRAM-> %s\n",yytext);
                                return K_PROGRAM;}
"string"                        {printf("STRING-> %s\n",yytext);
                                return K_STRING;}
[0-9]*                          {printf("ICONSTANT-> %s\n",yytext);
                                return ICONSTANT;}
\"(\\.|[^"\\])*\"               {printf("SCONSTANT-> %s\n",yytext);
                                return SCONSTANT;}
[A-Za-z0-9$_]{0,32}             {printf("IDENTIFIER-> %s\n",yytext);
                                return IDENTIFIER;}
:=                              {printf("ASSIGNMENT-> %s\n",yytext);
                                return ASSIGN;}
,                               {printf("COMMA-> %s\n",yytext);
                                return COMMA;}
\{                              {printf("LCURLY-> %s\n",yytext);
                                return LCURLY;}
\(                              {printf("LPAREN-> %s\n",yytext);
                                return LPAREN;}
\-                              {printf("MINUS-> %s\n",yytext);
                                return MINUS;}
\+                              {printf("PLUS-> %s\n",yytext);
                                return PLUS;}
\}                              {printf("RCURLY-> %s\n",yytext);
                                return RCURLY;}
\)                              {printf("RPAREN-> %s\n",yytext);
                                return RPAREN;}
;                               {printf("SEMI-> %s\n",yytext);
                                return SEMI;}
%%

int yywrap(){
    return 1;
}

