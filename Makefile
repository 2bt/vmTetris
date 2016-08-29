vmTetris: main.c Makefile
	gcc -Wall main.c -Os -s -o vmTetris

clean:
	rm -f vmTetris
