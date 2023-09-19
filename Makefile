##############################################################################
# Lexer Makefile
# Writen By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
LEXER=PruSloanLexer

all: $(LEXER)
#	dont forget to switch to our example
# 	$(shell ./$(LEXER) < PS_example.f23 | tee PS_Lexer_Output.txt)
	./$(LEXER) < te1.f23 | tee PS_Lexer_Output.txt

$(LEXER): lex.yy.c
	${CC} lex.yy.c -ll -o $(LEXER)

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(LEXER)