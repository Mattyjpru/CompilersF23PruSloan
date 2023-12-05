%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "lex.yy.c"

    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }

    int yylex();
    int yywrap();
    extern char* yytext;
    extern int line;
    extern int yylineno;

    //Symbol Table stuff
    int st_count=0;
    char useBuff[16];
    
    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        int intval;
        float dubval;
        int line_no;
        char* memLoc;
    } symbolTable[48];
    // struct stEntry SymbolTableList[5][48];

    struct stRtnValue{
        char * strVal;
        int intVal;
        double floatVal;
    };

    // Code Gen stuff
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };
    struct node *head;
////////func protos
    struct node* buildNode(struct node* left, struct node* right, char* token);
    void printtree(struct node* );
    void printInorder(struct node *);
    void insert();
    int search(char*);
    void newSymbol(char, char*);
    void execute(struct node*);
    char* repD(char*, char);
    void walk(struct node*, FILE*);
    char* intIn(int, int, int, FILE*);
    int ST_get_index(char*);
    void printStr(char*, FILE*);
    void assignmentGenerator(int, FILE*);
    void printStatementGenerator(char*, FILE*);
    void printVar(char* memAddress, char* type, FILE* filename);
    char* strIn(char* input, int sLoc, FILE* filename);


    int SI = 0;
    int IR = 1;
    int FR = 1;

%}

%union {
    struct nt1 { 
		char name[100];
        // char dt[100];
		struct node* nd;
	} nd_obj; 
    // 
}

%token<nd_obj> IDENTIFIER ICONSTANT DCONSTANT SCONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER 
%token<nd_obj> K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER
%token<nd_obj> K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token<nd_obj> ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS 
%token<nd_obj> DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI

%type<nd_obj> statement program expr condition param_list forcond block d_type var assignment task function procedure print value arg_list
%type<nd_obj> if ret chain chainend makenummutable reader callfunc arrayat gate relop forloop whileloop valRef buildarr

%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement 

%%
statement: 
    program { printf("\nValid Program\n");};

program: K_PROGRAM IDENTIFIER LCURLY task RCURLY
    /* {
        printf("Node %d: Reduced: program: K_PROGRAM IDENTIFIER LCURLY task RCURLY\n", nodeCount++);
        printf("\t Terminal Symbol: K_PROGRAM\n");
        printf("\t IDENTIFIER -> %s\n", $2);
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t task -> %s\n", $4);
        printf("\t Terminal Symbol: RCURLY\n");
    } */
    ;

task: function
    /* {
        printf("Node %d: Reduced: task: function\n", nodeCount++);
        printf("\t function -> %s\n", $1);
        $$ = "function";
    } */
    | procedure
    /* {
        printf("Node %d: Reduced: task: procedure\n", nodeCount++);
        printf("\t procedure -> %s\n", $1);
        $$ = "procedure";
    } */
    | function task
    /* {
        printf("Node %d: Reduced: task: task function\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t function -> %s\n", $2);
        $$ = "task function";
    } */
    | procedure task  
    /* {
        printf("Node %d: Reduced: task: task procedure\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        printf("\t procedure -> %s\n", $2);
        $$ = "task procedure";
    } */
    ;

procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    /* {
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
    } */
    ;

function: K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    /* {
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
    } */
    ;

