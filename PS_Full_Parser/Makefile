##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc

BUILD=PruSloanFullParser
OUTPUT=mg_FullParserOutput.txt

all: $(BUILD)
	./$(BUILD) < mg.f23 | tee $(OUTPUT)

Pru: $(BUILD)
	./$(BUILD) < Pru1.f23 | tee Pru1_output.txt

Sloan: $(BUILD)
	./$(BUILD) < Sloan2.f23 | tee Sloan2_output.txt

$(BUILD): lex.yy.c y.tab.c
	${CC} ${CFLAGS} y.tab.c -o $(BUILD)

y.tab.c:
	yacc -d PS_FullParser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c y.tab.h a.out