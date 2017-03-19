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
		--o < 24 ? a = &m[f(1) < 20 ? x : m[x - 20]++],
			*a = !(o / 16) * *a + (o / 8 ? 1 : -1) * (
			(x = o % 8) < 3 ? x:
			x < 5 ? f(x - 2):
			x < 6 ? m[f(1) < 20 ? x : m[x - 20]]:
			x < 7 ? getchar():
			rand() % f(1)):
		o < 27 ? f(2), c = o < 25 || !*a ^ o % 2 ? x : c:
		o < 30 ? putchar(f(o % 3) ?: *a):
		usleep(20000);
	system("stty sane");
}


// a - x
// a + x
// 0 + x
// 0, 1, 2, f(1), f(2), s(), getchar(), rand() % f(1)