block:
    print
    /* {
        printf("Node %d: Reduced: block: print\n", nodeCount++);
        printf("\t print -> %s\n", $1);
        $$ = "print";
    }           */
    | var SEMI
    /* {
        printf("Node %d: Reduced: block: var SEMI\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "var SEMI";
    } */
    | callfunc SEMI
    /* {
        printf("Node %d: Reduced: block: callfunc SEMI\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "callfunc SEMI";
    }   */
    | assignment SEMI
    /* {
        printf("Node %d: Reduced: block: assignment SEMI\n", nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "assignment SEMI";
    }    */
    | if
    /* {
        printf("Node %d: Reduced: block: if\n", nodeCount++);
        printf("\t if -> %s\n", $1);
        $$ = "if";
    }       */
    | ret
    /* {
        printf("Node %d: Reduced: block: ret\n", nodeCount++);
        printf("\t ret -> %s\n", $1);
        $$ = "ret";
    }      */
    | forloop
    /* {
        printf("Node %d: Reduced: block: forloop\n", nodeCount++);
        printf("\t forloop -> %s\n", $1);
        $$ = "forloop";
    }      */
    | whileloop
    /* {
        printf("Node %d: Reduced: block: whileloop\n", nodeCount++);
        printf("\t whileloop -> %s\n", $1);
        $$ = "whileloop";
    }      */
    | reader SEMI
    /* {
        printf("Node %d: Reduced: block: reader SEMI\n", nodeCount++);
        printf("\t reader -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "reader SEMI";
    }  */
    | task
    /* {
        printf("Node %d: Reduced: block: task\n", nodeCount++);
        printf("\t task -> %s\n", $1);
        $$ = "task";
    }      */
    | LCURLY block RCURLY
    /* {
        printf("Node %d: Reduced: block: LCURLY block RCURLY\n", nodeCount++);
        printf("\t Terminal Symbol: LCURLY\n");
        printf("\t block -> %s\n", $2);
        printf("\t Terminal Symbol: RCURLY\n");
        $$ = "LCURLY block RCURLY";
    }  */
    | block block 
    /* {
        printf("Node %d: Reduced: block: block\n", nodeCount++);
        printf("\t block -> %s\n", $1);
        printf("\t block -> %s\n", $2);
        $$ = "block block";
    }  */
    | IDENTIFIER makenummutable SEMI 
    /* {
        printf("Node %d: Reduced: block: IDENTIFIER makenummutable SEMI\n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t makenummutable -> %s\n", $2);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "IDENTIFIER block RCURLY";
    }  */
    | chain SEMI   
    /* {
        printf("Node %d: Reduced: block: chain SEMI\n", nodeCount++);
        printf("\t chain -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "chain SEMI";
    }     */
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI 
    /* {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t ICONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI";
    } */
    | K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_DOUBLE\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t DCONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI";
    } */
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t SCONSTANT -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI";
    } */
    | K_PRINT_INTEGER LPAREN valRef RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t valRef -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN valRef RPAREN SEMI";
    } */
    | K_PRINT_DOUBLE LPAREN valRef RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t valRef -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN valRef RPAREN SEMI";
    } */
    | K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t IDENTIFIER -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI";
    } */
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    /* {
        printf("Node %d: Reduced: print: K_PRINT_INTEGER LPAREN expr RPAREN SEMI\n",
        nodeCount++);
        printf("\t Terminal Symbol: K_PRINT_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\expr -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_PRINT_INTEGER LPAREN expr RPAREN SEMI";
    } */
    ;

var:
    d_type valRef 
    /* {
        printf("Node %d: Reduced: var: d_type valRef\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t valRef -> %s\n", $2);
        
        $$ = "d_type valRef";
    } */
    | d_type buildarr
    /* {
        printf("Node %d: Reduced: var: d_type buildarr\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t buildarr -> %s\n", $2);
        
        $$ = "d_type buildarr";
    } */
    | d_type assignment
    /* {
        printf("Node %d: Reduced: var: d_type assignment\n", nodeCount++);
        printf("\t d_type -> %s\n", $1);
        printf("\t assignment -> %s\n", $2);
        $$ = "d_type assignment";
    } */
    | var SEMI
    /* {
        printf("Node %d: Reduced: var: var SEMI\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "var SEMI";
    }  */
    ;

assignment:
    valRef ASSIGN expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN expr SEMI";
    } */
    | valRef ASSIGN_DIVIDE expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN_DIVIDE expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_DIVIDE\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN_DIVIDE expr SEMI";
    } */
    | valRef ASSIGN_MINUS expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN_MINUS expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MINUS\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN_MINUS expr SEMI";
    } */
    | valRef ASSIGN_MOD expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN_MOD expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MOD\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN_MOD expr SEMI";
    } */
    | valRef ASSIGN_MULTIPLY expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN_MULTIPLY expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_MULTIPLY\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN_MULTIPLY expr SEMI";
    } */
    | valRef ASSIGN_PLUS expr 
    /* {
        printf("Node %d: Reduced: assignment: valRef ASSIGN_PLUS expr SEMI\n", 
        nodeCount++);
        printf("\t valRef -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN_PLUS\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "valRef ASSIGN_PLUS expr SEMI";
    } */
    |assignment ASSIGN expr
    /* {
        printf("Node %d: Reduced: assignment: assignment ASSIGN expr \n", 
        nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t expr -> %s\n", $3);
        $$ = "assignment ASSIGN expr SEMI";
    } */
    ;
    

