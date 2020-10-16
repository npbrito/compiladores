# ------------------------------------------------
# Compilers Etapa4
#
# Author: Natália Paz Brito
# Email: npbrito@inf.ufrgs.br
# Date  : 2020-10-14
# ------------------------------------------------

CC=gcc
ETAPA=etapa4
DIR=include/
FILES=\
		src/main.c \
		src/hash.c \
		src/stack.c \
		src/list.c \
		src/misc.c \
		src/tree.c 

.PHONY: all
all:
	bison -d parser.y
	scp parser.tab.h $(DIR)
	flex scanner.l
	$(CC) -c -I $(DIR) $(FILES) lex.yy.c parser.tab.c  -ll
	$(CC) -o $(ETAPA) *.o -lfl

.PHONY: run
run:
	./$(ETAPA)

.PHONY: clean
clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h  *.o  $(ETAPA)