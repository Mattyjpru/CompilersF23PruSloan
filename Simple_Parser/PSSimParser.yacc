%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
    int nodeCount = 0;
%}
%union {
    double dVal;
    int iVal;
    char* sVal;
}

%type<sVal> IDENTIFIER SCONSTANT expr param_list block d_type var ass task function procedure print
%type<iVal> ICONSTANT
%type<dVal> DCONSTANT

%token K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT ICONSTANT DCONSTANT
%left MINUS PLUS
//%left DIVIDE MULTIPLY

%%
statement: 
    program { printf("Valid Program\n");
                  exit(0);  };

program: K_PROGRAM IDENTIFIER LCURLY task RCURLY
    {
        printf("Node %d: Reduced: program: K_PROGRAM IDENTIFIER LCURLY task RCURLY\n", nodeCount++);
        printf("\tTerminal Symbol: K_PROGRAM\n");
        printf("\tIDENTIFIER -> %s\n", $2);
        printf("\tTerminal Symbol: LCURLY\n");
        printf("\ttask -> %s\n", $4);
        printf("\tTerminal Symbol: RCURLY\n");
    };

task: function
    {
        printf("Node %d: Reduced: task: function\n", nodeCount++);
        printf("\tfunction -> %s\n", $1);
    }
    | procedure
    {
        printf("Node %d: Reduced: task: procedure\n", nodeCount++);
        printf("\tprocedure -> %s\n", $1);
    }
    | task function
    {
        printf("Node %d: Reduced: task: task function\n", nodeCount++);
        printf("\ttask -> %s\n", $1);
        printf("\tfunction -> %s\n", $2);
    }
    | task procedure
    {
        printf("Node %d: Reduced: task: task procedure\n", nodeCount++);
        printf("\ttask -> %s\n", $1);
        printf("\tprocedure -> %s\n", $2);
    }
    ;

procedure:
    K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PROCEDURE\n");
        printf("\tIDENTIFIER -> %s\n", $2);
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tparam_list -> %s\n", $4);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: LCURLY\n");
        printf("\tblock -> %s\n", $7);
        printf("\tTerminal Symbol: RCURLY\n");
    }
    |
    K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: procedure: K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PROCEDURE\n");
        printf("\tIDENTIFIER -> %s\n", $2);
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: LCURLY\n");
        printf("\tblock -> %s\n", $6);
        printf("\tTerminal Symbol: RCURLY\n");
    }
    ;

function: 
    K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: function: K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_FUNCTION\n");
        printf("\td_type -> %s\n", $2);
        printf("\tIDENTIFIER -> %s\n", $3);
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tparam_list -> %s\n", $5);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: LCURLY\n");
        printf("\tblock -> %s\n", $8);
        printf("\tTerminal Symbol: RCURLY\n");
    }
    |
    K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: function: K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_FUNCTION\n");
        printf("\td_type -> %s\n", $2);
        printf("\tIDENTIFIER -> %s\n", $3);
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: LCURLY\n");
        printf("\tblock -> %s\n", $7);
        printf("\tTerminal Symbol: RCURLY\n");
    }
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PRINT_INTEGER\n");
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tICONSTANT -> %d\n", $3);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: SEMI\n");
    }
    |
    K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PRINT_STRING\n");
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tSCONSTANT -> %s\n", $3);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: SEMI\n");
    }
    |
    K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PRINT_INTEGER\n");
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tIDENTIFIER -> %s\n", $3);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: SEMI\n");
    }
    |
    K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\tTerminal Symbol: K_PRINT_STRING\n");
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\tIDENTIFIER -> %s\n", $3);
        printf("\tTerminal Symbol: RPAREN\n");
        printf("\tTerminal Symbol: SEMI\n");
    }
    ;

var:
    d_type IDENTIFIER SEMI
    {
        printf("Node %d: Reduced: var: d_type IDENTIFIER SEMI\n", nodeCount++);
        printf("\td_type -> %s\n", $1);
        printf("\tIDENTIFIER -> %s\n", $2);
        printf("\tTerminal Symbol: SEMI\n");
    }
    |
    d_type ass
    {
        printf("Node %d: Reduced: var: d_type ass\n", nodeCount++);
        printf("\td_type -> %s\n", $1);
        printf("\tass -> %s\n", $2);
    }
    ;

