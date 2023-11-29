%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "lex.yy.c"

    extern int line;
    int yyerror(char *msg){
        printf("Invalid Program: %s on line %d\n", msg, line);
        exit(0);
    }

    int yylex();
    int nodeCount = 0;
    int yywrap();
    
    int SI = 0;
    int IR = 1;
    int FR = 1;

%}

%union {
    // struct nt1 { 
	// 	char name[100];
    //     // char dt[100];
	// 	struct node* nd;
	// } nd_obj; 
        int iVal;
    double dVal;
    char  *sVal;
}

%token<sVal> IDENTIFIER ICONSTANT DCONSTANT SCONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER 
%token<sVal> K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER
%token<sVal> K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token<sVal> ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS 
%token<sVal> DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI

%type<sVal> statement program expr param_list block d_type var assignment task function procedure print value
%type<sVal> if ret chain chainend makenummutable reader callfunc arrayat gate relop forloop whileloop happyruben buildarr

%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement 

%%
statement: 
    program { printf("\nValid Program\n");};

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
    | function task
    {
        printf("Node %d: Reduced: task: task function\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t function -> %s\n", $2);
        $$ = "task function";
    }
    | procedure task  
    {
        printf("Node %d: Reduced: task: task procedure\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t procedure -> %s\n", $2);
        $$ = "task procedure";
    };

procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
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
    };

function: K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
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
    };

