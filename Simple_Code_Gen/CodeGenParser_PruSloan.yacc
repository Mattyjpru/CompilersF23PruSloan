%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "lex.yy.c"

    extern int line;

    int yyerror(char *msg){
        printf("Invalid Program: %s, line: %d\n", msg, line);
        exit(0);
    }

    int yylex();
    int yywrap();
    
    //Symbol Table stuff
    int st_count=0;
    char useBuff[16];

    #define MAX_ST_SIZE 48
    #define MAX_ST_STACK_SIZE 30

    struct SymTabEntry{
        char* name;
        char* type;
        char* memLoc;
    }InitialSymTab[MAX_ST_SIZE];

    struct SymTabStack{
        struct SymTabEntry SymTab[MAX_ST_STACK_SIZE][MAX_ST_SIZE];
        int top;
        int sizes[MAX_ST_STACK_SIZE];
    }*ST_Stack;

    struct SymTabRtnValue{
        char* strVal;
        int intVal;
        double floatVal;
    };

    // Define a struct to hold the result of ST_get_index
    typedef struct {
        int stackIndex;
        int SymTabIndex;
    } IndexPair;

    // Code Gen stuff
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };
    struct node *head;

////////func protos
    struct node* buildNode(struct node*, struct node*, char*);
    void printtree(struct node* );
    void printInorder(struct node *);
    void insert();
    int search(char*);
    void newSymbol(char, char*);
    void execute(struct node*);
    char* repD(char*, char);
    void walk(struct node*, FILE*);
    char* intIn(int, int, int, FILE*);
    IndexPair ST_get_index(char*);
    void printStr(char*, FILE*);
    void assignmentGenerator(int, FILE*);
    void printStatementGenerator(char*, FILE*);
    void printVar(char*, char*, FILE*);
    char* strIn(char*, int, FILE*);
    void ST_Stack_init();
    int SymTab_push(struct SymTabEntry*);

    int SI = 0;
    int IR = 1;
    int FR = 1;

%}

%union {
    struct nt1{ 
		char name[100];
        // char dt[100];
		struct node* nd;
	}nd_obj; 
}

%token<nd_obj> IDENTIFIER ICONSTANT DCONSTANT SCONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER 
%token<nd_obj> K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER
%token<nd_obj> K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token<nd_obj> ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS 
%token<nd_obj> DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI

%type<nd_obj> statement program expr condition param_list forcond block d_type var assignment task function procedure print value arg_list
%type<nd_obj> if ret chain chainend makenummutable reader callfunc arrayat gate relop forloop whileloop valRef buildarr

%left MINUS PLUS
%left DIVIDE MULTIPLY
%start statement 

%%
statement: 
     program { printf("\nValid Program\n"); /*execute(head); */ printtree(head);}; 

program: K_PROGRAM IDENTIFIER {newSymbol('M', $2.name);} LCURLY task RCURLY
    {
        $$.nd=buildNode( $5.nd, NULL, $2.name);
        head = $$.nd;
    }
    ;

task: function {$$.nd = buildNode($1.nd, NULL, "task");}
    | procedure {$$.nd = buildNode($1.nd, NULL, "task");}
    | function task {$$.nd = buildNode($1.nd, $2.nd, "task");}
    | procedure task {$$.nd = buildNode($1.nd, $2.nd, "task");}
    ;

procedure: K_PROCEDURE IDENTIFIER {newSymbol('P', $2.name);} LPAREN param_list RPAREN block
    {
        $$.nd = buildNode($5.nd, $7.nd, $2.name);
    }
    ;

function: K_FUNCTION d_type IDENTIFIER {newSymbol('F', $3.name);} LPAREN param_list RPAREN block
    {
        $$.nd = buildNode($6.nd, $8.nd, $3.name);
    }
    ;

block:
    print {$$.nd = $1.nd;}

    | var SEMI {$$.nd = $1.nd;}

    | callfunc SEMI {$$.nd = $1.nd;}

    | assignment SEMI {$$.nd = $1.nd;}

    | if {$$.nd = $1.nd;}

    | ret {$$.nd = $1.nd;}

    | forloop {$$.nd = $1.nd;}

    | whileloop {$$.nd = $1.nd;}

    | reader SEMI {$$.nd = $1.nd;}

    | task {$$.nd = $1.nd;}

    | LCURLY block RCURLY {$$.nd = $2.nd;}

    | block block {$$.nd = buildNode($1.nd, $2.nd, "blocks");}

    | IDENTIFIER {newSymbol('V', $1.name);} makenummutable SEMI /*{$$.nd = $3.nd;}  NOT SURE HOW TO DO THIS ONE*/
    {
        $$.nd=buildNode($1.nd,$3.nd, "mutate");
    }

    | chain SEMI {$$.nd = $1.nd;}
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI 
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_DOUBLE LPAREN valRef RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), $3.nd, "print statement");
    }
    | K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), $3.nd, "print statement");
    }
    ;

