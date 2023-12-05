%{
#include "y.tab.h"
int line=1;

%}

%%
[ \t]                                                       ;
\/\/[^\r\n]*                                                ; // Comment
"do"                                                        {strcpy(yylval.nd_obj.name,(yytext)); return K_DO;}
"double"                                                    {strcpy(yylval.nd_obj.name,(yytext)); return K_DOUBLE;}
"else"                                                      {strcpy(yylval.nd_obj.name,(yytext)); return K_ELSE;}
"exit"                                                      {strcpy(yylval.nd_obj.name,(yytext)); return K_EXIT;}
"function"                                                  {strcpy(yylval.nd_obj.name,(yytext)); return K_FUNCTION;}
"if"                                                        {strcpy(yylval.nd_obj.name,(yytext)); return K_IF;}
"integer"                                                   {strcpy(yylval.nd_obj.name,(yytext)); return K_INTEGER;}
"print_double"                                              {strcpy(yylval.nd_obj.name,(yytext)); return K_PRINT_DOUBLE;}
"print_integer"                                             {strcpy(yylval.nd_obj.name,(yytext)); return K_PRINT_INTEGER;}
"print_string"                                              {strcpy(yylval.nd_obj.name,(yytext)); return K_PRINT_STRING;}
"procedure"                                                 {strcpy(yylval.nd_obj.name,(yytext)); return K_PROCEDURE;}
"program"                                                   {strcpy(yylval.nd_obj.name,(yytext)); return K_PROGRAM;}
"read_double"                                               {strcpy(yylval.nd_obj.name,(yytext)); return K_READ_DOUBLE;}
"read_integer"                                              {strcpy(yylval.nd_obj.name,(yytext)); return K_READ_INTEGER;}
"read_string"                                               {strcpy(yylval.nd_obj.name,(yytext)); return K_READ_STRING;}
"return"                                                    {strcpy(yylval.nd_obj.name,(yytext)); return K_RETURN;}
"string"                                                    {strcpy(yylval.nd_obj.name,(yytext)); return K_STRING;}
"then"                                                      {strcpy(yylval.nd_obj.name,(yytext)); return K_THEN;}
"while"                                                     {strcpy(yylval.nd_obj.name,(yytext)); return K_WHILE;}
-?((([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([dD][-+]?[0-9]+)?)   {strcpy(yylval.nd_obj.name,(yytext)); return DCONSTANT;}
[0-9]+                                                      {strcpy(yylval.nd_obj.name,(yytext)); return ICONSTANT;}
\"(\\.|[^"\\])*\"                                           {strcpy(yylval.nd_obj.name,(yytext)); return SCONSTANT;}
[A-Za-z0-9$_]{0,32}                                         {strcpy(yylval.nd_obj.name,(yytext)); return IDENTIFIER;}
:=                                                          {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN;}
\+=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN_PLUS;}
\-=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN_MINUS;}
\*=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN_MULTIPLY;}
\/=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN_DIVIDE;}
\%=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN_MOD;}
,                                                           {strcpy(yylval.nd_obj.name,(yytext)); return COMMA;}
&&                                                          {strcpy(yylval.nd_obj.name,(yytext)); return DAND;}
\/                                                          {strcpy(yylval.nd_obj.name,(yytext)); return DIVIDE;}
\|\|                                                        {strcpy(yylval.nd_obj.name,(yytext)); return DOR;}
==                                                          {strcpy(yylval.nd_obj.name,(yytext)); return DEQ;}
\>=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return GEQ;}
\>                                                          {strcpy(yylval.nd_obj.name,(yytext)); return GT;}
\[                                                          {strcpy(yylval.nd_obj.name,(yytext)); return LBRACKET;}
\<=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return LEQ;}
\{                                                          {strcpy(yylval.nd_obj.name,(yytext)); return LCURLY;}
\(                                                          {strcpy(yylval.nd_obj.name,(yytext)); return LPAREN;}
\<                                                          {strcpy(yylval.nd_obj.name,(yytext)); return LT;}
\-                                                          {strcpy(yylval.nd_obj.name,(yytext)); return MINUS;}
\-\-                                                        {strcpy(yylval.nd_obj.name,(yytext)); return DECREMENT;}
\%                                                          {strcpy(yylval.nd_obj.name,(yytext)); return MOD;}
\*                                                          {strcpy(yylval.nd_obj.name,(yytext)); return MULTIPLY;}
\!=                                                         {strcpy(yylval.nd_obj.name,(yytext)); return NE;}
\!                                                          {strcpy(yylval.nd_obj.name,(yytext)); return NOT;}
\.                                                          {strcpy(yylval.nd_obj.name,(yytext)); return PERIOD;}
\+                                                          {strcpy(yylval.nd_obj.name,(yytext)); return PLUS;}
\+\+                                                        {strcpy(yylval.nd_obj.name,(yytext)); return INCREMENT;}
\]                                                          {strcpy(yylval.nd_obj.name,(yytext)); return RBRACKET;}
\}                                                          {strcpy(yylval.nd_obj.name,(yytext)); return RCURLY;}
\)                                                          {strcpy(yylval.nd_obj.name,(yytext)); return RPAREN;}
;                                                           {strcpy(yylval.nd_obj.name,(yytext)); return SEMI;}
[\n]                                                        {line++;}
%%

int yywrap(){
    return 1;
}