d_type:
    K_INTEGER
    /* {
        printf("Node %d: Reduced: d_type: K_INTEGER\n", nodeCount++);
        printf("\t Terminal Symbol: K_INTEGER\n");
        $$ = "K_INTEGER";
    } */
    | K_STRING
    /* {
        printf("Node %d: Reduced: d_type: K_STRING\n", nodeCount++);
        printf("\t Terminal Symbol: K_STRING\n");
        $$ = "K_STRING";
    } */
    | K_DOUBLE
    /* {
        printf("Node %d: Reduced: d_type: K_DOUBLE\n", nodeCount++);
        printf("\t Terminal Symbol: K_DOUBLE\n");
        $$ = "K_DOUBLE";
    } */
    ;

expr:
    value 
    /* {
        printf("Node %d: Reduced: expr: value\n", nodeCount++);
        printf("\t value -> %s\n", $1);
        $$ = "value ";
    }  */
    | callfunc
    /* {
        printf("Node %d: Reduced: expr: callfunc\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        $$ = "callfunc ";
    }  */
    | expr MINUS expr
    /* {
        printf("Node %d: Reduced: expr: expr MINUS expr\n", nodeCount++);
        printf("\t expr-> %s\n", $1);
        printf("\t Terminal Symbol: MINUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MINUS expr";
    }  */
    | expr PLUS expr        
    /* {
        printf("Node %d: Reduced: expr: expr PLUS expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: PLUS\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr PLUS expr";
    } */
    | expr MULTIPLY expr
    /* {
        printf("Node %d: Reduced: expr: expr MULTIPLY expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: MULTIPLY\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MULTIPLY expr";
    } */
    | expr DIVIDE expr
    /* {
        printf("Node %d: Reduced: expr: expr DIVIDE expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: DIVIDE\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr DIVIDE expr";
    } */
    | expr MOD expr
     /* {
        printf("Node %d: Reduced: expr: expr MOD expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t Terminal Symbol: MOD\n");
        printf("\t expr -> %s\n", $3);
        $$ = "expr MOD expr";
    } */
    | LPAREN expr RPAREN   
    /* {
        printf("Node %d: Reduced: expr: LPAREN expr RPAREN\n", nodeCount++);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t expr -> %s\n", $2);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "LPAREN expr RPAREN";
    } */
    ;
    
value:
    ICONSTANT makenummutable  
    /* {
        printf("Node %d: Reduced: value: ICONSTANT makenummutable\n", nodeCount++);
        printf("\t Terminal Symbol: ICONSTANT\n");
        printf("\t makenummutable -> %s\n", $2);
        $$ = "ICONSTANT makenummutable ";
    }         */
    | DCONSTANT makenummutable  
    /* {
        printf("Node %d: Reduced: value: DCONSTANT makenummutable\n", nodeCount++);
        printf("\t Terminal Symbol: DCONSTANT\n");
        printf("\t makenummutable -> %s\n", $2);
        $$ = "DCONSTANT makenummutable ";
    }     */
    | valRef
    /* {
        printf("Node %d: Reduced: value: valRef\n", nodeCount++);
        printf("\t valRef -> %s\n", $1);
        $$ = "valRef ";
    }  */
    | MINUS value
    /* {
        printf("Node %d: Reduced: value: MINUS value\n", nodeCount++);
        printf("\t Terminal Symbol: MINUS\n");
        printf("\t value -> %s\n", $2);
        $$ = "MINUS value ";
    }  */
    | callfunc 
    /* {
        printf("Node %d: Reduced: value: callfunc\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        $$ = "callfunc ";
    }  */
    |SCONSTANT 
    /* {
        printf("Node %d: Reduced: value: SCONSTANT\n", nodeCount++);
        printf("\t Terminal Symbol: SCONSTANT\n");
        $$ = "SCONSTANT";
    } */

    ;

param_list:
    var
    /* {
        printf("Node %d: Reduced: param_list: var\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        $$ = "var";
    } */
    | var COMMA param_list
    /* {
        printf("Node %d: Reduced: param_list: var COMMA param_list\n", nodeCount++);
        printf("\t callfunc -> %s\n", $1);
        printf("\t Terminal Symbol: COMMA\n");
        printf("\t param_list -> %s\n", $3);
        $$ = "var COMMA param_list";
    } */
    | 
    /* {$$ = "_EPSILON_";} */
    ;





// New Code Starts here.



