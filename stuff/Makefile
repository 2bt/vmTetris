all: vm code


vm: main.c Makefile
	gcc main.c -g -o vm


code: assembler worm.txt
	./assembler worm.txt

#code: assembler tetris.txt
#	./assembler tetris.txt


clean:
	rm -f vm code
