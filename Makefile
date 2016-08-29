vm: src/main.c Makefile
	gcc -Wall src/main.c -Os -s -o vm

clean:
	rm -f vm
