%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int nodeID = 0;
    void add(char);
    void insert_type();
    int search(char *);

    struct dataType {
        char * id_name;
        int intVal;
        double doubleVal;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[100];

    int count=0;
    int q;
    char type[10];
    extern int countn;
%}

%union {
    int integer_val;
    double double_val;
    char* string_val;
}

%token K_DO K_DOUBLE K_ELSE K_EXIT
%token K_FUNCTION K_IF K_INTEGER K_PRINT_DOUBLE K_PRINT_INTEGER K_PRINT_STRING K_PROCEDURE K_PROGRAM K_READ_DOUBLE 
%token K_READ_INTEGER K_READ_STRING K_RETURN K_STRING K_THEN K_WHILE ASSIGN ASSIGN_PLUS ASSIGN_MINUS ASSIGN_MULTIPLY
%token ASSIGN_DIVIDE ASSIGN_MOD COMMA COMMENT DAND DIVIDE DOR DEQ GEQ GT LBRACKET LEQ LCURLY LPAREN LT MINUS DECREMENT
%token MOD MULTIPLY NE NOT PERIOD PLUS INCREMENT RBRACKET RCURLY RPAREN SEMI IDENTIFIER SCONSTANT ICONSTANT DCONSTANT

%type<string_val> IDENTIFIER SCONSTANT variable variables array function_call
%type<integer_val> ICONSTANT
%type<double_val> DCONSTANT

%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%left DOR
%left DAND
%nonassoc K_THEN
%nonassoc K_ELSE
%right NOT
%start program
%right INCREMENT DECREMENT

%%

program: K_PROGRAM {insert_type();} IDENTIFIER {add('V');} LCURLY function_list RCURLY;

function_list: procedure 
    | function 
    | function_list function
    | function_list procedure;


function: K_FUNCTION data_type IDENTIFIER {add('F');} LPAREN param_list RPAREN LCURLY statement_list RCURLY;

procedure: K_PROCEDURE IDENTIFIER {add('P');} LPAREN param_list RPAREN LCURLY statement_list RCURLY;

variable: IDENTIFIER {add('V');}
         | array;

variables: variable
         | variable COMMA variables;

param_list: 
          | param
          | param COMMA opt_param_list;

opt_param_list: param
              | param COMMA opt_param_list;

arg_list: 
         | expr
         | expr COMMA opt_arg_list;

opt_arg_list: expr
            | expr COMMA opt_arg_list;

param: data_type variable;

array: IDENTIFIER {add('V');} LBRACKET index RBRACKET;

index: 
         | expr;

data_type: K_DOUBLE {insert_type();}
         | K_INTEGER {insert_type();}
         | K_STRING {insert_type();};

statement_list: statement
              | statement_list statement;

statement: procedure
         | var_declaration SEMI
         | assignment SEMI
         | print_stmt SEMI
         | read_stmt SEMI
         | function_call SEMI
         | if_stmt
         | while_stmt
         | do_stmt
         | variable INCREMENT SEMI
         | variable DECREMENT SEMI
         | variable ASSIGN_PLUS expr SEMI
         | variable ASSIGN_MINUS expr SEMI
         | variable ASSIGN_MULTIPLY expr SEMI
         | variable ASSIGN_DIVIDE expr SEMI
         | variable ASSIGN_MOD expr SEMI
         | return_stmt SEMI;

var_declaration: data_type variable opt_assignment opt_declaration;

opt_declaration: 
         | COMMA variable opt_assignment opt_declaration;

assignment: variables ASSIGN expr opt_assignment;

opt_assignment: 
         | ASSIGN expr opt_assignment;

print_stmt: print_function LPAREN expr RPAREN;

print_function: K_PRINT_DOUBLE 
              | K_PRINT_INTEGER 
              | K_PRINT_STRING;

read_stmt: read_function LPAREN variable RPAREN;

read_function: K_READ_DOUBLE 
             | K_READ_INTEGER
             | K_READ_STRING;

function_call: IDENTIFIER LPAREN arg_list RPAREN;

if_stmt: K_IF LPAREN condition RPAREN K_THEN body
    | K_IF LPAREN condition RPAREN K_THEN body K_ELSE body;
   
body: statement
    | LCURLY statement_list RCURLY;

while_stmt: K_WHILE LPAREN condition RPAREN statement
    | K_WHILE LPAREN condition RPAREN LCURLY statement_list RCURLY;

