%{
#include <stdio.h>
#include "PStokens.h"
#include <string.h>

union{
    int iVal;
    double dVal;
    char* sVal;
} yylval;

%}

%%
[" "|\t|\n]                ;
"do"                       return K_DO;
"double"                   return K_DOUBLE;
"else"                     return K_ELSE;
"exit"                     return K_EXIT;
"function"                 return K_FUNCTION;
"if"                       return K_IF;
"integer"                  return K_INTEGER;
"print_double"             return K_PRINT_DOUBLE;
"print_integer"            return K_PRINT_INTEGER;
"print_string"             return K_PRINT_STRING;
"procedure"                return K_PROCEDURE;
"program"                  return K_PROGRAM;
"read_double"              return K_READ_DOUBLE;
"read_integer"             return K_READ_INTEGER;
"read_string"              return K_READ_STRING;
"return"                   return K_RETURN;
"string"                   return K_STRING;
"then"                     return K_THEN;
"while"                    return K_WHILE;
:=                         return ASSIGN;
\+=                         return ASSIGN_PLUS;
-=                         return ASSIGN_MINUS;
\*=                         return ASSIGN_MULTIPLY;
\/=                         return ASSIGN_DIVIDE;
%=                         return ASSIGN_MOD;
,                          return COMMA;
\/\/                       return COMMENT;
&&                         return DAND;
\/                          return DIVIDE;
\|\|                         return DOR;
==                         return DEQ;
>=                         return GEQ;
>                          return GT;
\[                         return LBRACKET;
<=                         return LEQ;
\{                         return LCURLY;
(                          return LPAREN;
<                          return LT;
-                          return MINUS;
--                         return DECREMENT;
%                         return MOD;
*                         return MULTIPLY;
!=                         return NE;
!                          return NOT;
.                          return PERIOD;
+                          return PLUS;
+\+                         return INCREMENT;
]                         return RBRACKET;
}                         return RCURLY;
)                         return RPAREN;
;                         return SEMI;

−?(([0-9]+)|(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([dD][−+]?[0-9]+)?                         return DCONSTANT;

[A-Za-z0-9$_]{32}                                     return IDENTIFIER;
                                                     //return SCONSTANT;
[0-9]*                                               return ICONSTANT;

%%
int main(int argc, char **argv){
    int token;
    printf("Token:\t\tMatch:\n");
    while ((token=yylex()) != 0){
        printf("%d\t\t%s\n", token, yytext);
    }
    return 0;
}