//cody code
condition: expr relop expr
    /* {
        printf("Node %d: Reduced: condition: expr relop expr\n", nodeCount++);
        printf("\t expr-> %s\n",$1);
        printf("\t relop-> %s\n",$2);
        printf("\t expr -> %s\n", $3);
        $$ = "expr relop expr";
    } */
    | condition gate condition
    /* {
        printf("Node %d: Reduced: condition: condition gate condition\n", nodeCount++);
        printf("\t condition-> %s\n",$1);
        printf("\t gate-> %s\n",$2);
        printf("\t condition -> %s\n", $3);
        $$ = "condition gate condition";
    } */
    | NOT condition
    /* {
        printf("Node %d: Reduced: condition: NOT condition\n", nodeCount++);
        printf("\t Terminal Symbol: NOT\n");
        printf("\t condition -> %s\n", $2);
        $$ = "NOT condition";
    } */
    ;

if: K_IF LPAREN condition RPAREN K_THEN block
    /* {
        printf("Node %d: Reduced: if: K_IF LPAREN condition RPAREN K_THEN block\n", nodeCount++);
        printf("\t Terminal Symbol: K_IF\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t condition -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: K_THEN\n");
        printf("\t block -> %s\n", $6);
        $$ = "K_IF LPAREN condition RPAREN K_THEN block";
    } */
    | K_IF LPAREN condition RPAREN K_THEN block K_ELSE block
    /* {
        printf("Node %d: Reduced: if: K_IF LPAREN condition RPAREN K_THEN block K_ELSE block\n", nodeCount++);
        printf("\t Terminal Symbol: K_IF\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t condition -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t Terminal Symbol: K_THEN\n");
        printf("\t block -> %s\n", $6);
        printf("\t Terminal Symbol: K_ELSE\n");
        printf("\t block -> %s\n", $8);
        $$ = "K_IF LPAREN condition RPAREN K_THEN block K_ELSE block";
    } */
    ;

ret:
    K_RETURN value SEMI
    /* {
        printf("Node %d: Reduced: ret: K_RETURN block SEMI\n", nodeCount++);
        printf("\t Terminal Symbol: K_RETURN\n");
        printf("\t value -> %s\n", $2);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_RETURN value SEMI";
    }  */
    |K_RETURN assignment SEMI
    /* {
        printf("Node %d: Reduced: ret: K_RETURN assignment SEMI\n", nodeCount++);
        printf("\t Terminal Symbol: K_RETURN\n");
        printf("\t assignment -> %s\n", $2);
        printf("\t Terminal Symbol: SEMI\n");
        $$ = "K_RETURN assignment SEMI";
    }  */
    ;

relop: 
    LT
    /* {
        printf("Node %d: Reduced: relop: LE\n", nodeCount++);
        printf("\t Terminal Symbol: LE\n");
        $$ = "LE";
    } */
    | GT
    /* {
        printf("Node %d: Reduced: relop: GT\n", nodeCount++);
        printf("\t Terminal Symbol: GT\n");
        $$ = "GT";
    } */
    | LEQ
    /* {
        printf("Node %d: Reduced: relop: LEQ\n", nodeCount++);
        printf("\t Terminal Symbol: LEQ\n");
        $$ = "LEQ";
    } */
    | GEQ
    /* {
        printf("Node %d: Reduced: relop: GEQ\n", nodeCount++);
        printf("\t Terminal Symbol: GEQ\n");
        $$ = "GEQ";
    } */
    | DEQ
    /* {
        printf("Node %d: Reduced: relop: DEQ\n", nodeCount++);
        printf("\t Terminal Symbol: DEQ\n");
        $$ = "DEQ";
    } */
    | NE
    /* {
        printf("Node %d: Reduced: relop: NE\n", nodeCount++);
        printf("\t Terminal Symbol: NE\n");
        $$ = "NE";
    } */
    ;

gate:
    DAND
    /* {
        printf("Node %d: Reduced: gate: DAND\n", nodeCount++);
        printf("\t Terminal Symbol: DAND\n");
        $$ = "DAND";
    } */
    | DOR
    /* {
        printf("Node %d: Reduced: gate: DOR\n", nodeCount++);
        printf("\t Terminal Symbol: DOR\n");
        $$ = "DOR";
    } */
    ;





//matty code
arg_list:
    value
    /* {
        printf("Node %d: Reduced: arg_list: value\n", nodeCount++);
        printf("\t value -> %s\n", $1);
        $$ = "value";
    } */
    | value COMMA arg_list
    /* {
        printf("Node %d: Reduced: arg_list: value COMMA arg_list\n", nodeCount++);
        printf("\t value-> %s\n",$1);
        printf("\t Terminal Symbol: Comma\n");
        printf("\t arg_list -> %s\n", $3);
        $$ = "value COMMA arg_list";
    } */
    |
    /* {$$ = "_EPSILON_";} */
    ;


