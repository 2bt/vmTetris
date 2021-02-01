all: vm snake-code


vm: main.c Makefile
	gcc main.c -g -o vm


snake-code: snake.txt assembler
	./assembler $<


tetris-code: tetris.txt assembler
	./assembler $<


clean:
	rm -f vm code
