CFLAGS=-g
FOLDER=src/
.PHONY: clean All

All: reversi
	@echo "----------Building Reversi----------"
	gcc $(CFLAGS)  reversi.o -o reversi

reversi: $(FOLDER)reversi.c $(FOLDER)reversi.h
	@echo "----------Compiling reversi.c----------"
	gcc $(FOLDER)reversi.c -c

clean:
	@echo "----------Cleaning project Reversi----------"
	rm *.o reversi

help:
	@echo "all: run the whole build of reversi"
	@echo "reversi: builds from reversi.c"
	@echo "clean: remove all files produced by compilation"
