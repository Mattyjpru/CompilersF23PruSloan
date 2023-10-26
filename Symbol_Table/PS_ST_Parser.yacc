%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();

    extern FILE* yyin;
    extern char* yytext;
    extern int line;
    // int nodeCount = 0;
    int st_loc=0;
    char useBuff[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        char* val;
        int intval;
        float dubval;
        int line_no;
    } symbolTable[48];

    void insert(){
        strcpy(useBuff, yytext);
    }

    int search_S(char* in){
        for(int i=0; i<st_loc; i++){
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
        for(int i=0; i<st_loc; i++){
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
         for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(symbolTable[i].dubval==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }




    void newSymbol_S(char c, char* stringVal){
        if(!search_S(stringVal)){
            switch(c){
                case 'V':
                    symbolTable[st_loc].name=strdup(stringVal);
                    symbolTable[st_loc].d_type=strdup(useBuff);
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("IDENTIFIER");
                    st_loc++;
                    break;
                case 'P':
                    symbolTable[st_loc].name=strdup(stringVal);        
                    symbolTable[st_loc].d_type=strdup("void");    
                    symbolTable[st_loc].line_no=line;    
                    symbolTable[st_loc].use=strdup("PROCEDURE");
                    st_loc++;
                    break;
                case 'S':
                    symbolTable[st_loc].name=strdup(stringVal); 
                    symbolTable[st_loc].d_type=strdup("CONST");
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("SCONSTANT");
                    st_loc++;
                    break;
                case 'F':
                    symbolTable[st_loc].name=strdup(stringVal); 
                    symbolTable[st_loc].d_type=strdup(useBuff);
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("FUNCTION");
                    st_loc++;
                    break;
                case 'M':
                    symbolTable[st_loc].name=strdup(stringVal); 
                    symbolTable[st_loc].d_type=strdup("N/A");
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("PROGRAM");
                    st_loc++;
                    break;
            }
        }
    }

    void newSymbol_I(int iconstVal){
        if(!search_I(iconstVal)){
            symbolTable[st_loc].intval=iconstVal;
            symbolTable[st_loc].d_type=strdup("CONST");
            symbolTable[st_loc].line_no=line;
            symbolTable[st_loc].use=strdup("ICONSTANT");
            st_loc++;
        }
    }

    void newSymbol_D(double dconstVal){
        if(!search_D(dconstVal)){
            symbolTable[st_loc].dubval=dconstVal;
            symbolTable[st_loc].d_type=strdup("CONST");
            symbolTable[st_loc].line_no=line;
            symbolTable[st_loc].use=strdup("DCONSTANT");
            st_loc++;
        }
    }
%}

%union {
    int iVal;
    double dVal;
    char  *sVal;
};

%type<sVal> IDENTIFIER SCONSTANT 
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
        newSymbol_S('M', $2); // Added the M symbol for program. Didn't know what else to put, P was already taken
    }
    ;

task: function
    | procedure
    | task function
    | task procedure
    ;

procedure:
    K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        newSymbol_S('P', $2);
    }
    | K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        newSymbol_S('P', $2);
    }
    ;

function: 
    K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {
        newSymbol_S('F', $3);
    }
    | K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {
        newSymbol_S('F', $3);
    }
    ;

block:
    print           

    | var             

    | assignment             

    | print block     

    | var block       

    | assignment block       

    | epsilon     

    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI { newSymbol_I($3); }
    | K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI { newSymbol_D($3); }
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI { newSymbol_S('S', $3); }
    | K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI { newSymbol_S('V', $3); }
    | K_PRINT_DOUBLE LPAREN IDENTIFIER RPAREN SEMI { newSymbol_S('V', $3); }
    | K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI { newSymbol_S('V', $3); }
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    ;

var:
    d_type IDENTIFIER SEMI {newSymbol_S('V', $2);}
    | d_type assignment
    ;

assignment:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    {
        newSymbol_S('V', $1);
        newSymbol_I($3);
    }
    | IDENTIFIER ASSIGN DCONSTANT SEMI
    {
        newSymbol_S('V', $1);
        newSymbol_D($3);
    }
    | IDENTIFIER ASSIGN SCONSTANT SEMI
    {
        newSymbol_S('V', $1);
        newSymbol_S('S', $3);
    }
    | IDENTIFIER ASSIGN expr SEMI { newSymbol_S('V', $1); }
    ;
    

d_type:
    K_INTEGER { insert(); }
    |K_STRING { insert(); }
    |K_DOUBLE { insert(); }
    ;

expr:
    ICONSTANT { newSymbol_I($1); }
    | DCONSTANT { newSymbol_D($1); }
    | IDENTIFIER { newSymbol_S('V', $1); }
    | expr MINUS expr             
    | expr PLUS expr              
    | LPAREN expr RPAREN          
    /* {printf("!");} */
    ;


param_list:
    d_type IDENTIFIER { newSymbol_S('V', $2); }                       
    | d_type IDENTIFIER COMMA param_list { newSymbol_S('V', $2); }  
    ;

epsilon: ;

%%

int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    for (int i=0;i<st_loc;i++){
/////////////////////////////////////////////////////name
        if(symbolTable[i].name){
            printf("%s",symbolTable[i].name);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
/////////////////////////////////////////////////////data type
        if(symbolTable[i].d_type){
            printf("%s",symbolTable[i].d_type);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
/////////////////////////////////////////////////////use
        if(symbolTable[i].use){
            printf("%s",symbolTable[i].use);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
/////////////////////////////////////////////////////value
        if(symbolTable[i].val){
            printf("%s",symbolTable[i].val);
            printf("\t");
        }
        else if(symbolTable[i].intval){
            printf("%d",symbolTable[i].intval);
            printf("\t");
        }
        else if(symbolTable[i].dubval){
            printf("%f",symbolTable[i].dubval);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
/////////////////////////////////////////////////////line number
        if(symbolTable[i].line_no){
            printf("%d",symbolTable[i].line_no);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
    }
    // code generator goes here
}
