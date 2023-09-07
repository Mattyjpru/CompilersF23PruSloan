CC=gcc
CFLAGS=


test: tester.c
	${CC} ${CFLAGS} lexer.c -o lexer

clean: 
	rm -f *.o lexer