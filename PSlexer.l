%{
#include <stdio.h>
#include "tokens.h"
%}

%%
[0-9]*                      |
[0-9]*\.[0-9]*              {return 1;}
[A-Z|a-z]*                  {return 2;}
                            {return K_DO;}
                            {return K_DOUBLE;}
                            {return K_ELSE;}
                            {return K_EXIT;}
                            {return K_FUNCTION;}
                            {return K_IF;}
                            {return K_INTEGER;}
                            {return K_PRINT_DOUBLE;}
                            {return K_PRINT_INTEGER;}
                            {return K_PRINT_STRING;}
                            {return K_PROCEDURE;}
                            {return K_PROGRAM;}
                            {return K_READ_DOUBLE;}
                            {return K_READ_INTEGER;}
                            {return K_READ_STRING;}
                            {return K_RETURN;}
                            {return K_STRING;}
                            {return K_THEN;}
                            {return K_WHILE;}
                            {return ASSIGN;}
                            {return ASSIGN_PLUS;}
                            {return ASSIGN_MINUS;}
                            {return ASSIGN_MULTIPLY;}
                            {return ASSIGN_DIVIDE;}
                            {return ASSIGN_MOD;}
                            {return COMMA;}
                            {return COMMENT;}
                            {return DAND;}
                            {return DIVIDE;}
                            {return DOR;}
                            {return DEQ;}
                            {return GEQ;}
                            {return GT;}
                            {return LBRACKET;}
                            {return LEQ;}
                            {return LCURLY;}
                            {return LPAREN;}
                            {return LT;}
                            {return MINUS;}
                            {return DECREMENT;}
                            {return MOD;}
                            {return MULTIPLY;}
                            {return NE;}
                            {return NOT;}
                            {return PERIOD;}
                            {return PLUS;}
                            {return INCREMENT;}
                            {return RBRACKET;}
                            {return RCURLY;}
                            {return RPAREN;}
                            {return SEMI;}
                            {return IDENTIFIER;}
                            {return SCONSTANT;}
                            {return ICONSTANT;}
                            {return DCONSTANT;}
%%
int main(int argc, char **argv){
    int val;
    while (val==yylex())
        printf("Value is %d\n", val);
    return 0;
}