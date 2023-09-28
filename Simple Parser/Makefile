##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
LEXER=PruSloanLexer
OUTPUT=PS_Lexer_Output.txt

all: $(BUILD)
	./$(BUILD) < PS_example.f23 | tee $(OUTPUT)

$(BUILD): lex.yy.c y.tab.c
	${CC} lex.yy.c y.tab.c -ly -ll -o $(BUILD)

y.tab.c:
	yacc -d PSSimParser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT)