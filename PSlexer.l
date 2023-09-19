%{
#include <stdio.h>
#include "PStokens.h"
#include <string.h>
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

%%
int main(int argc, char **argv){
    int val;
    while ((val=yylex()) != 0)
        printf("Value is %d\n", val);
    return 0;
}