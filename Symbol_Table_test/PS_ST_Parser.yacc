%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include"lex.yy.c"
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
        int line_no;
    } symbolTable[48];

    void insert();
    int search_S(char*);
    // int search_I(char*);
    // int search_D(char*);
    void newSymbol_S(char);
    // void newSymbol_I();
    // void newSymbol_D();
%}

%union {
    int iVal;
    double dVal;
    char  *sVal;
}



%token IDENTIFIER SCONSTANT DCONSTANT ICONSTANT K_DO K_DOUBLE K_ELSE K_EXIT K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS DECREMENT MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI
%left MINUS PLUS
//%left DIVIDE MULTIPLY
%start statement

%%
statement: 
    program { printf("Valid Program\n"); };

program: K_PROGRAM IDENTIFIER{newSymbol_S('M');} LCURLY task RCURLY
    ;

task: function
    | procedure
    | task function
    | task procedure
    ;

procedure:

    |K_PROCEDURE IDENTIFIER {newSymbol_S('P');} LPAREN param_list RPAREN LCURLY block RCURLY
    
    ;

function: 
    K_FUNCTION d_type IDENTIFIER {newSymbol_S('F');} LPAREN param_list RPAREN LCURLY block RCURLY

    ;

block:
    print           

    | var             

    | assignment             
/* 
    | print block     

    | var block       

    | assignment block        */

    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT { newSymbol_S('I'); } RPAREN SEMI 
    | K_PRINT_DOUBLE LPAREN DCONSTANT { newSymbol_S('D'); } RPAREN SEMI 
    | K_PRINT_STRING LPAREN SCONSTANT { newSymbol_S('S'); } RPAREN SEMI 
    | K_PRINT_INTEGER LPAREN IDENTIFIER { newSymbol_S('V'); } RPAREN SEMI 
    | K_PRINT_DOUBLE LPAREN IDENTIFIER { newSymbol_S('V'); } RPAREN SEMI 
    | K_PRINT_STRING LPAREN IDENTIFIER { newSymbol_S('V'); } RPAREN SEMI 
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    ;

var:
    d_type {newSymbol_S('V');} IDENTIFIER  SEMI 
    ;

assignment:
    d_type IDENTIFIER {newSymbol_S('V');} ASSIGN expr SEMI
    |
    IDENTIFIER {newSymbol_S('V');} ASSIGN expr SEMI
    ;
    

d_type:
    K_INTEGER { insert(); }
    |K_STRING { insert(); }
    |K_DOUBLE { insert(); }
    ;

expr:
    ICONSTANT { newSymbol_S('I'); }
    | DCONSTANT { newSymbol_S('D'); }
    | IDENTIFIER { newSymbol_S('V');}
    | expr MINUS expr             
    | expr PLUS expr              
    | LPAREN expr RPAREN
    | epsilon
    ;


param_list:
    d_type IDENTIFIER { newSymbol_S('V'); }                       
    | d_type IDENTIFIER{ newSymbol_S('V'); } COMMA param_list  
    |epsilon
    ;

epsilon: ;

%%
extern FILE* yyin;

int main(){
    do{
        yyparse();
        printf("\n\n");
        printf("%-25s %-15s %-15s %-15s\n","SYMBOL", "DATATYPE", "TYPE", "LINE NUMBER");
        printf("___________________________________________________________________________\n\n");

        for(int i=0; i<st_count; i++) {
            printf("%-25s %-15s %-15s %-15d\n", symbolTable[i].name, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
        }
        for(int i=0;i<st_count;i++) {
            free(symbolTable[i].name);
            free(symbolTable[i].d_type);
            free(symbolTable[i].use);
        }
    }while(!feof(yyin));
    return 0;
}
    void insert(){
        strcpy(useBuff, yytext);
    }

    int search_S(char* in){
        for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].name, in)==0){
                return -1;
                break;
            }
        }
        return 0;
    }

    /* int search_I(char* in){
        for(int i=0; i<st_count; i++){
            
        }
        return 0;
    }

    int search_D(char* in){
         for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(strcmp(symbolTable[i].name, in)==0){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    } */

    void newSymbol_S(char c){
        printf("%s\n", yytext);
        if(!search_S(yytext)){
            switch(c){
                case 'I':
                    symbolTable[st_count].name=strdup(yytext);
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("ICONSTANT");
                    st_count++;
                    break;
                case 'D':
                    symbolTable[st_count].name=strdup(yytext);
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("DCONSTANT");
                    st_count++;
                case 'V':
                    symbolTable[st_count].name=strdup(yytext);
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("IDENTIFIER");
                    st_count++;
                    break;
                case 'P':
                    symbolTable[st_count].name=strdup(yytext);        
                    symbolTable[st_count].d_type=strdup("void");    
                    symbolTable[st_count].line_no=line;    
                    symbolTable[st_count].use=strdup("PROCEDURE");
                    st_count++;
                    break;
                case 'S':
                    symbolTable[st_count].name=strdup(yytext); 
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("SCONSTANT");
                    st_count++;
                    break;
                case 'F':
                    symbolTable[st_count].name=strdup(yytext); 
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("FUNCTION");
                    st_count++;
                    break;
                case 'M':
                    symbolTable[st_count].name=strdup(yytext); 
                    symbolTable[st_count].d_type=strdup("N/A");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("PROGRAM");
                    st_count++;
                    break;
            }
        }
    }

    /* void newSymbol_I(){
        if(!search_I(yytext)){
            symbolTable[st_count].name=strdup(yytext);
            symbolTable[st_count].d_type=strdup("CONST");
            symbolTable[st_count].line_no=line;
            symbolTable[st_count].use=strdup("ICONSTANT");
            st_count++;
        }
    }

    void newSymbol_D(){
        if(!search_D(yytext)){
            
        }
    } */

