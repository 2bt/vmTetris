#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
char b[1000];
int m[444], c, x;
int f() { return x = b[c++] - 47; }
int main(int o, int a) {
	FILE* v = fopen("code", "r");
	fread(b, 1, sizeof(b), v);
	fclose(v);
	system("stty cbreak -echo min 0");
	for (srand(a); o = f();)
		o < 42 ?
			a = (x = o / 2 % 7) < 3 ? x:
				x < 4 ? f():
				x < 5 ? m[f() < 23 ? x : m[x - 23]]:
				x < 6 ? getchar():
				rand() % f(),
			m[x = o % 2 ? f() : m[6]++] *= o < 28,
			a = m[x] += o > 13 ? a : -a:
		o < 45 ? putchar(o % 3 ? o % 2 * 75 + f() : a):
		o < 63 ? f(), c = !a ^ o / 54 ? x + o % 9 * 75 : c:
		usleep(20000);
	system("stty sane");
}
