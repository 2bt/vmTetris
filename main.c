#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "4@0?L192V0M;0M84M0M;0M84M0M;0M84M0M;0M84M0M90M00M84M0M80M:4M0M80M04M"
"0M:0M84M0MD0M90M90M04M4M0MD0M90M90M04M4M0MD4M0M90M00M7494M0MD0M00M70M04M0MC4M4"
"90M90M04M4M0MC0M90M00M9494M0M:0M00M90M8494M0M:0M00M90M84M4M0M74M0M:0M94M4M0M74"
"M0M:0M909D08D0M505829558>0{08:0M558>1<8I9/98`8x8I9/98m8`8c9/J<4`/;:/=<3AA5@=28"
"/386848>1l05J335=7X05U335>2C0592:54A/@?53>2J4:53>2Q5:05b335>2i0673<6=2i06:2<60"
"4209D08E07:/3M052353>39333/M359/5:06:256359=3j/6>26</5:02125J359=3j2594652>3T<"
"4I/33=4D05H35:>42/5<35==7X/AA=4;043/:;/<=<2l/M4594957>2u5958>2r053345>6h0:H025"
":05L225059/>22>255>4s0<1:/5<2<<2<509D/89053/3M49335=7X58>5A09Z08C4907803805335"
"M>5j534957>5_/33>6c3774K5705835K>6=0K.<5z/..>6E5?/7905O/3933505D253/KI575753>6"
"Q58>5W8I9/98_8i8v09Z08C07:8I9/98b/3M06^23679/K8N8N4957>6|598858>6y;<1^8I9/906^"
"79/K8I9/98m8`8c9/F8z9/G9/L9/C9/Q8h8N091/5M>8B59>8749592M6759>8D88.";

int m[512], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = &m[f(1) < 20 ? x : m[x - 20]++]; }
int s() { return m[f(1) < 20 ? x : m[x - 20]]; }

int main() {
	srand(time(0));
	system("stty cbreak -echo min 0");
	while ((o = f(1))) {
		if (o < 4) { d(); *a = o > 1 ? f(o - 1) : s(); }
		else if (o < 6) { d(); *a += o > 4 ? -s() : s(); }
		else if (o < 8) *d() += 7 - o ?: -1;
		else if (o < 9) *d() = getchar();
		else if (o < 12) putchar(f(o - 9) ?: *a);
		else if (o < 13) *a = rand() % *a;
		else if (o < 14) usleep(20000);
		else { f(2); if (o < 15 || !*a ^ (o > 15)) c = x; }
	}
	system("stty sane");
	return 0;
}
