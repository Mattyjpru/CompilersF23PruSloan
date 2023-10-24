%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
    int nodeCount = 0;
    int st_loc=0;
    char[16] use;
    //Symbol Table stuff
    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        //char* val;
        int line_no;
    } symbolTable[2048];

    void insert(){
        strcpy(use, yytext);
    }

    void newSymbol(char c){
        int q=search(yytext)
        if(!q)/*?*/{
            switch(c){
                case 'V':

                    st_loc++;
                    break;
                case 'H':

                    st_loc++;
                    break;
                case 'C':

                    st_loc++;
                    break;
                case 'K'

                    st_loc++;
                    break;
                case 'F':

                    st_loc++;
                    break;

            }
        }
    }

    int search(char* use){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbol_table[i], use)==0){
                return -1;
            }
        }
        return 0;
    }
%}

%union {
    int iVal;
    double dVal;
    char  *sVal;
}

%type<sVal> IDENTIFIER SCONSTANT expr param_list block d_type var assignment task function procedure print
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

program: K_PROGRAM {insert_type();} IDENTIFIER{} LCURLY task RCURLY
    {

    };

task: function
    {

    }
    | procedure
    {

    }
    | task function
    {

    }
    | task procedure
    {

    }
    ;

procedure:
    K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {

    }
    | K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {

    }
    ;

function: 
    K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY
    {

    }
    | K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY
    {

    }
    ;

block:
    print           
    {

    }
    | var             
    {

    }
    | assignment             
    {

    }
    | print block     
    {

    }
    | var block       
    {

    }
    | assignment block       
    {

    }
    | epsilon     
    {
        
    }
    ;

print:
    K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI
    {

    }
    | K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI
    {

    }
    | K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI
    {

    }
    | K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI
    {

    }
    | K_PRINT_INTEGER LPAREN expr RPAREN SEMI
    {

    }
    ;

var:
    d_type IDENTIFIER SEMI
    {

    }
    | d_type assignment
    {

    }
    ;

assignment:
    IDENTIFIER ASSIGN ICONSTANT SEMI
    {

    }
    | IDENTIFIER ASSIGN SCONSTANT SEMI
    {

    }
    | IDENTIFIER ASSIGN expr SEMI
    {

    }
    ;
    

d_type:
    K_INTEGER                   
    {

    }
    | K_STRING                    
    {

    }
    ;

expr:
    ICONSTANT                   
    {

    }
    | IDENTIFIER
    {

    }
    | expr MINUS expr             
    {

    }
    | expr PLUS expr              
    {

    }
    | LPAREN expr RPAREN          
    {

    }
    ;


param_list:
    d_type IDENTIFIER                       
    {

    }
    | d_type IDENTIFIER COMMA param_list      
    {

    }
    ;

epsilon: ;

%%
extern FILE* yyin;

int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
