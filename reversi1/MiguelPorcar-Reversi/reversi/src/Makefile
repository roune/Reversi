CFLAGS=-g
.PHONY: clean All

all: reversi

reversi: reversi.o
	@echo "----------Building Reversi----------"
	gcc $(CFLAGS)  reversi.o -o reversi

reversi.o: reversi.c reversi.h
	@echo "----------Compiling reversi.c----------"
	gcc $(CFLAGS)  reversi.c -c

clean:
	@echo "----------Cleaning project Reversi----------"
	rm *.o reversi

help:
	@echo "all: run the whole build of reversi"
	@echo "reversi: builds from reversi.c"
	@echo "clean: remove all files produced by compilation"
