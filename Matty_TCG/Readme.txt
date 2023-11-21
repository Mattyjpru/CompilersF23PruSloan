Simple Parser Assignment
COSC 4785
11/21/23
Written by Matthew Pru and Cody Sloan

Our symbol table, AST building and code generation are written in our parser file (PS_CG_Parser.yacc). The 
Makefile will compile the source files. Using the command line 'Make' command and then gcc f23.c will make 
use of the yourmain() function in the header file of the same name. Then, ./a.out will show the output for 
f23.c

We used an Ubuntu command line to run and compile the files, so the version of lex and yacc (bison)
that we used is the one that comes from the command: sudo apt-get install flex bison