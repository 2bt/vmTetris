all: vm code


vm: main.c Makefile
	gcc main.c -g -o vm


code: tetris.txt assembler
	./assembler


clean:
	rm -f vm code
