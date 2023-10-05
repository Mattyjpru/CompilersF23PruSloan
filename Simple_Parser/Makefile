##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
BUILD=PruSloanParser
OUTPUT=PS_Parser_Out.txt

all: lex.yy.c y.tab.c
	${CC} lex.yy.c y.tab.c -o $(BUILD)

y.tab.c:
	yacc -d PSSimParser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c