    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include"lex.yy.c"

access_times = {
    "R": 1,
    "F": 2,
    "Mem": 20,
    "int /": 19,
    "int %": 20,
    "double /": 38,
    "double %": 40,
    "Function call": 100,
    # "Everything else": 1,
    }
    int SI = 0
    int IR = 1
    int FR = 1

void execute(node* start, symbolTable symboltable){//will need to call this in the makefile
    File* urManeDotH=fopen("yourmain.h", 'w');
    global SymbolTable//********
    SymbolTable = symboltable//********
    
    
    fputs("int yourmain() {\n", urManeDotH);
    fputs("SR -= {SymbolTable.get_symbol_counts()};\n", urManeDotH);//********
    walk(start);
    fputs("SR += {SymbolTable.get_symbol_counts()};\n", urManeDotH);//********
    fputs("return 0;\n}", urManeDotH);
    fclose(urManeDotH);
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
    type = SymbolTable.get_type(scope, name)
    value = SymbolTable.get_value(scope, name)
    // print(type)
    // print(value)
    // print(name)
    if (strcmp(type , "integer")==0) (
        memory_location = assign_int(value, SI, IR, file))
        //# IR += 1

    SymbolTable.add_mem(scope, name, memory_location)}
    
///////////////////////////////////////////////////////////////////////////////////////
void print_code(scope, name){//************************************
    if name[0] == '"':
        print_sconstant(name, file)
    else:
        type = SymbolTable.get_type(scope, name)
        mem = SymbolTable.get_mem(scope, name)
        print_variable(mem, type, file)
}

char* intIn(int intVal, int srLoc, int irLoc, file filename){


    // Returns:
    // memory (string): Memory address of the variable
    

    filename.write(f"R[{ir_index}] = {value};\n")
    filename.write(f"F23_Time += 1;\n")
    filename.write(f"Mem[SR + {stack_index}] = R[{ir_index}];\n")
    filename.write(f"F23_Time += 20 + 1;\n")

    return f"Mem[SR + {stack_index}]"}//************************************


void printStr(char* str, file filename){

    filename.write(f"print_string({sconstant});\n")
    filename.write(f"F23_Time += 1;\n")}

char* printVar(char* memAdress, char* type, file filename){

    if type == "integer":
        filename.write(f"print_int({mem});\n")
    filename.write(f"F23_Time += 20 + 1;\n")}


int floatIn(char* scope, char* name, int srLoc, int frLoc, file filename){

    // Returns:
    // fr_index: Current index of next empty float register
    
    value = symbol_find(scope, name)

    filename.write(f"F[{fr_index}] = {value}\n")
    filename.write(f"F23_Time += 1\n")
    filename.write(f"*(double*)Mem[SR + {stack_index}] = F[{fr_index}]\n")
    filename.write(f"F23_Time += 20 + 1\n")
}

void strIn(scope, name):
    """Prints generated code for an string assignment to yourmain.h

    Parameters:
    scope (string): Scope of the symbol
    name (string): Name of the symbol

    Returns:
    """
    