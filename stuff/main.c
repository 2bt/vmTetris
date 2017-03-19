#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char b[1<<10];

int m[444], c, *a, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }

int main(int o, int _) {
	FILE* v = fopen("code", "r");
	fread(b, 1, sizeof(b), v);
	fclose(v);
	system("stty cbreak -echo min 0");
	for (srand(_); o = f(1);)
		--o < 21 ? a = &m[f(1) < 20 ? x : m[x - 20]++],
			*a = !(o / 14) * *a + (o / 7 ? 1 : -1) * (
			!(x = o % 7) ? getchar():
			x < 3 ? x:
			x < 5 ? f(x - 2):
			x < 6 ? m[f(1) < 20 ? x : m[x - 20]]:
			rand() % f(1)):
		o < 24 ? f(2), c = o < 22 || !*a ^ o % 2 ? x : c:
		o < 27 ? putchar(f(o % 4) ?: *a):
		usleep(20000);
	system("stty sane");
}


// a - x
// a + x
// 0 + x
// getchar(), 1, 2, f(1), f(2), s(), rand() % f(1)
