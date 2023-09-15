##############################################################################
# Lexer Makefile
# Writen By Matthew Pru and Cody Sloan
#
# Made some changes. This should compile everything correctly, feel free to
# change it tho. The old Makefile was saved as Makefile.txt
##############################################################################
CC=gcc
LEXER=PruSloanLexer


all: $(LEXER)
#	dont forget to switch to our example
# 	$(shell ./$(LEXER) < PS_example.f23 | tee PS_Lexer_Output.txt)
	$(shell ./$(LEXER) < te1.f23 | tee PS_Lexer_Output.txt)

$(LEXER): lex.yy.c
	${CC} -o $(LEXER) lex.yy.c -ll 

lex.yy.c:
	$(shell lex PSlexer.l)	

clean: 
	rm -f *.o lex.yy.c $(LEXER)