##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc

BUILD=PruSloanSimpleCodeGen
OUTPUT=PS_CG_Parser_Out.txt
	
all: lex.yy.c y.tab.c
	${CC} ${CFLAGS} y.tab.c -o $(BUILD)

1: all
	./$(BUILD) < te1.f23 | tee $(OUTPUT)

2: all
	./$(BUILD) < te2.f23 | tee $(OUTPUT)

3: all
	./$(BUILD) < te3.f23 | tee $(OUTPUT)

4: all
	./$(BUILD) < te4.f23 | tee $(OUTPUT)
	
mg.f23: all
	./$(BUILD) < mg.f23 | tee $(OUTPUT)

runCode:
	gcc f23.c -lm ; ./a.out

y.tab.c:
	yacc -d CodeGenParser_PruSloan.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c y.tab.h a.out yourmain.h