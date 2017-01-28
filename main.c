#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

char* b = "6A0@M1:3W0N<0N96N0N<0N96N0N<0N96N0N<0N96N0N:0N10N96N0N90N;6N0N90N16N"
"0N;0N90N00NE0N:0N:0N16N0N00NE0N:0N:0N16N6N0NE6N0N:0N10N86:6N0NE0N10N80N16N0ND6"
"N6:0N:0N16N6N0ND0N:0N10N:6:6N0N;0N10N:0N96:6N0N;0N10N:0N96N6N0N86N0N;0N:6N6N0N"
"86N0N;0N:0:E09E0N60693:679>1~09;0N679>2?06J9160:906a906y906J9160:906n906a906d9"
"160K9<6=2<;2>=0B/7A=3Y2498969>3306K446=9<1605446=9<06^346>3d06:3;66B2A@74>3k6;"
"74>3r7;06c446>4:0784=7=4:07;3=70530:E09F08;24N063464>4Z04/2N47:26;07;36746:=5G"
"27?37=26;36K46:=5G36:6736K46:=5G36:6736K46:>5v244=5q06I46;>5_26=46>=9<2BB=5h05"
"42;<2=><4=2N57:6:78>4F7:79>4C064456>870;I0?6:06M3?606;5?60=2:0625=60:E29:06424"
"N6:446=9<79>6c0:[09D6:08904906446N>7<746:78>71244>8208/6L7806946L>7_0L/<7L7@28"
":24:06:4462LH78787425406E456>7m79>6y05J9160:906`906j906w90:[09D08;2559160:906c"
"924N07_3479160L906O996:78>8U7:069979>8R;<2u04J9150:907_9160L92449255906n906a90"
"6d9160G906{9160H9160M9160D9160R906i906O90:326N>:E7:>::6:7:3N797:>:G0699/";

int m[512], c, *a, o, x;

int f(int l) { for (x = 0; l--;) x = x * 80 + b[c++] -47; return x; }
int* d() { return a = f(1) < 20 ? m + x : m + m[x - 20]++; }
int s() { return f(1) < 20 ? m[x] : m[m[x - 20]]; }

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
