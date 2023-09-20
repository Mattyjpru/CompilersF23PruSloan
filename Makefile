##############################################################################
# Lexer Makefile
# Writen By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
LEXER=PruSloanLexer
OUTPUT=PS_Lexer_Output.txt

all: $(LEXER)
	./$(LEXER) < PS_example.f23 | tee $(OUTPUT)

$(LEXER): lex.yy.c
	${CC} lex.yy.c -ll -o $(LEXER)

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(LEXER) $(OUTPUT)