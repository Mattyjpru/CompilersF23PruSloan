CC=gcc
CFLAGS=
OPT=-O3 -msse -funroll-loops

test: tester.c
	${CC} ${CFLAGS} lexer.c -o lexer

clean: 
	rm -f *.o lexer