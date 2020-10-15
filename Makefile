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
		src/stack.c 

.PHONY: all
all:
	$(CC) -I$(DIR) $(FILES) -o $(ETAPA)

.PHONY: run
run:
	./$(ETAPA)

.PHONY: clean
clean:
	rm -f *.o  $(ETAPA)