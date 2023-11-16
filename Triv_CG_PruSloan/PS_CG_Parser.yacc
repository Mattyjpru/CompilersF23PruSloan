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
    }

    void insert();
    int search(char*);
    void newSymbol(char, char*);

    // Code Gen stuff
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };
    struct node *head;

    struct node* buildNode(struct node* left, struct node* right, char* token);
    void printtree(struct node* );
    void printInorder(struct node *);

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
}

%token<nd_obj> IDENTIFIER SCONSTANT ICONSTANT DCONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER 
%token<nd_obj> K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER
%token<nd_obj> K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token<nd_obj> ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS 
%token<nd_obj> DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI
%type<nd_obj> statement program task function procedure param_list block d_type print var assignment expr value

%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement 

%%
statement: 
    program { printf("Valid Program\n"); execute(head)};

program: K_PROGRAM IDENTIFIER {newSymbol('M', $2.name);} LCURLY task RCURLY
    {
        $$.nd=buildNode( $5.nd, NULL, $2.name);
        head = $$.nd; 
    }
    |
    ;

task: function {$$.nd = buildNode($1.nd, NULL, "task");}
    | procedure {$$.nd = buildNode($1.nd, NULL, "task");}
    | function task {$$.nd = buildNode($1.nd, $2.nd, "task");}
    | procedure task  {$$.nd = buildNode($1.nd, $2.nd, "task");}
    |
    ;

procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        $$.nd = buildNode($4.nd, $7.nd, $2.name);
    };

function: K_FUNCTION d_type IDENTIFIER {newSymbol('V', $3.name);} LPAREN param_list RPAREN LCURLY block RCURLY
    {
        $$.nd = buildNode($6.nd, $9.nd, $3.name);// $-2 never gets a node
    };

block:
    print               {$$.nd = $1.nd;}//buildNode($1.nd, NULL, "block");}
    | var               {$$.nd = $1.nd;}//buildNode($1.nd, NULL, "block");}
    | assignment        {$$.nd = $1.nd;}//buildNode($1.nd, NULL, "block");}    
    | block block       {$$.nd = buildNode($1.nd, $2.nd, "blocks");}
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI 
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_DOUBLE LPAREN DCONSTANT  RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_INTEGER LPAREN IDENTIFIER  RPAREN SEMI
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), buildNode(NULL, NULL, $3.name), "print statement");
    }
    | K_PRINT_DOUBLE LPAREN IDENTIFIER  RPAREN SEMI
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
    d_type IDENTIFIER {newSymbol('V', $2.name);} SEMI 
    {
        $$.nd = buildNode(buildNode(NULL, NULL, $2.name), NULL, "variable declaration");
    }
    | d_type assignment {$$.nd = $2.nd;}
    ;

assignment:
    IDENTIFIER {newSymbol('V', $1.name);} ASSIGN expr SEMI
    { 
        $$.nd = buildNode(buildNode(NULL, NULL, $1.name), $3.nd, "="); 
    }
    ;
    

d_type:
    K_INTEGER {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }
    |K_STRING {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }
    |K_DOUBLE {insert(); $$.nd = buildNode(NULL, NULL, $1.name); }
    ;

expr:
    value              { $$.nd = $1.nd;} 
    | expr MINUS expr    { $$.nd = buildNode($1.nd, $3.nd, $2.name); }
         
    | expr PLUS expr         { $$.nd = buildNode($1.nd, $3.nd, $2.name); }
     
    | LPAREN expr RPAREN   { $$.nd = $2.nd; }

    ;
    
value:
    ICONSTANT           { newSymbol('I', $1.name); $$.nd = buildNode(NULL, NULL, $1.name); }
    | DCONSTANT         { newSymbol('D', $1.name); $$.nd = buildNode(NULL, NULL, $1.name); }
    | IDENTIFIER        { newSymbol('V', $1.name); $$.nd = buildNode(NULL, NULL, $1.name); }
    ;

param_list:
    d_type IDENTIFIER { newSymbol('V', $2.name); } COMMA param_list
    { 
        $$.nd = buildNode(buildNode(NULL, NULL, $2.name), $5.nd, "Parameter List");
    } 
    | {$$.nd = NULL;}
    ;

/* relop: LT
| GT
| LEQ
| GEQ
| DEQ
| NE
; */

