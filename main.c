#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "5@/?L092V/M;/M85M/M;/M85M/M;/M85M/M;/M85M/M9/M0/M85M/M8/M:5M/M8/M05M"
"/M:/M8/M//MD/M9/M9/M05M/M//MD/M9/M9/M05M5M/MD5M/M9/M0/M7595M/MD/M0/M7/M05M/MC5"
"M59/M9/M05M5M/MC/M9/M0/M9595M/M:/M0/M9/M8595M/M:/M0/M9/M85M5M/M75M/M:/M95M5M/M"
"75M/M:/M9/9D/8D/M5/5829568=0}/8:/M568=1>/5I805/98/5`8/5x8/5I805/98/5m8/5`8/5c8"
"05/J8;501;:1=</A.6@<2X1387858=22/5J335<8505/4335<85/5]235=2c/592:55A1@?63=2j5:"
"63=2q6:/5b335=39/673<6<39/6:2<6/42/9D/8E/7:13M/52353=3Y/3.1M36915:/6:256359<4:"
"16>26<15:/2125J359<4:2595662=3t;4i133<4d/5H35:=4R15<35=<851AA<4[/431:;1<=;3<1M"
"4695967=3E6968=3B/53345=70/:H/>59/5L2>5/5:4>5/<19/514<5/9D189/5313M59335<8568="
"5V/9Z/8C59/78/38/5335M=6/635967=5t133=6{/7.5K67/5835K=6R/K.;6?1..=6Z6?179139/5"
"93351KG676763143/5D345=6f68=5l/4I805/98/5_8/5i8/5v8/9Z/8C/7:144805/98/5b813M/6"
"^236805/K8/5N885967=7N69/58868=7K:;1t/3I804/98/6^805/K813381448/5m8/5`8/5c805/"
"F8/5z805/G805/L805/C805/Q8/5h8/5N8/9215M=9>69=9359692M6869=9@/588.";

int m[512], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = m + (f(1) < 20 ? x : m[x - 20]++); }
int s() { return m[f(1) < 20 ? x : m[x - 20]]; }

int main() {
	srand(time(0));
	system("stty cbreak -echo min 0");
	while ((o = f(1))) {
		switch (o) {
		case 1: case 2: d(); *a = f(o); break;
		case 3: d(); *a = s(); break;
		case 4: d(); *a += s(); break;
		case 5: d(); *a -= s(); break;
		case 6: d(); *a *= s(); break;
		case 7: ++*d(); break;
		case 8: --*d(); break;
		case 9: *d() = getchar(); break;
		case 10: putchar(*a); break;
		case 11: *a = rand() % *a; break;
		case 12: usleep(20000); break;
		default: f(2); if (o == 13 || !*a ^ (o > 14)) c = x; break;
		}
	}
	system("stty sane");
	return 0;
}