do_stmt: K_DO LPAREN assignment SEMI condition SEMI expr RPAREN statement
    | K_DO LPAREN assignment SEMI condition SEMI expr RPAREN LCURLY statement_list RCURLY;

return_stmt: K_RETURN expr
    | K_RETURN variable ASSIGN expr;

expr: variable 
    | ICONSTANT {add('I');}
    | DCONSTANT {add('D');}
    | SCONSTANT {add('S');}
    | expr PLUS expr 
    | expr MINUS expr 
    | expr MULTIPLY expr
    | expr DIVIDE expr
    | expr MOD expr
    | MINUS expr
    | expr INCREMENT
    | expr DECREMENT
    | LPAREN expr RPAREN
    | function_call;

condition: expr DEQ expr
    | expr LT expr
    | expr LEQ expr
    | expr GT expr
    | expr GEQ expr
    | expr NE expr
    | NOT condition
    | condition DAND condition
    | condition DOR condition;
%%

int main() {
    do{
        yyparse();
        printf("\n\n");
        printf("SYMBOL\t\t\t\tDATATYPE\tTYPE\t\tLINE NUMBER \n");
        printf("___________________________________________________________________________\n\n");
        int i = 0;
        for(i=0; i<count; i++) {
            if(strcmp(symbol_table[i].type, "ICONSTANT") == 0){
                printf("%-25d\t%-15s\t%-15s\t%-15d\n", symbol_table[i].intVal, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
            }
            else if(strcmp(symbol_table[i].type, "DCONSTANT") == 0){
                printf("%-25f\t%-15s\t%-15s\t%-15d\n", symbol_table[i].doubleVal, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
            }
            else{
                printf("%-25s\t%-15s\t%-15s\t%-15d\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
            }
        }
        for(i=0;i<count;i++) {
            free(symbol_table[i].id_name);
            free(symbol_table[i].type);
        }
        printf("\n\n");
    }while(!feof(yyin));
    return 0;
}

int searchString(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].type,"ICONSTANT")!=0 && strcmp(symbol_table[i].type, "DCONSTANT")!=0){
            if(strcmp(symbol_table[i].id_name, type)==0) {
                return -1;
                break;
            }
        }
	}
	return 0;
}

int searchInt(int val){
	int i;
	for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].type, "ICONSTANT") == 0){
            if(symbol_table[i].intVal == val) {
                return -1;
                break;
            }
        }
	}
	return 0;
}

int searchDouble(double val){
	int i;
	for(i=count-1; i>=0; i--) {
        if(strcmp(symbol_table[i].type, "DCONSTANT") == 0){
            if(symbol_table[i].doubleVal == val) {
                return -1;
                break;
            }
        }
	}
	return 0;
}

void add(char c) {
    if(c == 'V') {
        q=searchString(yylval.string_val);
        if(!q){
            symbol_table[count].id_name=strdup(yylval.string_val);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("IDENTIFIER");
            count++;
        }
	}
	else if(c == 'I') {
         q=searchInt(yylval.integer_val);
        if(!q){
            symbol_table[count].intVal=yylval.integer_val;
            symbol_table[count].data_type=strdup("integer");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("ICONSTANT");
            count++;
        }
	}
	else if(c == 'D') {
        q=searchDouble(yylval.double_val);
        if(!q){
            symbol_table[count].doubleVal=yylval.double_val;
            symbol_table[count].data_type=strdup("double");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("DCONSTANT");
            count++;
        }
	}
	else if(c == 'S') {
        q=searchString(yylval.string_val);
        if(!q){
            symbol_table[count].id_name=strdup(yylval.string_val);
            symbol_table[count].data_type=strdup("string");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("SCONSTANT");
            count++;
        }
	}
    else if(c == 'F') {
        q=searchString(yylval.string_val);
        if(!q){
            symbol_table[count].id_name=strdup(yylval.string_val);
            symbol_table[count].data_type=strdup(type);
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("FUNCTION");   
            count++;
        }  
    }
    else if(c == 'P') {
        q=searchString(yylval.string_val);
        if(!q){
            symbol_table[count].id_name=strdup(yylval.string_val);
            symbol_table[count].data_type=strdup("void");
            symbol_table[count].line_no=countn;
            symbol_table[count].type=strdup("PROCEDURE");   
            count++;
        }  
    }
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
