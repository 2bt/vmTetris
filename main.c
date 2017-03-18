#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "5@0?L192V0M;0M85M0M;0M85M0M;0M85M0M;0M85M0M90M00M85M0M80M:5M0M80M05M"
"0M:0M85M0MD0M90M90M05M5M0MD0M90M90M05M5M0MD5M0M90M00M7595M0MD0M00M70M05M0MC5M5"
"90M90M05M5M0MC0M90M00M9595M0M:0M00M90M8595M0M:0M00M90M85M5M0M75M0M:0M95M5M0M75"
"M0M:0M909D08D0M50583954870{08:0M54871<;I</9;`;x;I</9;m;`;c</J64`/;:/=<2AA4@828"
"/38985871l05J23587X05U23572C0593:55A/@?4372J5:4372Q4:05b23572i0672<682i06:3<60"
"4209D08E07:/3M052253739233/M349/5:06:35625983j/6>36</5:02135J25983j359564273T6"
"4I/3384D05H25:742/5<25=87X/AA84;043/:;/<=62l/M449594772u494872r05324576h0:H025"
"=05L325059/>23>24574s0<1=/5<3<<3<509D/89053/3M5923587X4875A09Z08C5907803805325"
"M75j43594775_/3376c2775K4705825K76=0K.65z/..76E4?/7905O/3923505D353/KI47474376"
"Q4875W;I</9;_;i;v09Z08C07:;I</9;b/3M06^336:</K;N;N594776|49;84876y>61^;I</906^"
":</K;I</9;m;`;c</F;z</G</L</C</Q;h;N091/5M78B4978759493M6:4978D;8.";

int m[444], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = &m[f(1) < 20 ? x : m[x - 20]++]; }
int s() { return m[f(1) < 20 ? x : m[x - 20]]; }

int main() {
	system("stty cbreak -echo min 0");
	for (srand(time(0)); o = f(1);)
		o < 4 ? d(), *a = --o ? f(o) : s():
		o < 8 ? d(), *a += (o % 2 ?: -1) * (o > 5 ?: s()):
		o < 11 ? f(2), c = o < 9 || !*a ^ o % 2 ? x : c:
		o < 12 ? *d() = getchar():
		o < 15 ? putchar(f(o - 12) ?: *a):
		o < 16 ? *a = rand() % *a:
		usleep(20000);
	system("stty sane");
}
