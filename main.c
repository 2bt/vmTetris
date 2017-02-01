#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "4@0?L192V0M;0M84M0M;0M84M0M;0M84M0M;0M84M0M90M00M84M0M80M:4M0M80M04M"
"0M:0M80M/0MD0M90M90M04M0M/0MD0M90M90M04M4M0MD4M0M90M00M7494M0MD0M00M70M04M0MC4"
"M490M90M04M4M0MC0M90M00M9494M0M:0M00M90M8494M0M:0M00M90M84M4M0M74M0M:0M94M4M0M"
"74M0M:0M909D08D0M505829558>0}08:0M558>1>8I9/98`8x8I9/98m8`8c9/J<4l/;:/=<3AA5@="
"2D/386848>1n05J335=7d15/4335=7d05]235>2O0592:54A/@?53>2V4:53>2]5:05b335>2u0673"
"<6=2u06:2<604209D08E07:/3M052353>3E333/M359/5:06:256359=3v/6>26</5:02125J359=3"
"v2594652>3`<4U/33=4P05H35:>4>/5<35==7d/AA=4G043/:;/<=<2x/M4594957>315958>3.053"
"345>6t0:H025:05L225059/>22>255>5/0<1:/5<2<<2<509D/89053/3M49335=7d58>5M09Z08C4"
"907803805335M>5v534957>5k/33>6o3774K5705835K>6I0K.<66/..>6Q5?/7905O/3933505D25"
"3/KI575753>6]58>5c8I9/98_8i8v09Z08C07:8I9/98b/3M06^23679/K8N8N4957>78598858>75"
";<1`8I9/98^9/K8I9/98m8`8c9/F8z9/G9/L9/C9/Q8h8N092/5M>8L59>8A49592M6759>8N88.";

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
		else { f(2); if (o == 14 || !*a ^ (o > 15)) c = x; }
	}
	system("stty sane");
	return 0;
}
