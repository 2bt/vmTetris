vmTetris: main.c Makefile
	gcc main.c -w -Os -s -o vmTetris

clean:
	rm -f vmTetris