ass:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    {
        printf("Node %d: Reduced: ass: IDENTIFIER ASSIGN ICONSTANT SEMI\n", 
        nodeCount++);
        printf("\tIDENTIFIER -> %s\n", $1);
        printf("\tTerminal Symbol: ASSIGN\n");
        printf("\tICONSTANT -> %d\n", $3);
        printf("\tTerminal Symbol: SEMI\n");
    }
    |
    IDENTIFIER ASSIGN SCONSTANT SEMI
    {
        printf("Node %d: Reduced: ass: IDENTIFIER ASSIGN SCONSTANT SEMI\n", 
        nodeCount++);
        printf("\tIDENTIFIER -> %s\n", $1);
        printf("\tTerminal Symbol: ASSIGN\n");
        printf("\tSCONSTANT -> %s\n", $3);
        printf("\tTerminal Symbol: SEMI\n");
    }
    ;
    

d_type:
    K_INTEGER                   
    {
        printf("Node %d: Reduced: d_type: K_INTEGER\n", nodeCount++);
        printf("\tTerminal Symbol: K_INTEGER\n");
    }
    |
    K_STRING                    
    {
        printf("Node %d: Reduced: d_type: K_STRING\n", nodeCount++);
        printf("\tTerminal Symbol: K_STRING\n");
    }
    ;



expr:
    expr MINUS expr             
    {
        printf("Node %d: Reduced: expr: expr MINUS expr\n", nodeCount++);
        printf("\texpr-> %s\n", $1);
        printf("\tTerminal Symbol: MINUS\n");
        printf("\texpr -> %s\n", $3);
    }
    |
    expr PLUS expr              
    {
        printf("Node %d: Reduced: expr: expr PLUS expr\n", nodeCount++);
        printf("\texpr-> %s\n",$1);
        printf("\tTerminal Symbol: PLUS\n");
        printf("\texpr -> %s\n", $3);
    }
    |
    K_INTEGER                   
    {
        printf("Node %d: Reduced: expr: K_INTEGER\n", nodeCount++);
        printf("\tTerminal Symbol: K_INTEGER\n");
    }
    //eventually have conditions for double as well
    |
    LPAREN expr RPAREN          
    {
        printf("Node %d: Reduced: expr: LPAREN expr RPAREN\n", nodeCount++);
        printf("\tTerminal Symbol: LPAREN\n");
        printf("\texpr -> %s\n", $2);
        printf("\tTerminal Symbol: RPAREN\n");
    }
    ;


param_list:
    d_type IDENTIFIER                       
    {
        printf("Node %d: Reduced: param_list: d_type IDENTIFIER\n", nodeCount++);
        printf("\td_type -> %s\n", $1);
        printf("\tIDENTIFIER -> %s\n", $2);
    }
    |
    d_type IDENTIFIER COMMA param_list      
    {
        printf("Node %d: Reduced: param_list: d_type IDENTIFIER COMMA param_list\n",
        nodeCount++);
        printf("\td_type -> %s\n", $1);
        printf("\tIDENTIFIER -> %s\n", $2);
        printf("\tTerminal Symbol: COMMA\n");
        printf("\tparam_list -> %s\n", $4);
    }
    ;

block:
    expr block      
    {
        printf("Node %d: Reduced: block: expr block\n", nodeCount++);
        printf("\texpr -> %s\n", $1);
        printf("\tblock -> %s\n", $2);
    }
    |
    print block     
    {
        printf("Node %d: Reduced: block: print block\n", nodeCount++);
        printf("\tprint -> %s\n", $1);
        printf("\tblock -> %s\n", $2);
    }
    |
    var block       
    {
        printf("Node %d: Reduced: block: var block\n", nodeCount++);
        printf("\tvar -> %s\n", $1);
        printf("\tblock -> %s\n", $2);
    }
    |
    ass block       
    {
        printf("Node %d: Reduced: block: ass block\n", nodeCount++);
        printf("\tass -> %s\n", $1);
        printf("\tblock -> %s\n", $2);
    }
    |
    expr            
    {
        printf("Node %d: Reduced: block: expr\n", nodeCount++);
        printf("\texpr -> %s\n", $1);
    }
    |
    print           
    {
        printf("Node %d: Reduced: block: print\n", nodeCount++);
        printf("\tprint -> %s\n", $1);
    }
    |
    var             
    {
        printf("Node %d: Reduced: block: var\n", nodeCount++);
        printf("\tvar -> %s\n", $1);
    }
    |
    ass             
    {
        printf("Node %d: Reduced: block: ass\n", nodeCount++);
        printf("\tass -> %s\n", $1);
    }
    |
    epsilon     {printf("\tblock Exit");}
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