%%
extern FILE* yyin;

int main(){
    /* do{
        yyparse();
        printf("\n\n");
        printf("%-25s %-15s %-15s %-15s\n","SYMBOL", "DATATYPE", "TYPE", "LINE NUMBER");
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
        }
        for(int i=0;i<st_count;i++) {
            free(symbolTable[i].name);
            free(symbolTable[i].d_type);
            free(symbolTable[i].use);
        }
    }while(!feof(yyin));
    printf("\n\n");
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
    printf("Built a node: %s\n", newstr);
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



void execute(node* start, symbolTable symboltable){//will need to call this in the makefile
    File* urManeDotH=fopen("yourmain.h", 'w');
    /* global SymbolTable//********
    SymbolTable = symboltable//******** */
    
    // Not sure what the equivalent of "symbolTable.get_symbol_counts()" is, but we are going to try
    // st_count
    fprintf(urManeDotH, "int yourmain() {\n");
    fprintf(urManeDotH, "SR -= %d;\n", st_count);//********
    walk(start);
    fprintf(urManeDotH, "SR += %d;\n", st_count);//********
    fprintf(urManeDotH, "return 0;\n}");
    fclose(urManeDotH);
    }

int times(char* query){
    int out=0;
    switch(query){
        case "Function call":
            out=100;
            break;
        case "Mem access":
            out=20;
            break;
        case "int /":
            out=19;
            break;
        case "double /":
            out=38;
            break;
        case "int %":
            out=20;
            break;
        case "double %":
            out=40;
            break;
        case "R":
            out=1;
            break;
        case "F":
            out=2;
            break;
    }
    return out;
}

void walk(node* yesde){
        if (yesde->token == "=":){
            assign_code("statements", yesde->rightchild->token)
        }
            
        else if (yesde->token == "print statement":){
            print_code("statements", yesde->leftchild->token)
        }
            
        else{
            if (yesde->leftchild) {
                walk(yesde->leftchild);
            }
            if (yesde->leftchild) {
                walk(tree->leftchild);
            }
        }
    }
    
void assign_code(scope, name){//************************************
    int index = ST_get_index(name);
    if(index == -1){
        printf("AHHHH WHTATAT THE FUKC SJDINFS\n");
        exit(0);
    }
    char *type = symbolTable[index].d_type;

    printf("%s\n", type)

    if (strcmp(type , "integer")==0) {
        memory_location = intIn(symbolTable[index].intval, SI, IR, file);
        strcpy(symbolTable[index].memLoc, memory_location);
        //# IR += 1
        printf("%d\n", symbolTable[index].intval);
    }
    else if(strcmp(type , "double")==0){
        printf("%f.25\n", symbolTable[index].dubval);
    }
    else if(strcmp(type , "string")==0){
        printf("%s\n", symbolTable[index].name);
    }

    
}

char* ST_get_index(name){
    for(int i = 0; i < st_count; i++){
        if(strcmp(symbolTable[i].name, name) == 0){
            return i;
        }
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////
void print_code(scope, name){//************************************
    if name[0] == '"':
        print_sconstant(name, file)
    else:
        type = SymbolTable.get_type(scope, name)
        mem = SymbolTable.get_mem(scope, name)
        print_variable(mem, type, file)
}

char* intIn(int intVal, int sLoc, int irLoc, File* filename){
    fprintf(filename,"R[%d] = %d;\n" , irLoc, intval);
    fprintf(filename, "F23_Time += 1;\n",);
    fprintf(filename, "Mem[SR + %d] = R[%d];\n", sLoc, irLoc);
    
    fprintf(filename, "F23_Time += 20 + 1;\n",);
    char buff[20];
    sprintf(buff, "Mem[SR + %d]", sLoc)
    return buff;
    }//************************************


void printStr(char* str, File* filename){

    fprintf(filename, "print_string(%s);\n", str);
    fprintf(filename, "F23_Time += 1;\n");
}
char* printVar(char* memAdress, char* type, File* filename){

    (strcmp(type , "integer")==0){
        fprintf(filename, "print_int(%s);\n", memAddress);
    }

    fprintf(filename, "F23_Time += 20 + 1;\n");
}



void strIn(scope, name):
    """Prints generated code for an string assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    """
    