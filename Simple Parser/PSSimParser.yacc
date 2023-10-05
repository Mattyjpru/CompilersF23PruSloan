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

/* %token K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE
%token K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE
%token K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE
%token ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE
%token ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET
%token LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD
%token PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT
%token ICONSTANT DCONSTANT */
%token K_PROGRAM, K_FUNCTION, ICONSTANT, K_PRINT_INTEGER, K_PRINT_STRING, IDENTIFIER, K_INTEGER, K_STRING
LPAREN, LCURLY, RPAREN, RCURLY, COMMA, ASSIGN, SEMI
%left MINUS PLUS
%left DIVIDE MULTIPLY

%%
statement: prog { printf("Valid Program\n");
                  exit(0);  };

prog: K_PROGRAM IDENTIFIER LBRACKET task RBRACKET;

task: function
    | procedure
    | task function
    | task procedure
    ;

var:
    K_INTEGER IDENTIFIER SEMI
    |
    K_INTEGER ass
    |
    K_STRING IDENTIFIER SEMI
    |
    K_STRING ass
    ;

ass:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    |
    IDENTIFIER ASSIGN SCONSTANT SEMI
    |
    IDENTIFIER ASSIGN DCONSTANT SEMI
    ;
    
ret_t:
    K_INTEGER
    |
    K_STRING
    |
    ;


################ TODO ##################
param_list:

function: K_FUNCTION ret_t IDENTIFIER LPAREN RPAREN;
%%
extern FILE* yyin;

int yyerror(char *msg){
    printf("Invalid Program\n")
}

int main(int argc, char** argv){
    do {
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
