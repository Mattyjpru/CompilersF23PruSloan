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
    

    //Symbol Table stuff
    // int st_count=0;
    // char useBuff[16];
    
    // struct stEntry{
    //     char* name;
    //     char* d_type;
    //     char* use;
    //     int intval;
    //     float dubval;
    //     int line_no;
    //     char* memLoc;
    // } symbolTable[48];
    // struct stEntry SymbolTableList[5][48];

    // struct stRtnValue{
    //     char * strVal;
    //     int intVal;
    //     double floatVal;
    // };

    // Code Gen stuff
    // struct node{
    //     char* token;
    //     struct node* leftchild;
    //     struct node* rightchild;
    //     // char* dataType;
    // };
    // struct node *head;
////////func protos
    // struct node* buildNode(struct node* left, struct node* right, char* token);
    // void printtree(struct node* );
    // void printInorder(struct node *);
    // void insert();
    // int search(char*);
    // void newSymbol(char, char*);
    // void execute(struct node*);
    // char* repD(char*, char);
    // void walk(struct node*, FILE*);
    // char* intIn(int, int, int, FILE*);
    // int ST_get_index(char*);
    // void assignmentGenerator(int, FILE*);
    // void printStatementGenerator(char*, FILE*);
    // void printVar(char* memAddress, char* type, FILE* filename);
    


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
%type<sVal> if ret makenummutable reader callfunc arrayat gate relop forloop whileloop

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
    | assignment SEMI
    {
        printf("Node %d: Reduced: block: assignment\n", nodeCount++);
        printf("\assignment -> %s\n", $1);
        $$ = "assignment";
    }   
    | if     
    | ret
    | forloop
    | whileloop
    | reader
    | task
    | LCURLY block RCURLY
    | block block       
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
    | K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
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
    | K_PRINT_DOUBLE LPAREN IDENTIFIER RPAREN SEMI
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
    d_type IDENTIFIER 
    {
        printf("Node %d: Reduced: var: d_type IDENTIFIER\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t IDENTIFIER -> %s\n", $2);
        
        $$ = "d_type IDENTIFIER";
    }
    | d_type buildarr
    | d_type assignment
    {
        printf("Node %d: Reduced: var: d_type assignment\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t assignment -> %s\n", $2);
        $$ = "d_type assignment";
    }
    | var SEMI
    ;

assignment:
    IDENTIFIER ASSIGN expr 
    {
        printf("Node %d: Reduced: assignment: IDENTIFIER ASSIGN expr SEMI\n", 
        nodeCount++);
        printf("\t IDENTIFIER -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "IDENTIFIER ASSIGN expr SEMI";
    }
    | IDENTIFIER ASSIGN_DIVIDE expr 

    | IDENTIFIER ASSIGN_MINUS expr 
    
    | IDENTIFIER ASSIGN_MOD expr 
    
    | IDENTIFIER ASSIGN_MULTIPLY expr 
    
    | IDENTIFIER ASSIGN_PLUS expr 
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
    ;

expr:
    value 
    | callfunc

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
    
    | expr DIVIDE expr
    
    | expr MOD expr
     
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
    | DCONSTANT makenummutable     
    | IDENTIFIER 
    | arrayat  
    | MINUS value
    | callfunc  
    ;

param_list:
    var
    | var COMMA param_list
    {
        printf("Node %d: Reduced: param_list: d_type IDENTIFIER COMMA param_list\n",
        nodeCount++);
        // NEEDS REWRITTEN
        $$ = "d_type IDENTIFIER COMMA param_list";
    }
    |
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
    K_READ_DOUBLE
    | K_READ_INTEGER
    | K_READ_STRING
    ;

makenummutable:
    DECREMENT
    |
    INCREMENT
    |
    ;

arrayat: IDENTIFIER LBRACKET ICONSTANT makenummutable RBRACKET 
    | IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET 
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

%%
extern FILE* yyin;

int main(){
    do{
        yyparse();

    }while(!feof(yyin));

    return 0;
}

    
    