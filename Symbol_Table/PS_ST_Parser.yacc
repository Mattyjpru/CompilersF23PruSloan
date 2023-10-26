%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
    extern char* yytext;
    extern int line;
    extern FILE* yyin;
    int nodeCount = 0;
    int st_loc=0;
    char useBuff[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        char* val;
        int line_no;
    } symbolTable[48];

    void insert(){
        strcpy(useBuff, yytext);
    }

    int searchS(char* in){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].name, in)==0){
                return -1;
            }
        }
        return 0;
    }

    int searchI(int in){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].use, "ICONSTANT")==0)
            {
                if(symbolTable[i].val==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int searchD(double in){
         for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(symbolTable[i].val==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }




    void newSymbol(char c){
        switch(c){
            case 'V':

                symbolTable[st_loc].name=yylval.sVal;
                symbolTable[st_loc].d_type=strdup(useBuff);
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("IDENTIFIER");
                st_loc++;
                break;
            case 'P':
                symbolTable[st_loc].name=strdup(yytext);        
                symbolTable[st_loc].d_type=strdup(useBuff);    
                symbolTable[st_loc].line_no=line;    
                symbolTable[st_loc].use=strdup("PROCEDURE");
                st_loc++;
                break;
            case 'I':
                symbolTable[st_loc].name=strdup(yytext);
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("ICONSTANT");
                st_loc++;
                break;
            case 'D':
                symbolTable[st_loc].name=strdup(yytext);
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("DCONSTANT");
                st_loc++;
                break;
            case 'S':
                symbolTable[st_loc].name=strdup(yytext);
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("SCONSTANT");
                st_loc++;
                break;
            case 'F':
                symbolTable[st_loc].name=strdup(yytext);
                symbolTable[st_loc].d_type=strdup(useBuff);
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("FUNCTION");
                st_loc++;
                break;

        }
    }
%}

%union {
    int iVal;
    double dVal;
    char  *sVal;
}

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

program: K_PROGRAM  IDENTIFIER{newSymbol('V');} LCURLY task RCURLY
    ;

task: function
    {newSymbol('F');}
    | procedure{newSymbol('P');}
    | task function{newSymbol('F');}
    | task procedure{newSymbol('P');}
    ;

procedure:
    K_PROCEDURE IDENTIFIER{newSymbol('V');} LPAREN param_list RPAREN LCURLY block RCURLY
    | K_PROCEDURE{newSymbol('P');} IDENTIFIER{newSymbol('V');} LPAREN RPAREN LCURLY block RCURLY///////////////////////////////////////////////////////////////////////
    ;

function: 
    K_FUNCTION{newSymbol('F');} d_type IDENTIFIER{newSymbol('V');} LPAREN param_list RPAREN LCURLY block RCURLY
    | K_FUNCTION{newSymbol('F');} d_type IDENTIFIER{newSymbol('V');} LPAREN RPAREN LCURLY block RCURLY///////////////////////////////////////////////////////////////////////
    ;

block:
    print           
    {printf("!");}
    | var             
    {printf("!");}
    | assignment             
    {printf("!");}
    | print block     
    {printf("!");}
    | var block       
    {printf("!");}
    | assignment block       
    {printf("!");}
    | epsilon     
   {printf("!");}
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT{newSymbol('C');} RPAREN SEMI
    | K_PRINT_DOUBLE LPAREN DCONSTANT{newSymbol('C');} RPAREN SEMI
    | K_PRINT_STRING LPAREN SCONSTANT{newSymbol('C');} RPAREN SEMI
    | K_PRINT_INTEGER LPAREN IDENTIFIER{newSymbol('V');} RPAREN SEMI
    | K_PRINT_DOUBLE LPAREN IDENTIFIER{newSymbol('V');} RPAREN SEMI
    | K_PRINT_STRING LPAREN IDENTIFIER{newSymbol('V');} RPAREN SEMI
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    {printf("!");}
    ;

var:
    d_type IDENTIFIER{newSymbol('V');} SEMI
    |d_type assignment
    {printf("!");}
    ;

assignment:
    IDENTIFIER{newSymbol('V');} ASSIGN ICONSTANT{newSymbol('C');} SEMI
    | IDENTIFIER{newSymbol('V');} ASSIGN DCONSTANT{newSymbol('C');} SEMI///////////////////////////////////////////////////////////////////////
    | IDENTIFIER{newSymbol('V');} ASSIGN SCONSTANT{newSymbol('C');} SEMI///////////////////////////////////////////////////////////////////////
    | IDENTIFIER{newSymbol('V');} ASSIGN expr SEMI///////////////////////////////////////////////////////////////////////
    ;
    

d_type:
    K_INTEGER{insert();}
    |K_STRING{insert();}
    |K_DOUBLE{insert();}
    ;

expr:
    ICONSTANT{newSymbol('C');}
    | DCONSTANT{newSymbol('C');}
    | IDENTIFIER{newSymbol('V');}
    | expr MINUS expr             
    {printf("!");}
    | expr PLUS expr              
    {printf("!");}
    | LPAREN expr RPAREN          
    {printf("!");}
    ;


param_list:
    d_type IDENTIFIER{newSymbol('V');}                       
    | d_type IDENTIFIER{newSymbol('V');} COMMA param_list      
    ;

epsilon: {printf("!");};

%%

int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    for (int i=0;i<st_loc;i++){
        if(symbolTable[i].name){
            printf("%s",symbolTable[i].name);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].d_type){
            printf("%s",symbolTable[i].d_type);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].use){
            printf("%s",symbolTable[i].use);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].val){
            printf("%s",symbolTable[i].val);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

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
