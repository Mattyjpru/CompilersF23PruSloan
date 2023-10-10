%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
%}
%union {
    double dVal;
    int iVal;
}


%token K_PROGRAM K_FUNCTION ICONSTANT K_PRINT_INTEGER K_PRINT_STRING IDENTIFIER K_INTEGER K_STRING 
%token LPAREN LCURLY RPAREN RCURLY COMMA ASSIGN SEMI SCONSTANT K_PROCEDURE
%left MINUS PLUS
//%left DIVIDE MULTIPLY

%%
statement: 
    prog { printf("Valid Program\n");
                  exit(0);  };

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    |
    K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    |
    K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    |
    K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    
    ;

prog: 
    K_PROGRAM IDENTIFIER LCURLY task RCURLY;

task: function
    | procedure
    | task function
    | task procedure
    ;

procedure:
    K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    |
    K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    ;

function: 
    K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    |
    K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    ;

var:
    d_type IDENTIFIER SEMI
    |
    d_type ass
    ;

ass:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    |
    IDENTIFIER ASSIGN SCONSTANT SEMI
    ;
    


d_type:
    K_INTEGER
    |
    K_STRING
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
    d_type IDENTIFIER
    |
    d_type IDENTIFIER COMMA param_list
    ;

block:
    expr block
    |
    print block
    |
    var block
    |
    ass block
    |
    expr
    |
    print
    |
    var
    |
    ass

    ;

epsilon: ;

%%
extern FILE* yyin ;



int main(int argc ,char** argv){
    do {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\nWalking through the Parse Tree Begins Here\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
