Simple Parser Assignment
COSC 4785
10/26/23
Written by Cody Sloan and Matthew Pru

our code generator does not completed work for mg.f23 as an input at this point in time. we have 
removed the print statements from our grammar and replaced them with functionality for creating an
AST in the parsing stage. we have also placed our code generation from our trivial code generator
in and obtained output from tiny examples 1 and 2. we have also integrated scope sensitive symbol tables
Matty did the AST building inside the grammar while Cody focussed on getting scope to work forthe symbol tables.
Both spent time together working on and debugging these and everything else.
The 'Make' command will compile and link everything. with 'make clean' removing appropriate files.
'Make mg.f23' will run the compiled code with f23.c while 'make 1' 'make 2', 'make 3', and 'make 4'
will do the same for the tiny examples corresponding to each number
We used an Ubuntu command line to run and compile the files, so the version of lex and yacc (bison)
that we used is the one that comes from the command: sudo apt-get install flex bison