var:
    d_type valRef {$$.nd = $2.nd;}
    | d_type buildarr {$$.nd = $2.nd;}
    | d_type assignment {$$.nd = $2.nd;}
    | var SEMI {$$.nd = $1.nd;}
    ;

assignment:
    valRef ASSIGN expr {$$.nd = buildNode($1.nd, $3.nd, "=");}

    | valRef ASSIGN_DIVIDE expr {$$.nd = buildNode($1.nd, $3.nd, "/=");}

    | valRef ASSIGN_MINUS expr {$$.nd = buildNode($1.nd, $3.nd, "-=");}

    | valRef ASSIGN_MOD expr {$$.nd = buildNode($1.nd, $3.nd, "%=");}

    | valRef ASSIGN_MULTIPLY expr {$$.nd = buildNode($1.nd, $3.nd, "*=");}

    | valRef ASSIGN_PLUS expr {$$.nd = buildNode($1.nd, $3.nd, "+=");}

    | assignment ASSIGN expr {$$.nd = buildNode($1.nd, $3.nd, "=");}

    ;
    

d_type:
    K_INTEGER {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }

    | K_STRING {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }

    | K_DOUBLE {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }
 
    ;

expr:
    
     LPAREN expr RPAREN { $$.nd = $2.nd;} 

    | callfunc { $$.nd = $1.nd;}

    | expr MINUS expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr PLUS expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr MULTIPLY expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr DIVIDE expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr MOD expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }
    
    | value { $$.nd = $1.nd; }

    

    ;
    
value:
    ICONSTANT {newSymbol('I', $1.name);}  ////////////////////////////////////////////////////////////////////////
    {
        $$.nd = buildNode(NULL, NULL, $1.name);
    }
    | DCONSTANT {newSymbol('D', $1.name);}   ////////////////////////////////////////////////////////////////////////
    {
        $$.nd = buildNode(NULL, NULL, $1.name);
    }
    | valRef { $$.nd = $1.nd;}

    | MINUS value ////////////////////////////////////////////////////////////////////////

    | callfunc { $$.nd = $1.nd;}

    | SCONSTANT { $$.nd = $1.nd;}

    ;

param_list:
    var { $$.nd = $1.nd; }

    | var COMMA param_list
    { 
        $$.nd = buildNode($1.nd, $3.nd, "Parameter List");
    } 
    | {$$.nd = NULL;}
    ;

// New Code Starts here.



//cody code
condition: expr relop expr
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "condition");
    }
    | condition gate condition
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "gate");
    }
    | NOT condition

    ;

if:  K_IF LPAREN condition RPAREN K_THEN block
    {
        $$.nd=buildNode($3.nd, $6.nd, "if");
    }
    | K_IF LPAREN condition RPAREN K_THEN block K_ELSE block
    {
        $$.nd=buildNode(buildNode($3.nd, $6.nd, "if"), buildNode(NULL, $8.nd, "else"), "ifel");
    }
    ;

ret:
    K_RETURN assignment SEMI
    {
        $$.nd=buildNode(NULL,$2.nd,"return");
        // $$.nd=buildNode(NULL,buildNode(NULL, NULL, $2.name),"return");
    }
    |K_RETURN value SEMI
    {
        $$.nd=buildNode(NULL,$2.nd,"return");
        // $$.nd=buildNode(NULL,buildNode(NULL, NULL, $2.name),"return");
    }
    ;

relop: 
    LT{$$.nd=buildNode(NULL, NULL, $1.name);}

    | GT{$$.nd=buildNode(NULL, NULL, $1.name);}

    | LEQ{$$.nd=buildNode(NULL, NULL, $1.name);}

    | GEQ{$$.nd=buildNode(NULL, NULL, $1.name);}

    | DEQ{$$.nd=buildNode(NULL, NULL, $1.name);}

    | NE{$$.nd=buildNode(NULL, NULL, $1.name);}

    ;

gate:
    DAND{$$.nd=buildNode(NULL, NULL, $1.name);}

    | DOR{$$.nd=buildNode(NULL, NULL, $1.name);}

    ;





//matty code
arg_list:
    value
    {$$.nd=$1.nd;}
    | value COMMA arg_list
    {
        $$.nd=buildNode($1.nd,$3.nd,"arg_list");
    }
    |{$$.nd=NULL;}
    /* {$$ = "_EPSILON_";} */
    ;


