%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lex.yy.c"
    void yyerror(const char *s);
%}
%union {
    double dVal;
    int iVal;
}

%token K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE
%token K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE
%token K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE
%token ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE
%token ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET
%token LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD
%token PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT
%token ICONSTANT DCONSTANT
%left MINUS PLUS
%left DIVIDE MULTIPLY

%%

%%
extern FILE* yyin;

int main(int argc, char** argv){
    do {
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
