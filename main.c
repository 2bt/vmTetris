#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

char b[] = "hbncQmikGnUbnUehUnUbnUehUnUbnUehUnUbnUehUnUdnUmnUehUnUenUchUnUenUmh"
"UnUcnUenUnnUYnUdnUdnUmhUnUnnUYnUdnUdnUmhUhUnUYhUnUdnUmnUfhihUnUYnUmnUfnUmhUnUZ"
"hUhinUdnUmhUhUnUZnUdnUmnUdhihUnUcnUmnUdnUehihUnUcnUmnUdnUehUhUnUfhUnUcnUdhUhUn"
"UfhUnUcnUdniYnjYnUhnmekimgj`m njcnUhgj`l_nmTemmndenm=enm%enmTemmndenm0enm=enm:"
"emmnSebhalghlefnaogbakElojfjhj`kknmSjomaebmmnijomaebnm@kom`k:nmdkhmhalbcgo`k3h"
"hgo`k,ghnm;jom`jdnlfjflajdnlckflnnkniYnjXnkcloUnmkjmo`jDnoolUogilmhnlckmljmiai"
"WlldklflmhkmXjmiaiWkmihlkmXjmiaiWkmihlkmXjmi`i(looai-nmUjmh`i?lmfjmeaeblaaai6n"
"njlhglfebjalUngihigk`jXgigj`j[nmjjnm`fgnhUndhdnmQkdmnmcidmnfldnmlifmniYljinmjl"
"oUhijomaebgj`h;niCnjZhinkenoenmjjmU`gbgohigk`gmloo`flnkohWgknmejmW`g?nWobgRgcl"
"kiloinmdjomlW[gkgkgolnonmYjnm`g1gj`h%nnTemmndenm>enm4enm'eniCnjZnkclnnemmndenm"
";eloUnl?kolemmnRenmOeehigk`fIginmeegj`fLcbl)noTemnndenl?emmnRelooelnnenm0enm=e"
"nm:emmnWenm#emmnVemmnQemmnZemmnLenm5enmOeniklmU`dYgi`ddhigikUlegi`dWnmeeo";

uint16_t m[512], r[20], c, *a, o, x;

uint16_t f(int l) { for (x = 0; l--;) x = x * 80 + (111 - b[c++]); return x; }
uint16_t* d() { return a = f(1) < 20 ? r + x : m + r[x - 20]++; }
uint16_t s() { return f(1) < 20 ? r[x] : m[r[x - 20]]; }

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
