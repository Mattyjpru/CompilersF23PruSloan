CC=gcc
CFLAGS=


test: tester.c
	${CC} ${CFLAGS} PSlexer.l -o lexer.c

clean: 
	rm -f *.o lexer.c PSlexer.l