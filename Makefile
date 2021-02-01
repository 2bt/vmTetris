all: tetris snake

tetris: tetris.c Makefile
	gcc $< -w -Os -s -o $@

snake: snake.c Makefile
	gcc $< -w -Os -s -o $@

clean:
	rm -f vmTetris