reader:
    K_READ_DOUBLE LPAREN expr RPAREN
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "reader");
    }
    | K_READ_INTEGER LPAREN expr RPAREN
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "reader");
    }
    | K_READ_STRING LPAREN SCONSTANT RPAREN
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "reader");
    }
    | K_READ_STRING LPAREN IDENTIFIER RPAREN
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "reader");
    }
    ;

makenummutable:
    DECREMENT
    {
        $$.nd=buildNode(NULL, NULL, "--");
    }
    | INCREMENT
    {
        $$.nd=buildNode(NULL, NULL, "++");
    }
    |
    /* {$$ = "_EPSILON_";} */
    {$$.nd=NULL;}
    
    ;

arrayat: IDENTIFIER LBRACKET ICONSTANT RBRACKET 
    {
        $$.nd=buildNode($1.nd, buildNode(NULL, NULL,$3.name), "arrayat");
    }
    | IDENTIFIER LBRACKET IDENTIFIER makenummutable RBRACKET 
    {
        $$.nd=buildNode($1.nd,buildNode($3.nd, $4.nd, "mutate"), "arrayat");
    }
    | IDENTIFIER LBRACKET expr RBRACKET
    {
        $$.nd=buildNode($1.nd, $3.nd, "arrayat");
    }
    ;

buildarr:
    IDENTIFIER LBRACKET RBRACKET {newSymbol('V',$1.name); $$.nd=buildNode(NULL, NULL, $1.name);}

    ;

callfunc:
    IDENTIFIER LPAREN arg_list RPAREN
    {
        $$.nd=buildNode($1.nd,$3.nd,"callfunc");
    }

    ;

whileloop:
     K_WHILE LPAREN condition RPAREN block
    {
        $$.nd=buildNode($3.nd, $5.nd, "while");
    }
    ;
forcond:
    ICONSTANT {$$.nd=buildNode(NULL,NULL, $1.name);}

    | IDENTIFIER{$$.nd=$1.nd;}
    
    ;
forloop:
    K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block
    {$$.nd=buildNode(buildNode($3.nd, $5.nd, "="),buildNode($7.nd,$12.nd,"++"),"forloop");}

    | K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block
    {$$.nd=buildNode(buildNode($3.nd, $5.nd, "="),buildNode($7.nd,$12.nd,"--"),"forloop");}

    ;
    
valRef:
    IDENTIFIER { newSymbol('V', $1.name); $$.nd=buildNode(NULL, NULL, $1.name);}

    | arrayat{$$.nd=$1.nd;}

    ;
chain:
    var COMMA
    {$$.nd=$1.nd;}
    | assignment COMMA
    {$$.nd=$1.nd;}
    | expr COMMA
    {$$.nd=$1.nd;}
    | chain chain
    {
        $$.nd=buildNode($1.nd,$2.nd,"chain");
    }
    | chain chainend
    {
        $$.nd=buildNode($1.nd,$2.nd,"chain");
    }
    ;
chainend:
    var{ $$.nd = $1.nd; }


    | assignment{ $$.nd = $1.nd; }

    | expr{ $$.nd = $1.nd; }

    ;

%%
extern FILE* yyin;

