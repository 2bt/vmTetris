vm: src/main.c Makefile
	c99 -Wall src/main.c -O2 -o vm

clean:
	rm -f vm
