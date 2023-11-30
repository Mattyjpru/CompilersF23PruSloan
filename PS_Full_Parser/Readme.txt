Simple Parser Assignment
COSC 4785
10/26/23
Written by Cody Sloan and Matthew Pru

Our full parser successfully parses mg.f23. We have marked, in the yacc file, the specific rules that each of us 
wrote. However, we spent a lot of time together debugging and retrofitting our new rules into the original
grammar from our simple parser. The 'Make' command will parse the mg.f23 file and create the appropriate output.
'Make Pru' and 'Make Sloan' will respectively parse Matty's and Cody's example files and create output files for them
We used an Ubuntu command line to run and compile the files, so the version of lex and yacc (bison)
that we used is the one that comes from the command: sudo apt-get install flex bison