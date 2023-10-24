##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
BUILD=PruSloanSymbolTable
OUTPUT=PS_ST_Parser_Out.txt

all: $(BUILD)
	@./$(BUILD) < simple1.f23 | tee -a $(OUTPUT)



#Old rule
#	./$(BUILD) < simple1.f23 | tee $(OUTPUT)

$(BUILD): lex.yy.c y.tab.c
	${CC} lex.yy.c y.tab.c -o $(BUILD)

y.tab.c:
	yacc -d PS_ST_Parser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c y.tab.h