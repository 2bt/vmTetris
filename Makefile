vm: src/main.c Makefile
	c99 -Wall src/main.c -o vm

clean:
	rm -f vm
