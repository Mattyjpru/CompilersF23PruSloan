%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    }node;
    struct node *head;

    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }

    int yylex();
    extern char* yytext;
    extern int line;
    extern int yylineno;
    // int nodeCount = 0;
    int st_count=0;
    char useBuff[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        int intval;
        float dubval;
        int line_no;
    } symbolTable[48];

    node* buildNode( node*, node*, char*);
    void printtree(struct node* );
    void printInorder(struct node *);

    void insert();
    int search(char*);
    // int search_I(int);
    // int search_D(double);
    void newSymbol(char, char*);
    // void newSymbol_I(int);
    // void newSymbol_D(double);
%}

%union {
    struct nt1 { 
		char name[100];
        char dt[100];
		struct node* nd;
	} nd_obj; 
}

%token<nd_obj> IDENTIFIER SCONSTANT ICONSTANT DCONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER 
%token<nd_obj> K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER
%token<nd_obj> K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token<nd_obj> ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS 
%token<nd_obj> DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI
%type<nd_obj> statement program task function procedure param_list block d_type print var assignment epsilon expr

%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement 

%%
statement: 
    program { printf("Valid Program\n"); };

program: K_PROGRAM IDENTIFIER{newSymbol('M', $2);}  LCURLY task RCURLY
    {
        $$.nd=buildNode($2,$4,$2); 
        head=$$.nd;
    }
    ;

task: function
    | procedure
    | task function
    | task procedure
    ;

procedure:

    |K_PROCEDURE IDENTIFIER {newSymbol('P', $2);} LPAREN param_list RPAREN LCURLY block RCURLY
    
    ;

function: 
    K_FUNCTION d_type IDENTIFIER {newSymbol('F', $3);} LPAREN param_list RPAREN LCURLY block RCURLY

    ;

block:
    print                   { $$.nd = buildNode(NULL, NULL, "printf"); } 
    | var             
    | assignment            { $$.nd = $1.nd; }
    | print block     
    | var block       
    | assignment block       
    | epsilon     

    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT { newSymbol('I',$3); } RPAREN SEMI 
    | K_PRINT_DOUBLE LPAREN DCONSTANT { newSymbol('D', $3); } RPAREN SEMI 
    | K_PRINT_STRING LPAREN SCONSTANT { newSymbol('S', $3); } RPAREN SEMI 
    | K_PRINT_INTEGER LPAREN IDENTIFIER { newSymbol('V', $3); } RPAREN SEMI 
    | K_PRINT_DOUBLE LPAREN IDENTIFIER { newSymbol('V', $3); } RPAREN SEMI 
    | K_PRINT_STRING LPAREN IDENTIFIER { newSymbol('V', $3); } RPAREN SEMI 
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    ;

var:
    d_type IDENTIFIER{newSymbol('V', $2);} SEMI
    { $1.nd = buildNode(NULL, NULL, $1.name); $$.nd = buildNode($1.nd, $3.nd, "="); }
    | d_type assignment
    ;

assignment:
    IDENTIFIER {newSymbol('V', $1);} ASSIGN expr SEMI
    ;
    

d_type:
    K_INTEGER { insert(); }
    |K_STRING { insert(); }
    |K_DOUBLE { insert(); }
    ;

expr:
    ICONSTANT               { newSymbol('I',$1); $$.nd = buildNode(NULL, NULL, $1.name); }
    | DCONSTANT             { newSymbol('D', $1);  $$.nd = buildNode(NULL, NULL, $1.name); }
    | IDENTIFIER            { newSymbol('V', $1); $$.nd = buildNode(NULL, NULL, $1.name); }
    | expr MINUS expr       { $$.nd = buildNode($1.nd, $3.nd, $2.name); }  
    | expr PLUS expr        { $$.nd = buildNode($1.nd, $3.nd, $2.name); }      
    | LPAREN expr RPAREN   
    ;


param_list:
    var                   
    | var COMMA param_list  
    |epsilon
    ;

epsilon: ;

/* relop: LT
| GT
| LEQ
| GEQ
| DEQ
| NE
; */

%%
extern FILE* yyin;

/* int main(){
    do{
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
    return 0;
} */
    void insert(){
        strcpy(useBuff, yytext);
    }

    /* int search_S(char* in){
        for(int i=0; i<st_count; i++){
            if((strcmp(symbolTable[i].use, "ICONSTANT") != 0) && (strcmp(symbolTable[i].use, "DCONSTANT") != 0)){
                if(strcmp(symbolTable[i].name, in)==0){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int search_I(int in){
        for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].use, "ICONSTANT")==0)
            {
                if(symbolTable[i].intval==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int search_D(double in){
         for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(symbolTable[i].dubval==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    } */

    /* void newSymbol_S(char c, char* stringVal){
        if(!search_S(stringVal)){
            switch(c){
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

    void newSymbol_I(int iconstVal){
        if(!search_I(iconstVal)){
            symbolTable[st_count].intval=iconstVal;
            symbolTable[st_count].d_type=strdup("CONST");
            symbolTable[st_count].line_no=line;
            symbolTable[st_count].use=strdup("ICONSTANT");
            st_count++;
        }
    }

    void newSymbol_D(double dconstVal){
        if(!search_D(dconstVal)){
            symbolTable[st_count].dubval=dconstVal;
            symbolTable[st_count].d_type=strdup("CONST");
            symbolTable[st_count].line_no=line;
            symbolTable[st_count].use=strdup("DCONSTANT");
            st_count++;
        }
    } */


////////////////////////// New Symbol Table Stuff ///////////////////////////////////////////////
void newSymbol(char c, char* stringVal){
        if(!search_S(stringVal)){
            switch(c){
                case 'I':
                    symbolTable[st_count].name=strdup(stringVal);        
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;    
                    symbolTable[st_count].use=strdup("PROCEDURE");
                    st_count++;
                    break;
                case 'D':
                    symbolTable[st_count].name=strdup(stringVal);   
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


////////////////////////////below may need tweaking/////////////////////////////////
    node* buildNode( node* leftchild, node* rightchild, char* token){
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        char *newstr = (char*) malloc(strlen(token)+1);
        strcpy(newstr, token);
        newnode->left = left;
        newnode->right = right;
        newnode->token = newstr;
        return(newnode);
    }

    void printtree(struct node* tree) {
        printf("\n\n Inorder traversal of the Parse Tree: \n\n");
        printInorder(tree);
        printf("\n\n");
    }

    void printInorder(struct node *tree) {
        int i;
        if (tree->left) {
            printInorder(tree->left);
        }
        printf("%s, ", tree->token);
        if (tree->right) {
            printInorder(tree->right);
        }
    }
