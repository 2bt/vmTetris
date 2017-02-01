#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "4@0?L192V0M;0M84M0M;0M84M0M;0M84M0M;0M84M0M90M00M84M0M80M:4M0M80M04M"
"0M:0M80M/0MD0M90M90M04M0M/0MD0M90M90M04M4M0MD4M0M90M00M7494M0MD0M00M70M04M0MC4"
"M490M90M04M4M0MC0M90M00M9494M0M:0M00M90M8494M0M:0M00M90M84M4M0M74M0M:0M94M4M0M"
"74M0M:0M909D08D0M505829558>0}08:0M558>1>8I9/98`8x8I9/98m8`8c9/J<4b/;:/=<3AA5@="
"2:/386848>1n05J335=7Z05U335>2E0592:54A/@?53>2L4:53>2S5:05b335>2k0673<6=2k06:2<"
"604209D08E07:/3M052353>3;333/M359/5:06:256359=3l/6>26</5:02125J359=3l2594652>3"
"V<4K/33=4F05H35:>44/5<35==7Z/AA=4=043/:;/<=<2n/M4594957>2w5958>2t053345>6j0:H0"
"25:05L225059/>22>255>4u0<1:/5<2<<2<509D/89053/3M49335=7Z58>5C09Z08C49078038053"
"35M>5l534957>5a/33>6e3774K5705835K>6?0K.<5|/..>6G5?/7905O/3933505D253/KI575753"
">6S58>5Y8I9/98_8i8v09Z08C07:8I9/98b/3M06^23679/K8N8N4957>7.598858>6{;<1`8I9/90"
"6^79/K8I9/98m8`8c9/F8z9/G9/L9/C9/Q8h8N091/5M>8D59>8949592M6759>8F88.";


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
