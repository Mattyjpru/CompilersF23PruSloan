##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc

BUILD=PruSloanFullParser
OUTPUT=PS_Full_Parser_Out.txt

all: $(BUILD)
	./$(BUILD) < changeable-mg.f23 | tee $(OUTPUT)

$(BUILD): lex.yy.c y.tab.c
	${CC} ${CFLAGS} y.tab.c -o $(BUILD)

y.tab.c:
	yacc -d PS_FullParser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c y.tab.h a.out