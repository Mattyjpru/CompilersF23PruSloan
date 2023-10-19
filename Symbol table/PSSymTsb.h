#include<string.h>
#include<stdio.h>

// symbolTable[];
// //memset(symbolTable, 1, 1024);

struct ICONSTANT{
    char* name;
    char* d_type;
    char* use;
    int line_no;
} symbolTable[0];

struct SCONSTANT{
    char* name;
    char* d_type;
    char* use;
    int line_no;
} symbolTable[0];

struct DCONSTANT{
    char* name;
    char* d_type;
    char* use;
    int line_no;
} symbolTable[0];

struct INTEGER{
    char* name;
    char* d_type;
    char* use;
    int line_no;
} symbolTable[0];

struct STRING{
    char* name;
    char* d_type;
    char* use;
    int line_no;
} symbolTable[0];

