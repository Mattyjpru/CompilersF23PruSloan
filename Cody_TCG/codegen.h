    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include"lex.yy.c"


    int SI = 0
    int IR = 1
    int FR = 1

void execute(node* start, symbolTable symboltable){//will need to call this in the makefile
    File* urManeDotH=fopen("yourmain.h", 'w');
    global SymbolTable//********
    SymbolTable = symboltable//********
    
    
    fprintf(urManeDotH, "int yourmain() {\n");
    fprintf(urManeDotH, "SR -= %d;\n", SymbolTable.get_symbol_counts());//********
    walk(start);
    fprintf(urManeDotH, "SR += %d;\n", SymbolTable.get_symbol_counts());//********
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
    type = SymbolTable.get_type(scope, name)//
    value = SymbolTable.get_value(scope, name)//
    // print(type)
    // print(value)
    // print(name)
    if (strcmp(type , "integer")==0) (
        memory_location = assign_int(value, SI, IR, file))
        //# IR += 1

    SymbolTable.add_mem(scope, name, memory_location)}//********************************
    
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
    