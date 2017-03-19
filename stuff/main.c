#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char b[1000];

int m[444], c, x;

int f() { return x = b[c++] - 49; }

int main(int o, int a) {
	FILE* v = fopen("code", "r");
	fread(b, 1, sizeof(b), v);
	fclose(v);

	system("stty cbreak -echo min 0");
	for (srand(a); o = f();)
		--o < 24 ? m[a = f() < 20 ? x : m[x - 20]++] *= o < 14,
			a = m[a] += (o > 6 ?: -1) * (
			(x = o % 7) < 3 ? x:
			x < 4 ? f():
			x < 5 ? m[f() < 20 ? x : m[x - 20]]:
			x < 6 ? getchar():
			rand() % f()):
		o < 60 ? f(), c = o < 40 | !a ^ o / 50 ? x + o % 10 * 70 : c:
		o < 63 ? putchar(o % 3 ? o % 2 * 70 + f() : a):
		usleep(20000);
	system("stty sane");
}


// a - x
// a + x
// 0 + x
// 0, 1, 2, f(), s(), getchar(), rand()%f()