int main(){
    do{
        yyparse();
        printf("___________________________________________________________________________\n\n");

        for(int i=0; i<st_count; i++) {
            printf("%-25s %-15s\n", InitialSymTab[i].name, InitialSymTab[i].type);
        }
        for(int i=0;i<st_count;i++) {
            free(InitialSymTab[i].name);
            free(InitialSymTab[i].type);
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

int search(char* in){
    for(int i=0; i<st_count; i++){
        if(strcmp(InitialSymTab[i].name, in)==0){
            return -1;
            break;
        }
    }
    return 0;
}

////////////////////////////////// New Symbol Table Stuff //////////////////////////////////////////
void newSymbol(char c, char* stringVal){
    if(!search(stringVal)){
        switch(c){
            case 'I':
                InitialSymTab[st_count].name=strdup(stringVal);
                InitialSymTab[st_count].type=strdup("ICONSTANT");
                st_count++;
                break;
            case 'D': 
                InitialSymTab[st_count].name = strdup(repD(repD(stringVal,'d'),'D'));;
                InitialSymTab[st_count].type=strdup("DCONSTANT");
                st_count++;
                break;
            case 'V':
                InitialSymTab[st_count].name=strdup(stringVal);
                InitialSymTab[st_count].type=strdup(useBuff);
                st_count++;
                break;
            case 'P':
                InitialSymTab[st_count].name=strdup(stringVal);        
                InitialSymTab[st_count].type=strdup("PROCEDURE");    
                st_count++;
                break;
            case 'S':
                InitialSymTab[st_count].name=strdup(stringVal); 
                InitialSymTab[st_count].type=strdup("SCONSTANT");
                st_count++;
                break;
            case 'F':
                InitialSymTab[st_count].name=strdup(stringVal); 
                InitialSymTab[st_count].type=strdup("FUNCTION");
                // Do we want to save the return type of the function?
                //InitialSymTab[st_count].use=strdup(useBuff);
                st_count++;
                break;
            case 'M':
                InitialSymTab[st_count].name=strdup(stringVal); 
                InitialSymTab[st_count].type=strdup("PROGRAM");
                st_count++;
                break;
        }
    }
}


struct node* buildNode( struct node* left, struct node* right, char* token){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->leftchild = left;
    newnode->rightchild = right;
    newnode->token = newstr;

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
    fprintf(stderr, "%s, ", tree->token);
    if (tree->rightchild) {
        printInorder(tree->rightchild);
    }
}


/////////////////////////////////////////code generator because we are bad at linking files/////////////////////////////////////



void execute(struct node* start){//will need to call this in the makeFILE
    FILE* urManeDotH=fopen("yourmain.h", "w+");
    
    fprintf(urManeDotH, "int yourmain() {\n");
    fprintf(urManeDotH, "SR -= %d;\n", st_count);//********
    ST_Stack_init();
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
        
            if(strcmp(yesde->token,"=")==0){
                IndexPair varIndexPair = ST_get_index(yesde->leftchild->token);
                IndexPair valueIndexPair = ST_get_index(yesde->rightchild->token);

                /* InitialSymTab[varIndex].intval = InitialSymTab[valueIndex].intval; */

                assignmentGenerator(1, filename);}
            else if(strcmp(yesde->token,"print statement")==0){
                printStatementGenerator(yesde->rightchild->token, filename);}
            else if(strcmp(yesde->token,"while")==0){

            }
            else if(strcmp(yesde->token,"forloop")==0){

            }
            else if(strcmp(yesde->token,"+=")==0){

            }
            else if(strcmp(yesde->token,"/=")==0){

            }
            else if(strcmp(yesde->token,"-=")==0){

            }
            else if(strcmp(yesde->token,"*=")==0){

            }
            else if(strcmp(yesde->token,"%=")==0){

            }
            else if(strcmp(yesde->token,"callfunc")==0){

            }
            else if(strcmp(yesde->token,"reader")==0){

            }
            else if(strcmp(yesde->token,"arg_list")==0){

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
    
    if (strcmp(InitialSymTab[index].type , "integer")==0) {
        /* fprintf(stderr, "VALUE: %d\n", InitialSymTab[index].intval); */
        /* location = intIn(InitialSymTab[index].intval, SI, IR, filename); */
        IR++;
        InitialSymTab[index].memLoc=strdup(location);
        /* printf("%d\n", InitialSymTab[index].intval); */
    }
    else if(strcmp(InitialSymTab[index].type , "double")==0){
        /* printf("%f\n", InitialSymTab[index].dubval); */
    }
    else if(strcmp(InitialSymTab[index].type , "string")==0){
        /* printf("%s\n", InitialSymTab[index].name); */
        location = strIn(InitialSymTab[index].name, SI, filename);
        IR++;
        InitialSymTab[index].memLoc=strdup(location);
    }
    free(location);
}

IndexPair ST_get_index(char* name){
    for(int i = ST_Stack->top-1; i >= 0; i--){
        int ST_size = ST_Stack->sizes[i];
        for(int j = ST_size-1; j >= 0; j--){
            if(strcmp(ST_Stack->SymTab[i][j].name, name) == 0){
                return (IndexPair) {i, j};
            }
        }
    }
    return (IndexPair){-1,-1};
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
        /* IndexPair indexPair = ST_get_index(name);
        printVar(InitialSymTab[index].memLoc, InitialSymTab[index].type, filename); */
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
    fprintf(stderr, "EAT MY ASS1\n");
    if (strcmp(type , "integer")==0){
        fprintf(filename, "print_integer(%s);\n", memAddress);
    }
    fprintf(stderr, "EAT MY ASS2\n");
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
    
    
// Symbol Table stack/////
// Initialize the stack
void ST_Stack_init() {
    ST_Stack = (struct SymTabStack*) malloc(sizeof(struct SymTabStack));
    ST_Stack->top = -1;
}

// Push an array onto the stack
int push(struct SymTabEntry* entries, int size) {
    if (ST_Stack->top == MAX_ST_STACK_SIZE - 1) {
        return -1; // Stack is full
    }
    ST_Stack->top++;
    memcpy(ST_Stack->SymTab[ST_Stack->top], entries, size * sizeof(struct SymTabEntry));
    ST_Stack->sizes[ST_Stack->top] = size;
    return 0; // Success
}
    
    