reader:
    K_READ_DOUBLE LPAREN expr RPAREN
    /* {
        printf("Node %d: Reduced: reader: K_READ_DOUBLE LPAREN expr RPAREN \n", nodeCount++);
        printf("\t Terminal Symbol: K_READ_DOUBLE\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "K_READ_DOUBLE LPAREN expr RPAREN";
    }  */
    | K_READ_INTEGER LPAREN expr RPAREN
    /* {
        printf("Node %d: Reduced: reader: K_READ_INTEGER LPAREN expr RPAREN \n", nodeCount++);
        printf("\t Terminal Symbol: K_READ_INTEGER\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "K_READ_INTEGER LPAREN expr RPAREN";
    }  */
    | K_READ_STRING LPAREN SCONSTANT RPAREN
    /* {
        printf("Node %d: Reduced: reader: K_READ_STRING LPAREN SCONSTANT RPAREN \n", nodeCount++);
        printf("\t Terminal Symbol: K_READ_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: SCONSTANT\n");
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "K_READ_STRING LPAREN SCONSTANT RPAREN";
    }  */
    | K_READ_STRING LPAREN IDENTIFIER RPAREN
    /* {
        printf("Node %d: Reduced: reader: K_READ_STRING LPAREN IDENTIFIER RPAREN \n", nodeCount++);
        printf("\t Terminal Symbol: K_READ_STRING\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "K_READ_STRING LPAREN IDENTIFIER RPAREN";
    }  */
    ;

makenummutable:
    DECREMENT
    /* {
        printf("Node %d: Reduced: makenummutable: DECREMENT\n", nodeCount++);
        printf("\t Terminal Symbol: DECREMENT\n");
        $$ = "DECREMENT";
    } */
    | INCREMENT
    /* {
        printf("Node %d: Reduced: makenummutable: INCREMENT\n", nodeCount++);
        printf("\t Terminal Symbol: INCREMENT\n");
        $$ = "INCREMENT";
    } */
    |
    /* {$$ = "_EPSILON_";} */
    
    ;

arrayat: IDENTIFIER LBRACKET ICONSTANT makenummutable RBRACKET 
    /* {
        printf("Node %d: Reduced: arrayat: IDENTIFIER LBRACKET ICONSTANT makenummutable RBRACKET \n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: LBRACKET\n");
        printf("\t Terminal Symbol: ICONSTANT\n");
        printf("\t makenummutable -> %s\n", $4);
        printf("\t Terminal Symbol: RBRACKET\n");
        $$ = "IDENTIFIER LBRACKET ICONSTANT makenummutable RBRACKET";
    }  */
    | IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET 
    /* {
        printf("Node %d: Reduced: arrayat: IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET \n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: LBRACKET\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t makenummutable -> %s\n", $4);
        printf("\t Terminal Symbol: RBRACKET\n");
        $$ = "IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET";
    }  */
    | IDENTIFIER LBRACKET expr RBRACKET
    /* {
        printf("Node %d: Reduced: arrayat: IDENTIFIER LBRACKET expr RBRACKET \n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: LBRACKET\n");
        printf("\t expr -> %s\n", $3);
        printf("\t Terminal Symbol: RBRACKET\n");
        $$ = "IDENTIFIER LBRACKET expr RBRACKET";
    }  */
    ;

buildarr:
    IDENTIFIER LBRACKET RBRACKET 
    /* {
        printf("Node %d: Reduced: buildarr: IDENTIFIER LBRACKET RBRACKET \n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: LBRACKET\n");
        printf("\t Terminal Symbol: RBRACKET\n");
        $$ = "IDENTIFIER LBRACKET RBRACKET";
    }  */
    ;

callfunc:
    IDENTIFIER LPAREN arg_list RPAREN
    /* {
        printf("Node %d: Reduced: callfunc: LPAREN arg_list RPAREN\n", nodeCount++);
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t arg_list -> %s\n", $2);
        printf("\t Terminal Symbol: RPAREN\n");
        $$ = "LPAREN arg_list RPAREN";
    }  */
    ;

whileloop:
     K_WHILE LPAREN condition RPAREN block
    /* {
        printf("Node %d: Reduced: whileloop: K_WHILE LPAREN condition RPAREN block\n", nodeCount++);
        printf("\t Terminal Symbol: K_WHILE\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t condition -> %s\n", $3);
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t block -> %s\n", $5);
        $$ = "K_WHILE LPAREN condition RPAREN block";
    } */
    ;
