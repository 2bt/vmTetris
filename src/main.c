#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

enum { END, LD1, LD2, MOV, ADD, SUB, MUL, INC, DEC, JMP, JZ, JNZ, GET, PUT, RND, SLP };

uint8_t b[1 << 12] = {
	// TODO
};

uint16_t m[1 << 12], r[8], c, *a, o, n, x;

uint16_t f(uint8_t l) {
	for (x = 0; l--; ++c) x = x << 4 | (b[c / 2] >> c % 2 * 4 & 15);
	return x;
}

uint16_t* d() {
	x = f(1);
	return a = x < 8 ? r + x : m + r[x % 8]++;
}

uint16_t s() {
	x = f(1);
	return x < 8 ? r[x] : m[r[x % 8]];
}

int main(int argc, char** argv) {

	assert(argc == 2);
	FILE* v = fopen(argv[1], "r");
	assert(v);
	fread(b, 1, sizeof(b), v);
	fclose(v);

	srand(time(0));
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
		case JMP:
		case JZ:
		case JNZ: n = f(3); if (o == JMP || !*a ^ (o > JZ)) c = n; break;
		case GET: *d() = getchar(); break;
		case PUT: putchar(*a); break;
		case RND: *a = rand() % *a; break;
		case SLP: usleep(50000); break;
		}
	}
	system("stty sane");
	return 0;
}
