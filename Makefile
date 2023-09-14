CC=gcc
#Executable=PruSloanLexer


all: 
	@echo $(shell lex PSlexer.l)
#	${CC} -lex.yy.c

clean: 
	rm -f *.o lex.yy.c 