forcond:
    ICONSTANT
    /* {
        printf("Node %d: Reduced: forcond: ICONSTANT\n", nodeCount++);
        printf("\t Terminal Symbol: ICONSTANT\n");
        $$ = "ICONSTANT";
    } */
    | IDENTIFIER
    /* {
        printf("Node %d: Reduced: forcond: IDENTIFIER\n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        $$ = "IDENTIFIER";
    } */
    ;
forloop:
    K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block
    /* {
        printf("Node %d: Reduced: forloop: K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block\n", nodeCount++);
        printf("\t Terminal Symbol: K_DO\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t forcond -> %s\n", $5);
        printf("\t Terminal Symbol: SEMI\n");
        printf("\t condition -> %s\n", $7);
        printf("\t Terminal Symbol: SEMI\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: INCREMENT\n");
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t block -> %s\n", $12);
        $$ = "K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block";
    } */
    | K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block
    /* {
        printf("Node %d: Reduced: forloop: K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block\n", nodeCount++);
        printf("\t Terminal Symbol: K_DO\n");
        printf("\t Terminal Symbol: LPAREN\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: ASSIGN\n");
        printf("\t forcond -> %s\n", $5);
        printf("\t Terminal Symbol: SEMI\n");
        printf("\t condition -> %s\n", $7);
        printf("\t Terminal Symbol: SEMI\n");
        printf("\t Terminal Symbol: IDENTIFIER\n");
        printf("\t Terminal Symbol: DECREMENT\n");
        printf("\t Terminal Symbol: RPAREN\n");
        printf("\t block -> %s\n", $12);
        $$ = "K_DO LPAREN IDENTIFIER ASSIGN ICONSTANT SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block";
    } */

    ;
    
valRef:
    IDENTIFIER
    /* {
        printf("Node %d: Reduced: valRef: IDENTIFIER\n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        $$ = "IDENTIFIER";
    } */
    | arrayat
    /* {
        printf("Node %d: Reduced: valRef: arrayat\n", nodeCount++);
        printf("\t arrayat -> %s\n", $1);
        $$ = "arrayat";
    } */
    ;
chain:
    var COMMA
    /* {
        printf("Node %d: Reduced: chain: var COMMA\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        printf("\t Terminal Symbol: COMMA\n");
        $$ = "var COMMA";
    } */
    | assignment COMMA
    /* {
        printf("Node %d: Reduced: chain: assignment COMMA\n", nodeCount++);
        printf("\t assignment -> %s\n", $1);
        printf("\t Terminal Symbol: COMMA\n");
        $$ = "assignment COMMA";
    } */
    | expr COMMA
    /* {
        printf("Node %d: Reduced: chain: expr COMMA\n", nodeCount++);
        printf("\t expr -> %s\n", $1);
        printf("\t Terminal Symbol: COMMA\n");
        $$ = "expr COMMA";
    } */

    | chain chain
    /* {
        printf("Node %d: Reduced: chain: chain chain\n", nodeCount++);
        printf("\t chain -> %s\n", $1);
        printf("\t chain -> %s\n", $2);
        $$ = "chain chain";
    } */
    | chain chainend
    /* {
        printf("Node %d: Reduced: chain: chain chainend\n", nodeCount++);
        printf("\t chain -> %s\n", $1);
        printf("\t chainend -> %s\n", $2);
        $$ = "chain chainend";
    } */
    ;
chainend:
    var
    /* {
        printf("Node %d: Reduced: chainend: var\n", nodeCount++);
        printf("\t var -> %s\n", $1);
        $$ = "var";
    } */

    | assignment
    /* {
        printf("Node %d: Reduced: chainend: assignment\n", nodeCount++);
        printf("\t assignment -> %s\n", $1);
        $$ = "assignment";
    } */
    | expr
    /* {
        printf("Node %d: Reduced: chainend: expr\n", nodeCount++);
        printf("\t expr -> %s\n", $1);
        $$ = "expr";
    } */
    ;

%%
extern FILE* yyin;

