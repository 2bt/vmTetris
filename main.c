#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "4@0?L192V0M;0M84M0M;0M84M0M;0M84M0M;0M84M0M90M00M84M0M80M:4M0M80M04M"
"0M:0M84M0MD0M90M90M04M4M0MD0M90M90M04M4M0MD4M0M90M00M7494M0MD0M00M70M04M0MC4M4"
"90M90M04M4M0MC0M90M00M9494M0M:0M00M90M8494M0M:0M00M90M84M4M0M74M0M:0M94M4M0M74"
"M0M:0M909D08D0M50582955870{08:0M55871<;I</9;`;x;I</9;m;`;c</J64`/;:/=<3AA5@828"
"/38984871l05J33587X05U33572C0592:54A/@?5372J4:5372Q5:05b33572i0673<682i06:2<60"
"4209D08E07:/3M052353739333/M359/5:06:25635983j/6>26</5:02125J35983j259465273T6"
"4I/3384D05H35:742/5<35=87X/AA84;043/:;/<=62l/M459495772u595872r05334576h0:H025"
"=05L225059/>22>25574s0<1=/5<2<<2<509D/89053/3M4933587X5875A09Z08C4907803805335"
"M75j53495775_/3376c3774K5705835K76=0K.65z/..76E5?/7905O/3933505D253/KI57575376"
"Q5875W;I</9;_;i;v09Z08C07:;I</9;b/3M06^236:</K;N;N495776|59;85876y>61^;I</906^"
":</K;I</9;m;`;c</F;z</G</L</C</Q;h;N091/5M78B5978749592M6:5978D;8.";

int m[444], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = &m[f(1) < 20 ? x : m[x - 20]++]; }
int s() { return m[f(1) < 20 ? x : m[x - 20]]; }

int main() {
	system("stty cbreak -echo min 0");
	for (srand(time(0)); o = f(1);)
		o < 4 ? d(), *a = --o ? f(o) : s():
		o < 6 ? d(), *a += o > 4 ? -s() : s():
		o < 8 ? *d() -= o - 7 ?: 1:
		o < 11 ? f(2), c = o < 9 || !*a ^ o % 2 ? x : c:
		o < 12 ? *d() = getchar():
		o < 15 ? putchar(f(o - 12) ?: *a):
		o < 16 ? *a = rand() % *a:
		usleep(20000);
	system("stty sane");
}
