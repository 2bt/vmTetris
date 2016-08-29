vm: src/main.c Makefile
	gcc -Wall src/main.c -O2 -o vm

clean:
	rm -f vm