block:
    print
    {
        printf("Node %d: Reduced: block: print\n", nodeCount++);
        printf("\t print -> %s\n", $1);
        $$ = "print";
    }          
    | var SEMI
    {
        printf("Node %d: Reduced: block: var SEMI\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "var SEMI";
    }
    | callfunc SEMI
    {
        printf("Node %d: Reduced: block: callfunc SEMI\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "callfunc SEMI";
    }  
    | assignment SEMI
    {
        printf("Node %d: Reduced: block: assignment SEMI\n", nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "assignment SEMI";
    }   
    | if
    {
        printf("Node %d: Reduced: block: if\n", nodeCount++);
        printf("\t if -> %s\n", $1);
        $$ = "if";
    }      
    | ret
    {
        printf("Node %d: Reduced: block: ret\n", nodeCount++);
        printf("\t ret -> %s\n", $1);
        $$ = "ret";
    }     
    | forloop
    {
        printf("Node %d: Reduced: block: forloop\n", nodeCount++);
        printf("\t forloop -> %s\n", $1);
        $$ = "forloop";
    }     
    | whileloop
    {
        printf("Node %d: Reduced: block: whileloop\n", nodeCount++);
        printf("\t whileloop -> %s\n", $1);
        $$ = "whileloop";
    }     
    | reader SEMI
    {
        printf("Node %d: Reduced: block: reader SEMI\n", nodeCount++);
        printf("\t reader -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "reader SEMI";
    } 
    | task
    {
        printf("Node %d: Reduced: block: task\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        $$ = "task";
    }     
    | LCURLY block RCURLY
    {
        printf("Node %d: Reduced: block: LCURLY block RCURLY\n", nodeCount++);
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $2);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "LCURLY block RCURLY";
    } 
    | block block 
    | IDENTIFIER makenummutable SEMI 
    | chain SEMI   
    {
        printf("Node %d: Reduced: block: chain SEMI\n", nodeCount++);
        printf("\t chain -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "chain SEMI";
    }    
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI 
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t ICONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI";
    }
    | K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_DOUBLE\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t DCONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI";
    }
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
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
    | K_PRINT_INTEGER LPAREN happyruben RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t happyruben -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN happyruben RPAREN SEMI";
    }
    | K_PRINT_DOUBLE LPAREN happyruben RPAREN SEMI
    {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t happyruben -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN happyruben RPAREN SEMI";
    }
    | K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
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
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
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
    d_type happyruben 
    {
        printf("Node %d: Reduced: var: d_type happyruben\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t happyruben -> %s\n", $2);
        
        $$ = "d_type happyruben";
    }
    | d_type buildarr
    {
        printf("Node %d: Reduced: var: d_type buildarr\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t buildarr -> %s\n", $2);
        
        $$ = "d_type buildarr";
    }
    | d_type assignment
    {
        printf("Node %d: Reduced: var: d_type assignment\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t assignment -> %s\n", $2);
        $$ = "d_type assignment";
    }
    | var SEMI
    {
        printf("Node %d: Reduced: block: var SEMI\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "var SEMI";
    } 
    ;

assignment:
    happyruben ASSIGN expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN expr SEMI";
    }
    | happyruben ASSIGN_DIVIDE expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN_DIVIDE expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_DIVIDE\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN_DIVIDE expr SEMI";
    }
    | happyruben ASSIGN_MINUS expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN_MINUS expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MINUS\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN_MINUS expr SEMI";
    }
    | happyruben ASSIGN_MOD expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN_MOD expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MOD\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN_MOD expr SEMI";
    }
    | happyruben ASSIGN_MULTIPLY expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN_MULTIPLY expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MULTIPLY\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN_MULTIPLY expr SEMI";
    }
    | happyruben ASSIGN_PLUS expr 
    {
        printf("Node %d: Reduced: assignment: happyruben ASSIGN_PLUS expr SEMI\n", 
        nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_PLUS\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "happyruben ASSIGN_PLUS expr SEMI";
    }
    |assignment ASSIGN expr
    {
        printf("Node %d: Reduced: assignment: assignment ASSIGN expr \n", 
        nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        $$ = "assignment ASSIGN expr SEMI";
    }
    ;
    

d_type:
    K_INTEGER
    {
        printf("Node %d: Reduced: d_type: K_INTEGER\n", nodeCount++);
        printf("\t Terminal Symbol: K_INTEGER\n");
        $$ = "K_INTEGER";
    }
    | K_STRING
    {
        printf("Node %d: Reduced: d_type: K_STRING\n", nodeCount++);
        printf("\t Terminal Symbol: K_STRING\n");
        $$ = "K_STRING";
    }
    | K_DOUBLE
    {
        printf("Node %d: Reduced: d_type: K_DOUBLE\n", nodeCount++);
        printf("\t Terminal Symbol: K_DOUBLE\n");
        $$ = "K_DOUBLE";
    }
    ;

expr:
    value 
    {
        printf("Node %d: Reduced: block: value\n", nodeCount++);
        printf("\t value -> %s\n", $1);
        $$ = "value ";
    } 
    | callfunc
    {
        printf("Node %d: Reduced: block: callfunc\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        $$ = "callfunc ";
    } 
    | expr MINUS expr
    {
        printf("Node %d: Reduced: expr: expr MINUS expr\n", nodeCount++);
        printf("\t expr-> %s\n", $1);
        printf("\t Terminal Symbol: MINUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MINUS expr";
    } 
    | expr PLUS expr        
    {
        printf("Node %d: Reduced: expr: expr PLUS expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: PLUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr PLUS expr";
    }
    | expr MULTIPLY expr
    {
        printf("Node %d: Reduced: expr: expr MULTIPLY expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: MULTIPLY\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MULTIPLY expr";
    }
    | expr DIVIDE expr
    {
        printf("Node %d: Reduced: expr: expr DIVIDE expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: DIVIDE\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr DIVIDE expr";
    }
    | expr MOD expr
     {
        printf("Node %d: Reduced: expr: expr MOD expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: MOD\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MOD expr";
    }
    | LPAREN expr RPAREN   
    {
        printf("Node %d: Reduced: expr: LPAREN expr RPAREN\n", nodeCount++);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t expr -> %s\n", $2);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "LPAREN expr RPAREN";
    }
    ;
    
value:
    ICONSTANT makenummutable  
    {
        printf("Node %d: Reduced: block: ICONSTANT makenummutable\n", nodeCount++);
        printf("\t Terminal Symbol: ICONSTANT\n");
        printf("\t makenummutable -> %s\n", $2);
        $$ = "ICONSTANT makenummutable ";
    }        
    | DCONSTANT makenummutable  
    {
        printf("Node %d: Reduced: block: DCONSTANT makenummutable\n", nodeCount++);
        printf("\t Terminal Symbol: DCONSTANT\n");
        printf("\t makenummutable -> %s\n", $2);
        $$ = "DCONSTANT makenummutable ";
    }    
    | happyruben
    {
        printf("Node %d: Reduced: block: happyruben\n", nodeCount++);
        printf("\t happyruben -> %s\n", $1);
        $$ = "happyruben ";
    } 
    | MINUS value
    {
        printf("Node %d: Reduced: block: MINUS value\n", nodeCount++);
        printf("\t Terminal Symbol: MINUS\n");
        printf("\t value -> %s\n", $2);
        $$ = "MINUS value ";
    } 
    | callfunc 
    {
        printf("Node %d: Reduced: block: callfunc\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        $$ = "callfunc ";
    } 
    |SCONSTANT 
    {
        printf("Node %d: Reduced: d_type: SCONSTANT\n", nodeCount++);
        printf("\t Terminal Symbol: SCONSTANT\n");
        $$ = "SCONSTANT";
    }

    ;

param_list:
    | var
    {
        printf("Node %d: Reduced: param_list: var\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        $$ = "var";
    }
    | var COMMA param_list
    {
        printf("Node %d: Reduced: param_list: var COMMA param_list\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        printf("\t Terminal Symbol: COMMA\n");
        printf("\t param_list -> %s\n", $3);
        $$ = "var COMMA param_list";
    }
    ;

// New Code Starts here.
arg_list:
    value
    | value COMMA arg_list
    |
    ;

relop: 
    LT
    | GT
    | LEQ
    | GEQ
    | DEQ
    | NE
    ;

gate:
    DAND
    |
    DOR;

condition: expr relop expr
    | condition gate condition
    | NOT condition
    ;

if: K_IF LPAREN condition RPAREN K_THEN block
    | K_IF LPAREN condition RPAREN K_THEN block K_ELSE block
    ;

reader:
    K_READ_DOUBLE LPAREN expr RPAREN
    | K_READ_INTEGER LPAREN expr RPAREN
    | K_READ_STRING LPAREN SCONSTANT RPAREN
    | K_READ_STRING LPAREN IDENTIFIER RPAREN
    ;

makenummutable:
    | DECREMENT
    | INCREMENT
    
    ;

arrayat: IDENTIFIER LBRACKET ICONSTANT makenummutable RBRACKET 
    | IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET 
    | IDENTIFIER LBRACKET expr RBRACKET
    ;

buildarr:
    IDENTIFIER LBRACKET RBRACKET 
    ;

callfunc:
    IDENTIFIER LPAREN arg_list RPAREN
    ;

whileloop:
    K_WHILE LPAREN condition RPAREN LCURLY block RCURLY
    | K_WHILE LPAREN condition RPAREN block
    ;

forloop:
    K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block
    | K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block
    | K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER INCREMENT RPAREN LCURLY block RCURLY
    | K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER DECREMENT RPAREN LCURLY block RCURLY
    ;
    
ret:
    K_RETURN value SEMI
    |K_RETURN assignment SEMI
    ;

happyruben:
    IDENTIFIER
    |
    arrayat
    ;
chain:
    var COMMA
    | assignment COMMA
    | expr COMMA
    | value COMMA
    | chain chain
    | chain chainend
    ;
chainend:
    var
    | value
    | assignment
    | expr
    ;

%%
extern FILE* yyin;

int main(){
    do{
        yyparse();

    }while(!feof(yyin));

    return 0;
}

    
    