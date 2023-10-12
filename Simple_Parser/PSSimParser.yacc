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
}


%token K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT ICONSTANT DCONSTANT
%left MINUS PLUS
//%left DIVIDE MULTIPLY

%%
statement: 
    prog { printf("Valid Program\n");
                  exit(0);  };

prog: K_PROGRAM IDENTIFIER LCURLY task RCURLY
    {
        printf("Node %d: Reduced: program: K_PROGRAM IDENTIFIER LCURLY task RCURLY\n", nodeCount++);
        printf("Terminal Symbol: K_PROGRAM\n");
        printf("IDENTIFIER -> %s\n", $2);
        printf("Terminal Symbol: LCURLY\n");
        printf("task -> %s\n", $4);
        printf("Terminal Symbol: RCURLY\n");
    };

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

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    |
    K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    |
    K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    |
    K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
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
    {printf("Node %d: Reduced: Block: K_INTEGER\n", nodeCount++);
    printf("Terminal Symbol: %s", $1)}
    |
    K_STRING                    
    {printf("Node %d: Reduced: Block: K_STRING\n", nodeCount++);
    printf("Terminal Symbol: %s\n", $1)}
    ;



expr:
    expr MINUS expr             
    {printf("Node %d: Reduced: Block: expr MINUS expr\n", nodeCount++);
    printf("Terminal Symbol: %s\n", $1)}
    |
    expr PLUS expr              
    {printf("Node %d: Reduced: Block: expr PLUS expr\n", nodeCount++);
    }
    |
    K_INTEGER                   
    {printf("Node %d: Reduced: Block: K_INTEGER\n", nodeCount++);
    printf("Terminal Symbol: %s\n", $1)}
    //eventually have conditions for double as well
    |
    LPAREN expr RPAREN          
    {printf("Node %d: Reduced: Block: LPAREN expr RPAREN\n", nodeCount++);
    }
    ;


param_list:
    d_type IDENTIFIER                       
    {printf("Node %d: Reduced: Block: d_type IDENTIFIER\n", nodeCount++);
    }
    |
    d_type IDENTIFIER COMMA param_list      
    {printf("Node %d: Reduced: Block: d_type IDENTIFIER COMMA param_list\n", nodeCount++);
    }
    ;

block:
    expr block      
    {printf("Node %d: Reduced: Block: expr block\n", nodeCount++);
    }
    |
    print block     
    {printf("Node %d: Reduced: Block: print block\n", nodeCount++);
    }
    |
    var block       
    {printf("Node %d: Reduced: Block: var block\n", nodeCount++);
    }
    |
    ass block       
    {printf("Node %d: Reduced: Block: ass block\n", nodeCount++);
    }
    |
    expr            
    {printf("Node %d: Reduced: Block: expr\n", nodeCount++);
    }
    |
    print           
    {printf("Node %d: Reduced: Block: print\n", nodeCount++);
    }
    |
    var             
    {printf("Node %d: Reduced: Block: var\n", nodeCount++);
    }
    |
    ass             
    {printf("Node %d: Reduced: Block: ass\n", nodeCount++);
    }
    |
    epsilon     {printf("Block Exit")}
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