int main(){
    do{
        yyparse();
        printf("\n\n");
        /* printf("%-25s %-15s %-15s %-15s\n","SYMBOL", "DATATYPE", "TYPE", "LINE NUMBER");
        printf("___________________________________________________________________________\n\n");

        for(int i=0; i<st_count; i++) {
            if(strcmp(symbolTable[i].use, "ICONSTANT") == 0){
                printf("%-25d %-15s %-15s %-15d\n", symbolTable[i].intval, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
            else if(strcmp(symbolTable[i].use, "DCONSTANT") == 0){
                printf("%-25f %-15s %-15s %-15d\n", symbolTable[i].dubval, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
            else{
                printf("%-25s %-15s %-15s %-15d\n", symbolTable[i].name, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
        } */
        for(int i=0;i<st_count;i++) {
            free(symbolTable[i].name);
            free(symbolTable[i].d_type);
            free(symbolTable[i].use);
            free(symbolTable[i].memLoc);
        }
    }while(!feof(yyin));
    /* printf("\n\n");
    printtree(head); 
    printf("\n\n"); */
    return 0;
}
void insert(){
    strcpy(useBuff, yytext);
}

////////////////////////// Function to replace the d to e in double strings /////////////////////////
char* repD(char* str, char target){
    char* here=strchr(str,target);
    while(here){
        *here='e';
        here=strchr(here, target);
    }
    return str;
}

////////////////////////////////// New Symbol Table Stuff //////////////////////////////////////////
void newSymbol(char c, char* stringVal){
    if(!search(stringVal)){
        switch(c){
            case 'I':
                symbolTable[st_count].name=strdup(stringVal);
                symbolTable[st_count].intval = atoi(stringVal);
                symbolTable[st_count].d_type=strdup("CONST");
                symbolTable[st_count].line_no=line;    
                symbolTable[st_count].use=strdup("ICONSTANT");//this should be ICONSTANT but if i change it to that, it sets the 441 to 0?
                st_count++;
                break;
            case 'D':
                stringVal = strdup(repD(repD(stringVal,'d'),'D'));
                symbolTable[st_count].name=strdup(stringVal);
                symbolTable[st_count].dubval = atof(stringVal);
                symbolTable[st_count].d_type=strdup("CONST");
                symbolTable[st_count].line_no=line;
                symbolTable[st_count].use=strdup("DCONSTANT");
                st_count++;
                break;
            case 'V':
                symbolTable[st_count].name=strdup(stringVal);
                symbolTable[st_count].d_type=strdup(useBuff);
                symbolTable[st_count].line_no=line;
                symbolTable[st_count].use=strdup("IDENTIFIER");
                st_count++;
                break;
            case 'P':
                symbolTable[st_count].name=strdup(stringVal);        
                symbolTable[st_count].d_type=strdup("void");    
                symbolTable[st_count].line_no=line;    
                symbolTable[st_count].use=strdup("PROCEDURE");
                st_count++;
                break;
            case 'S':
                symbolTable[st_count].name=strdup(stringVal); 
                symbolTable[st_count].d_type=strdup("CONST");
                symbolTable[st_count].line_no=line;
                symbolTable[st_count].use=strdup("SCONSTANT");
                st_count++;
                break;
            case 'F':
                symbolTable[st_count].name=strdup(stringVal); 
                symbolTable[st_count].d_type=strdup(useBuff);
                symbolTable[st_count].line_no=line;
                symbolTable[st_count].use=strdup("FUNCTION");
                st_count++;
                break;
            case 'M':
                symbolTable[st_count].name=strdup(stringVal); 
                symbolTable[st_count].d_type=strdup("N/A");
                symbolTable[st_count].line_no=line;
                symbolTable[st_count].use=strdup("PROGRAM");
                st_count++;
                break;
        }
    }
}

int search(char* in){
    for(int i=0; i<st_count; i++){
        if(strcmp(symbolTable[i].name, in)==0){
            return -1;
            break;
        }
    }
    return 0;
}


struct node* buildNode( struct node* left, struct node* right, char* token){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->leftchild = left;
    newnode->rightchild = right;
    newnode->token = newstr;
    /* printf("Built a node: %s\n", newstr); */
    return(newnode);
}

void printtree(struct node* tree) {
    printf("\n\n Inorder traversal of the Parse Tree: \n\n");
    printInorder(tree);
    printf("\n\n");
}

void printInorder(struct node *tree) {
    if (tree->leftchild) {
        printInorder(tree->leftchild);
    }
    printf("%s, ", tree->token);
    if (tree->rightchild) {
        printInorder(tree->rightchild);
    }
}


/////////////////////////////////////////code generator because we are bad at linking files/////////////////////////////////////



