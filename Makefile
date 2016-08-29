vm: main.c Makefile
	gcc -Wall main.c -Os -s -o vm

clean:
	rm -f vm
