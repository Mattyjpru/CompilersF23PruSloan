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
    d_type IDENTIFIER SEMI
    |
    d_type ass
    |
    ;

ass:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    |
    IDENTIFIER ASSIGN SCONSTANT SEMI
    /* |
    IDENTIFIER ASSIGN DCONSTANT SEMI */
    ;
    


d_type:
    K_INTEGER
    |
    K_STRING
    ;

print:
    K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    |
    K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    |
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    |
    K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    ;

expr:
    expr MINUS expr
    |
    expr PLUS expr
    |
    K_INTEGER
    //eventually have conditions for double as well
    |
    LPAREN expr RPAREN
    ;


//################ TODO ##################
param_list:


function: K_FUNCTION d_type IDENTIFIER LPAREN RPAREN;
//############# Terminals ################


%%
extern FILE* yyin;

int yyerror(char *msg){
    printf("Invalid Program\n")
}

int main(int argc, char** argv){
    do {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n
        Walking through the Parse Tree Begins Here\n
        ++++++++++++++++++++++++++++++++++++++++++++++++\n")
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