void execute(struct node* start){//will need to call this in the makeFILE
    FILE* urManeDotH=fopen("yourmain.h", "w+");
    
    fprintf(urManeDotH, "int yourmain() {\n");
    fprintf(urManeDotH, "SR -= %d;\n", st_count);//********
    walk(start, urManeDotH);
    fprintf(urManeDotH, "SR += %d;\n", st_count);//********
    fprintf(urManeDotH, "return 0;\n}");
    fclose(urManeDotH);
    }



void walk(struct node* yesde, FILE* filename){
    /* printf("walk\n"); */
        if(!(yesde->leftchild)&&!(yesde->rightchild)){
            /* printf("leaf\n"); */
        }
        else{
            if (strcmp(yesde->token, "=")==0){
                int varIndex = ST_get_index(yesde->leftchild->token);
                int valueIndex = ST_get_index(yesde->rightchild->token);

                symbolTable[varIndex].intval = symbolTable[valueIndex].intval;

                assignmentGenerator(varIndex, filename);
         
            }
                
            else if (strcmp(yesde->token, "print statement") == 0){
                printStatementGenerator(yesde->rightchild->token, filename);
      
            }
                
            else{
                if (yesde->leftchild) {
                    walk(yesde->leftchild, filename);
                }
                if (yesde->rightchild) {
                    walk(yesde->rightchild, filename);
                }
            }
        }
    }
    
void assignmentGenerator(int index, FILE* filename){//************************************
    if(index == -1){
        printf("THIS IS BAD\n");
        exit(0);
    }
    
    char* location;
    if (strcmp(symbolTable[index].d_type , "integer")==0) {
        location = intIn(symbolTable[index].intval, SI, IR, filename);
        IR++;
        symbolTable[index].memLoc=strdup(location);
        /* printf("%d\n", symbolTable[index].intval); */
    }
    else if(strcmp(symbolTable[index].d_type , "double")==0){
        /* printf("%f\n", symbolTable[index].dubval); */
    }
    else if(strcmp(symbolTable[index].d_type , "string")==0){
        /* printf("%s\n", symbolTable[index].name); */
        location = strIn(symbolTable[index].name, SI, filename);
        IR++;
        symbolTable[index].memLoc=strdup(location);
    }
    free(location);
}

int ST_get_index(char* name){
    for(int i = 0; i < st_count; i++){
        if(strcmp(symbolTable[i].name, name) == 0){
            return i;
        }
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////
void printStatementGenerator(char* name, FILE* filename){//************************************
    // TODO:
    // Figure out how to get 'file'
    if(name[0] == '"'){
        printStr(name, filename);
    }
    else{
        // Gotta do all this just to get the location to pass to printVar.
        int index = ST_get_index(name);
        printVar(symbolTable[index].memLoc, symbolTable[index].d_type, filename);
    }
}

char* intIn(int intVal, int sLoc, int irLoc, FILE* filename){
    fprintf(filename,"R[%d] = %d;\n" , irLoc, intVal);
    /* printf("%d integer value is: \n", intVal); */
    fprintf(filename, "F23_Time += 1;\n");
    fprintf(filename, "Mem[SR + %d] = R[%d];\n", sLoc, irLoc);
    
    fprintf(filename, "F23_Time += 20 + 1;\n");
    char* buff;
    buff = malloc(sizeof(char)*20);
    sprintf(buff, "Mem[SR + %d]", sLoc);
    return buff;
    }


void printStr(char* str, FILE* filename){

    fprintf(filename, "print_string(%s);\n", str);
    fprintf(filename, "F23_Time += 1;\n");
}
void printVar(char* memAddress, char* type, FILE* filename){

    if (strcmp(type , "integer")==0){
        fprintf(filename, "print_int(%s);\n", memAddress);
    }
    if (strcmp(type , "string")==0){
        fprintf(filename, "print_string(%s);\n", memAddress);
    }
    fprintf(filename, "F23_Time += 20 + 1;\n");
}



char* strIn(char* input, int sLoc, FILE* filename){
    fprintf(filename,"sBuf = %s;\n" ,  input);
    /* printf("%d integer value is: \n", intVal); */
    fprintf(filename, "F23_Time += 1;\n");
    fprintf(filename, "SMem[SR + %d] = sBuf;\n", sLoc);
    
    fprintf(filename, "F23_Time += 20 + 1;\n");
    char* buff;
    buff = malloc(sizeof(char)*20);
    sprintf(buff, "SMem[SR + %d]", sLoc);
    return buff;
}
    
    

    
    