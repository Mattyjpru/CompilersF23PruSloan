CC=gcc
EXECUTABLE=PruSloanLexer


all: 
	$(shell lex PSlexer.l)
	${CC} lex.yy.c -ll $(EXECUTABLE)
#dont forget to switch to our example
	$(shell ./$(EXECUTABLE) < te1.f23)
#	$(shell ./$(EXECUTABLE) < PS_example.f23)

clean: 
	rm -f *.o lex.yy.c 