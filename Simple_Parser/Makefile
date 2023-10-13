##############################################################################
# Compilers Project Makefile
# Written By Matthew Pru and Cody Sloan
##############################################################################
CC=gcc
BUILD=PruSloanParser
OUTPUT=PS_Parser_Out.txt

all: $(BUILD)
	@printf "++++++++++++++++++++++++++++++++++++++++++++++++\n" | tee $(OUTPUT)
	@printf "# Parsing Tree for the first program begins here:\n" | tee -a $(OUTPUT)
	@printf "++++++++++++++++++++++++++++++++++++++++++++++++\n" | tee -a $(OUTPUT)
	@./$(BUILD) < simple1.f23 | tee -a $(OUTPUT)
	@printf "\n++++++++++++++++++++++++++++++++++++++++++++++++\n" | tee -a $(OUTPUT)
	@printf "# Parsing Tree for the second program begins here:\n" | tee -a $(OUTPUT)
	@printf "++++++++++++++++++++++++++++++++++++++++++++++++\n" | tee -a $(OUTPUT)
	@./$(BUILD) < simple2.f23 | tee -a $(OUTPUT)


#Old rule
#	./$(BUILD) < simple1.f23 | tee $(OUTPUT)

$(BUILD): lex.yy.c y.tab.c
	${CC} lex.yy.c y.tab.c -o $(BUILD)

y.tab.c:
	yacc -d PSSimParser.yacc

lex.yy.c:
	lex PSlexer.l

clean: 
	rm -f *.o lex.yy.c $(BUILD) $(OUTPUT) y.tab.c y.tab.h