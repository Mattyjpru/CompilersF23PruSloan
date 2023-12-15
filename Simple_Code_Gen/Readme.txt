Simple Code Generator Assignment
COSC 4785
12/15/23
Written by Cody Sloan and Matthew Pru

Our code generator does not work for mg.f23 as an input at this point in time. We have 
removed the print statements from our grammar and replaced them with functionality for creating an
AST in the parsing stage. We have also started revising our code generation from our trivial code generator
to integrate with our new symbol table, which should keep track of the scope in the code.
Matty did the AST building inside the grammar while Cody focussed on getting scope to work for the symbol tables.
Both spent time together working on and debugging these and everything else.
The 'Make' command will compile and link everything. with 'make clean' removing appropriate files.
'Make mg.f23' will run the compiled code with f23.c while 'make 1' 'make 2', 'make 3', and 'make 4'
will do the same for the tiny examples corresponding to each number.
We used an Ubuntu command line to run and compile the files, so the version of lex and yacc (bison)
that we used is the one that comes from the command: sudo apt-get install flex bison.