all: vm code


vm: main.c Makefile
	gcc main.c -g -o vm


#code: snake.txt assembler
code: tetris.txt assembler
	./assembler $< $@


clean:
	rm -f vm code
