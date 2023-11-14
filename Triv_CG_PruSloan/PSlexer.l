%{
#include "y.tab.h"
int line=1;
char* repD(char* str, char target){
    char* here=strchr(str,target);
    while(here){
        *here='e';
        here=strchr(here, target);
    }
    return str;
}

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
-?((([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([dD][-+]?[0-9]+)?)   {strcpy(yylval.nd_obj.dt,(yytext)); return DCONSTANT;}
[0-9]+                                                      {strcpy(yylval.nd_obj.dt,(yytext)); return ICONSTANT;}
\"(\\.|[^"\\])*\"                                           {strcpy(yylval.nd_obj.dt,(yytext)); return SCONSTANT;}
[A-Za-z0-9$_]{0,32}                                         {strcpy(yylval.nd_obj.dt,(yytext)); return IDENTIFIER;}
:=                                                          {strcpy(yylval.nd_obj.name,(yytext)); return ASSIGN;}
\+=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn ASSIGN_PLUS;}
\-=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn ASSIGN_MINUS;}
\*=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn ASSIGN_MULTIPLY;}
\/=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn ASSIGN_DIVIDE;}
\%=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn ASSIGN_MOD;}
,                                                           {strcpy(yylval.nd_obj.name,(yytext)); sreturn COMMA;}
&&                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn DAND;}
\/                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn DIVIDE;}
\|\|                                                        {strcpy(yylval.nd_obj.name,(yytext)); sreturn DOR;}
==                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn DEQ;}
\>=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn GEQ;}
\>                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn GT;}
\[                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn LBRACKET;}
\<=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn LEQ;}
\{                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn LCURLY;}
\(                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn LPAREN;}
\<                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn LT;}
\-                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn MINUS;}
\-\-                                                        {strcpy(yylval.nd_obj.name,(yytext)); sreturn DECREMENT;}
\%                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn MOD;}
\*                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn MULTIPLY;}
\!=                                                         {strcpy(yylval.nd_obj.name,(yytext)); sreturn NE;}
\!                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn NOT;}
\.                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn PERIOD;}
\+                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn PLUS;}
\+\+                                                        {strcpy(yylval.nd_obj.name,(yytext)); sreturn INCREMENT;}
\]                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn RBRACKET;}
\}                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn RCURLY;}
\)                                                          {strcpy(yylval.nd_obj.name,(yytext)); sreturn RPAREN;}
;                                                           {strcpy(yylval.nd_obj.name,(yytext)); sreturn SEMI;}
[\n]                                                        {line++;}
%%

int yywrap(){
    return 1;
}

