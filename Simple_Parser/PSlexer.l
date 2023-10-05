%{
#include "y.tab.h"
#include <string.h>
%}

%%
[ \t\n\r]                                                       ;
"function"                                                  return K_FUNCTION;
"integer"                                                   return K_INTEGER;
"print_integer"                                             return K_PRINT_INTEGER;
"print_string"                                              return K_PRINT_STRING;
"procedure"                                                 return K_PROCEDURE;
"program"                                                   return K_PROGRAM;
"string"                                                    return K_STRING;
[A-Za-z0-9$_]{0,32}                                         return IDENTIFIER;
[0-9]*                                                      return ICONSTANT;
"\""([^\n\"\\]*(\\[.\n])*)*"\""                             return SCONSTANT;
:=                                                          return ASSIGN;
,                                                           return COMMA;
\{                                                          return LCURLY;
\(                                                          return LPAREN;
\-                                                          return MINUS;
\+                                                          return PLUS;
\}                                                          return RCURLY;
\)                                                          return RPAREN;
;                                                           return SEMI;
%%

int yywrap(){
    return 1;
}
// int main(int argc, char **argv){
//     int token;
//     printf("Token:\t\tMatch:\n");
//     while ((token=yylex()) != 0){
//         printf("%d\t\t%s\n", token, yytext);
//     }
//     return 0;
// }