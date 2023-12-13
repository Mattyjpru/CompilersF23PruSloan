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
    program { printf("\nValid Program\n"); execute(head);};

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

procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        $$.nd = buildNode($4.nd, $7.nd, $2.name);
    }
    ;

function: K_FUNCTION d_type IDENTIFIER {newSymbol('V', $3.name);} LPAREN param_list RPAREN LCURLY block RCURLY
    {
        $$.nd = buildNode($6.nd, $9.nd, $3.name);
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

    | IDENTIFIER /*{newSymbol('V', $3.name);}*/ makenummutable SEMI /*{$$.nd = $3.nd;}  NOT SURE HOW TO DO THIS ONE*/

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
    | K_PRINT_INTEGER LPAREN valRef RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_DOUBLE LPAREN valRef RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
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
    valRef ASSIGN expr 

    | valRef ASSIGN_DIVIDE expr 

    | valRef ASSIGN_MINUS expr 

    | valRef ASSIGN_MOD expr 

    | valRef ASSIGN_MULTIPLY expr 

    | valRef ASSIGN_PLUS expr 

    | assignment ASSIGN expr

    ;
    

d_type:
    K_INTEGER {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }

    | K_STRING {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }

    | K_DOUBLE {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }
 
    ;

expr:
    value { $$.nd = $1.nd; }

    | callfunc { $$.nd = $1.nd;}

    | expr MINUS expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr PLUS expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr MULTIPLY expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr DIVIDE expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | expr MOD expr { $$.nd = buildNode($1.nd, $3.nd, $2.name); }

    | LPAREN expr RPAREN { $$.nd = $2.nd;} 

    ;
    
value:
    ICONSTANT makenummutable ////////////////////////////////////////////////////////////////////////

    | DCONSTANT makenummutable  ////////////////////////////////////////////////////////////////////////

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

    | condition gate condition

    | NOT condition

    ;

if: K_IF LPAREN condition RPAREN K_THEN block

    | K_IF LPAREN condition RPAREN K_THEN block K_ELSE block

    ;

ret:
    K_RETURN value SEMI

    |K_RETURN assignment SEMI

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

    | DOR

    ;





//matty code
arg_list:
    value

    | value COMMA arg_list

    |
    /* {$$ = "_EPSILON_";} */
    ;


reader:
    K_READ_DOUBLE LPAREN expr RPAREN

    | K_READ_INTEGER LPAREN expr RPAREN

    | K_READ_STRING LPAREN SCONSTANT RPAREN

    | K_READ_STRING LPAREN IDENTIFIER RPAREN

    ;

makenummutable:
    DECREMENT

    | INCREMENT

    |
    /* {$$ = "_EPSILON_";} */
    
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
     K_WHILE LPAREN condition RPAREN block

    ;
forcond:
    ICONSTANT

    | IDENTIFIER
    /* {
        printf("Node %d: Reduced: forcond: IDENTIFIER\n", nodeCount++);
        printf("\t Terminal Symbol: IDENTIFIER\n");
        $$ = "IDENTIFIER";
    } */
    ;
forloop:
    K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER INCREMENT RPAREN block

    | K_DO LPAREN IDENTIFIER ASSIGN forcond SEMI condition SEMI IDENTIFIER DECREMENT RPAREN block


    ;
    
valRef:
    IDENTIFIER

    | arrayat

    ;
chain:
    var COMMA

    | assignment COMMA

    | expr COMMA


    | chain chain

    | chain chainend

    ;
chainend:
    var


    | assignment

    | expr

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
    
    

    
    