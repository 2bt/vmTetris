all: vm code


vm: main.c Makefile
	gcc -Wall main.c -Os -s -o vm


code: tetris.txt assembler
	./assembler < tetris.txt


clean:
	rm -f vm code
