#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>

char b[1 << 12] = {};

uint16_t m[512], r[8], c, *a, o, x;

uint16_t f(uint8_t l) {
	for (x = 0; l--;) x = x * 56 + (b[c++] - 35);
	return x;
}

uint16_t* d() { return a = f(1) < 8 ? r + x : m + r[x - 8]++; }

uint16_t s() { return f(1) < 8 ? r[x] : m[r[x - 8]]; }

enum { END, LD1, LD2, MOV, ADD, SUB, MUL, INC, DEC, GET, PUT, RND, SLP, JMP, JPZ, JNZ };

int main(int argc, char** argv) {

	assert(argc == 2);
	FILE* v = fopen(argv[1], "r");
	assert(v);
	fread(b, 1, sizeof(b), v);
	fclose(v);

//	srand(time(0));
	uint32_t i = 0;

	srand(1472503431);

	system("stty cbreak -echo min 0");
	while ((o = f(1))) {
		switch (o) {
		case LD1:
		case LD2: d(); *a = f(o); break;
		case MOV: d(); *a = s(); break;
		case ADD: d(); *a += s(); break;
		case SUB: d(); *a -= s(); break;
		case MUL: d(); *a *= s(); break;
		case INC: ++*d(); break;
		case DEC: --*d(); break;
		case GET: *d() = getchar(); break;
		case PUT: putchar(*a); break;
		case RND: *a = rand() % *a; break;
		case SLP: usleep(20000);
//			printf("%4d) %03x:", i++, c);
//			for (x=0;x<8;x++)printf("|%d", r[x]);
//			printf("\n");
			break;
		case JMP:
		case JPZ:
		case JNZ: f(2); if (o == JMP || !*a ^ (o > JPZ)) c = x; break;
		}
	}
	system("stty sane");
	return 0;
}
