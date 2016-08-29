#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

uint8_t b[] = {
	33, 122, 42, 26, 46, 38, 16, 162, 102, 18, 206, 231, 225, 122, 30, 206,
	231, 225, 122, 30, 206, 231, 225, 122, 30, 206, 231, 225, 122, 30, 190,
	231, 231, 225, 122, 30, 174, 231, 225, 123, 30, 174, 231, 231, 231, 225,
	123, 30, 174, 225, 17, 190, 225, 27, 190, 225, 123, 126, 126, 30, 30, 225,
	27, 190, 225, 27, 190, 231, 231, 231, 231, 225, 27, 190, 231, 225, 123,
	126, 30, 158, 103, 231, 225, 27, 190, 225, 18, 158, 231, 231, 231, 225, 27,
	174, 231, 103, 225, 123, 126, 126, 126, 30, 174, 225, 27, 190, 231, 231,
	225, 123, 118, 30, 190, 231, 225, 18, 174, 231, 225, 122, 118, 30, 190,
	231, 225, 18, 174, 231, 225, 122, 126, 30, 158, 231, 231, 225, 123, 30,
	190, 231, 231, 225, 121, 126, 30, 190, 231, 225, 43, 22, 38, 21, 22, 126,
	33, 74, 38, 88, 27, 19, 81, 28, 126, 88, 27, 52, 34, 177, 45, 82, 219, 34,
	35, 45, 66, 218, 34, 177, 45, 82, 219, 34, 243, 45, 50, 210, 34, 83, 45,
	98, 220, 41, 46, 33, 53, 122, 49, 55, 171, 33, 25, 10, 168, 26, 108, 3,
	197, 117, 181, 145, 42, 18, 92, 32, 74, 240, 34, 101, 5, 162, 4, 47, 34,
	79, 32, 27, 173, 33, 75, 39, 33, 121, 26, 177, 33, 58, 154, 8, 27, 46, 119,
	8, 27, 174, 120, 34, 67, 5, 178, 2, 27, 98, 49, 92, 58, 42, 176, 40, 50, 1,
	164, 19, 65, 98, 97, 81, 18, 4, 3, 30, 66, 37, 176, 34, 29, 0, 227, 128,
	22, 130, 51, 26, 98, 52, 58, 114, 36, 91, 98, 42, 55, 36, 118, 67, 178, 37,
	166, 114, 67, 98, 55, 36, 91, 98, 42, 55, 36, 118, 67, 178, 37, 182, 178,
	59, 0, 42, 107, 34, 161, 37, 183, 146, 21, 98, 35, 26, 113, 37, 169, 4, 31,
	146, 35, 170, 162, 18, 81, 33, 53, 167, 39, 51, 114, 51, 186, 41, 224, 227,
	129, 118, 118, 20, 194, 37, 180, 18, 136, 118, 37, 18, 89, 82, 43, 81, 33,
	85, 33, 59, 26, 114, 161, 49, 231, 34, 65, 52, 34, 18, 96, 35, 33, 56, 58,
	49, 227, 33, 100, 35, 33, 54, 58, 98, 97, 83, 22, 82, 3, 126, 86, 32, 74,
	240, 88, 59, 129, 98, 194, 81, 116, 22, 164, 1, 26, 82, 37, 190, 67, 133,
	112, 134, 180, 51, 57, 0, 59, 73, 65, 112, 140, 20, 162, 37, 188, 99, 28,
	12, 57, 117, 17, 139, 57, 100, 3, 22, 178, 5, 50, 140, 72, 72, 8, 19, 32,
	18, 86, 33, 59, 215, 87, 34, 145, 37, 181, 51, 33, 18, 219, 34, 181, 45,
	50, 209, 34, 179, 45, 66, 216, 98, 194, 81, 20, 4, 34, 177, 45, 82, 219,
	34, 67, 61, 224, 34, 3, 4, 210, 34, 214, 45, 34, 208, 125, 118, 20, 194,
	37, 180, 195, 132, 22, 162, 125, 37, 18, 89, 82, 59, 28, 159, 129, 34, 18,
	219, 34, 181, 45, 50, 208, 34, 214, 45, 18, 219, 34, 181, 45, 50, 223, 34,
	35, 45, 50, 213, 34, 134, 45, 66, 220, 34, 150, 45, 98, 222, 34, 86, 45,
	114, 211, 34, 163, 45, 34, 208, 97, 52, 226, 75, 71, 104, 75, 118, 3, 46,
	50, 64, 2, 141, 54, 97, 23, 75, 71, 33, 218
};

uint16_t m[1 << 10], r[8], c, *a, o, n, x;

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
	srand(time(0));
	system("stty cbreak -echo min 0");
	while ((o = f(1))) {
		switch (o) {
		case 1:
		case 2: d(); *a = f(o); break;
		case 3: d(); *a = s(); break;
		case 4: d(); *a += s(); break;
		case 5: d(); *a -= s(); break;
		case 6: d(); *a *= s(); break;
		case 7: ++*d(); break;
		case 8: --*d(); break;
		case 9:
		case 10:
		case 11: n = f(3); if (o == 9 || !*a ^ (o > 10)) c = n; break;
		case 12: *d() = getchar(); break;
		case 13: putchar(*a); break;
		case 14: *a = rand() % *a; break;
		case 15: usleep(20000); break;
		}
	}
	system("stty sane");
	return 0;
}
