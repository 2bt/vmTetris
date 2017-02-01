#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "4@/?L092V/M;/M84M/M;/M84M/M;/M84M/M;/M84M/M9/M0/M84M/M8/M:4M/M8/M04M"
"/M:/M8/M//MD/M9/M9/M04M/M//MD/M9/M9/M04M4M/MD4M/M9/M0/M7494M/MD/M0/M7/M04M/MC4"
"M49/M9/M04M4M/MC/M9/M0/M9494M/M:/M0/M9/M8494M/M:/M0/M9/M84M4M/M74M/M:/M94M4M/M"
"74M/M:/M9/9D/8D/M5/5829558<0}/8:/M558<1>/5I705/97/5`7/5x7/5I705/97/5m7/5`7/5c7"
"05/J7:501;:1=</A.5@;2X1386848<22/5J335;8@05/4335;8@/5]235<2c/592:54A1@?53<2j4:"
"53<2q5:/5b335<39/673<6;39/6:2<6/42/9D/8E/7:13M/52353<3Y/3.1M35915:/6:256359;4:"
"16>26<15:/2125J359;4:2594652<3t:4i133;4d/5H35:<4R15<35=;8@1AA;4[/431:;1<=:3<1M"
"4594957<3E5958<3B/53345<7;/:H/258/5L225/591>22>255<5C/<1815<2<<2<5/9D189/5313M"
"49335;8@58<5a/9Z/8C49/78/38/5335M<6:534957<6/133<76/7.4K57/5835K<6]/K.:6J1..<6"
"e5?179139/593351KG575753143/5D345<6q58<5w/4I705/97/5_7/5i7/5v7/9Z/8C/7:144705/"
"97/5b713M/6^236705/K7/5N774957<7Y59/58758<7V9:1t/3I704/97/6^705/K713371447/5m7"
"/5`7/5c705/F7/5z705/G705/L705/C705/Q7/5h7/5N7/9215M<9I59<9>49592M6759<9K/587.";

int m[512], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] - 46; return x; }
int* d() { return a = &m[f(1) < 20 ? x : m[x - 20]++]; }
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
		case 6: ++*d(); break;
		case 7: --*d(); break;
		case 8: *d() = getchar(); break;
		case 9: putchar(*a); break;
		case 10: *a = rand() % *a; break;
		case 11: usleep(20000); break;
		default: f(2); if (o == 12 || !*a ^ (o > 13)) c = x; break;
		}
	}
	system("stty sane");
	return 0;
}
