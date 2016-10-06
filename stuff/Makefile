all: vm code


vm: main.c Makefile
	gcc -Wall main.c -g -o vm


code: tetris.txt assembler
	./assembler < tetris.txt


clean:
	rm -f vm code
