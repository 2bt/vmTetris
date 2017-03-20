#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char b[1000];

int m[444], c, x;

int f() { return x = b[c++] - 46; }

int main(int o, int a) {
	FILE* v = fopen("code", "r");
	fread(b, 1, sizeof(b), v);
	fclose(v);

	system("stty cbreak -echo min 0");
	for (srand(a); o = f();)
		o < 42 ? m[a = o % 2 ? f() < 20 ? x : m[x - 20]++ : m[4]++] *= o < 28,
			a = m[a] += (o > 13 ?: -1) * (
			(x = o / 2 % 7) < 3 ? x:
			x < 4 ? f():
			x < 5 ? m[f() < 20 ? x : m[x - 20]]:
			x < 6 ? getchar():
			rand() % f()):
		o < 45 ? putchar(o % 3 ? o % 2 * 74 + f() : a):
		o < 63 ? f(), c = !a ^ o / 54 ? x + o % 9 * 74 : c:
		usleep(20000);
	system("stty sane");
}


// a - x
// a + x
// 0 + x

// 0, 1, 2, f(), s(), getchar(), rand()%f()
