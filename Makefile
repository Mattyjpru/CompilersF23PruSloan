CC=gcc
CFLAGS=


test: PSlexer.c
	${CC} ${CFLAGS} PSlexer.l -o lexer.c

clean: 
	rm -f *.o lexer.c PSlexer.l