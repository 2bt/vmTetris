#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>

char b[1 << 12] = {};

enum { R = 20 };
int m[512], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = f(1) < R ? m + x : m + m[x - R]++; }
int s() { return f(1) < R ? m[x] : m[m[x - R]]; }

enum { END, MOV, LD1, LD2, ADD, SUB, INC, DEC, JMP, JNZ, JZ, GET, PUT, PT1, PT2, RND, SLP, };

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
		case MOV:
      case LD1:
		case LD2: d(); *a = o > 1 ? f(o - 1) : s(); break;
		case ADD: d(); *a += s(); break;
		case SUB: d(); *a -= s(); break;
		case INC: ++*d(); break;
		case DEC: --*d(); break;
		case JMP:
		case JZ:
		case JNZ: f(2); if (o == JMP || !*a ^ (o < JZ)) c = x; break;
		case GET: *d() = getchar(); break;
		case PUT:
		case PT1:
		case PT2: putchar(f(o - PUT) ?: *a); break;
		case RND: *a = rand() % *a; break;
		case SLP: usleep(20000); break;
		}
	}
	system("stty sane");
	return 0;
}
