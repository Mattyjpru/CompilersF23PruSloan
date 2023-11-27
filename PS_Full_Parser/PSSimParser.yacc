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
    int iVal;
    double dVal;
    char  *sVal;
}

%type<sVal> IDENTIFIER SCONSTANT expr param_list block d_type var assignment task function procedure print
%type<iVal> ICONSTANT
%type<dVal> DCONSTANT

%token K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT ICONSTANT DCONSTANT
%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement

%%
statement: 
    program { printf("Valid Program\n");
                  exit(0);  };

program: K_PROGRAM IDENTIFIER LCURLY task RCURLY
    {
        printf("Node %d: Reduced: program: K_PROGRAM IDENTIFIER LCURLY task RCURLY\n", nodeCount++);
        printf("\t Terminal Symbol: K_PROGRAM\n");
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t task -> %s\n", $4);
        printf("\t Terminal Symbol: RCURLY\n");
    };

task: function
    {
        printf("Node %d: Reduced: task: function\n", nodeCount++);
        printf("\t function -> %s\n", $1);
        $$ = "function";
    }
    | procedure
    {
        printf("Node %d: Reduced: task: procedure\n", nodeCount++);
        printf("\t procedure -> %s\n", $1);
        $$ = "procedure";
    }
    | task function
    {
        printf("Node %d: Reduced: task: task function\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t function -> %s\n", $2);
        $$ = "task function";
    }
    | task procedure
    {
        printf("Node %d: Reduced: task: task procedure\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t procedure -> %s\n", $2);
        $$ = "task procedure";
    }
    ;

procedure:
    K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PROCEDURE\n");
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t param_list -> %s\n", $4);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $7);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY";
    }
    |
    K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: procedure: K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PROCEDURE\n");
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $6);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY";
    }
    ;

function: 
    K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: function: K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_FUNCTION\n");
        printf("\t d_type -> %s\n", $2);
        printf("\t IDENTIFIER -> %s\n", $3);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t param_list -> %s\n", $5);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $8);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY";
    }
    |
    K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        printf("Node %d: Reduced: function: K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_FUNCTION\n");
        printf("\t d_type -> %s\n", $2);
        printf("\t IDENTIFIER -> %s\n", $3);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $7);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY";
    }
    ;

block:
    print           
    {
        printf("Node %d: Reduced: block: print\n", nodeCount++);
        printf("\t print -> %s\n", $1);
        $$ = "print";
    }
    |
    var             
    {
        printf("Node %d: Reduced: block: var\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        $$ = "var";
    }
    |
    assignment             
    {
        printf("Node %d: Reduced: block: assignment\n", nodeCount++);
        printf("\assignment -> %s\n", $1);
        $$ = "assignment";
    }
    |
    print block     
    {
        printf("Node %d: Reduced: block: print block\n", nodeCount++);
        printf("\t print -> %s\n", $1);
        printf("\t block -> %s\n", $2);
        $$ = "print block";
    }
    |
    var block       
    {
        printf("Node %d: Reduced: block: var block\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t block -> %s\n", $2);
        $$ = "var block";
    }
    |
    assignment block       
    {
        printf("Node %d: Reduced: block: assignment block\n", nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t block -> %s\n", $2);
        $$ = "assignment block";
    }
    |
    epsilon     {printf("\t block Exit"); $$ = "epsilon";}
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t ICONSTANT -> %d\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI";
    }
    |
    K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t SCONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI";
    }
    |
    K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t IDENTIFIER -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI";
    }
    |
    K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t IDENTIFIER -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI";
    }
    |
    K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN expr RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\expr -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN expr RPAREN SEMI";
    }
    ;

var:
    d_type IDENTIFIER SEMI
    {
        printf("Node %d: Reduced: var: d_type IDENTIFIER SEMI\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "d_type IDENTIFIER SEMI";
    }
    |
    d_type assignment
    {
        printf("Node %d: Reduced: var: d_type assignment\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t assignment -> %s\n", $2);
        $$ = "d_type assignment";
    }
    ;

assignment:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    {
        printf("Node %d: Reduced: assignment: IDENTIFIER ASSIGN ICONSTANT SEMI\n", 
        nodeCount++);
        printf("\t IDENTIFIER -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t ICONSTANT -> %d\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "IDENTIFIER ASSIGN ICONSTANT SEMI";
    }
    |
    IDENTIFIER ASSIGN SCONSTANT SEMI
    {
        printf("Node %d: Reduced: assignment: IDENTIFIER ASSIGN SCONSTANT SEMI\n", 
        nodeCount++);
        printf("\t IDENTIFIER -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t SCONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "IDENTIFIER ASSIGN SCONSTANT SEMI";
    }
    |
    IDENTIFIER ASSIGN expr SEMI
    {
        printf("Node %d: Reduced: assignment: IDENTIFIER ASSIGN expr SEMI\n", 
        nodeCount++);
        printf("\t IDENTIFIER -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "IDENTIFIER ASSIGN expr SEMI";
    }
    ;
    

d_type:
    K_INTEGER                   
    {
        printf("Node %d: Reduced: d_type: K_INTEGER\n", nodeCount++);
        printf("\t Terminal Symbol: K_INTEGER\n");
        $$ = "K_INTEGER";
    }
    |
    K_STRING                    
    {
        printf("Node %d: Reduced: d_type: K_STRING\n", nodeCount++);
        printf("\t Terminal Symbol: K_STRING\n");
        $$ = "K_STRING";
    }
    ;

expr:
    ICONSTANT                   
    {
        printf("Node %d: Reduced: expr: ICONSTANT\n", nodeCount++);
        printf("\t Terminal Symbol: ICONSTANT\n");
        $$ = "ICONSTANT";
    }
    |
    IDENTIFIER
    {
        printf("Node %d: Reduced: expr: IDENTIFIER\n", nodeCount++);
        printf("IDENTIFIER -> %s\n", $1);
        $$ = "IDENTIFIER";
    }
    |
    expr MINUS expr             
    {
        printf("Node %d: Reduced: expr: expr MINUS expr\n", nodeCount++);
        printf("\t expr-> %s\n", $1);
        printf("\t Terminal Symbol: MINUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MINUS expr";
    }
    |
    expr PLUS expr              
    {
        printf("Node %d: Reduced: expr: expr PLUS expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: PLUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr PLUS expr";
    }
    |
    LPAREN expr RPAREN          
    {
        printf("Node %d: Reduced: expr: LPAREN expr RPAREN\n", nodeCount++);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t expr -> %s\n", $2);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "LPAREN expr RPAREN";
    }
    ;


param_list:
    d_type IDENTIFIER                       
    {
        printf("Node %d: Reduced: param_list: d_type IDENTIFIER\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t IDENTIFIER -> %s\n", $2);
        $$ = "d_type IDENTIFIER";
    }
    |
    d_type IDENTIFIER COMMA param_list      
    {
        printf("Node %d: Reduced: param_list: d_type IDENTIFIER COMMA param_list\n",
        nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: COMMA\n");
        printf("\t param_list -> %s\n", $4);
        $$ = "d_type IDENTIFIER COMMA param_list";
    }
    ;

epsilon: ;

%%
extern FILE* yyin;

int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
