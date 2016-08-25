#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>

enum { END, LD1, LD2, MOV, ADD, SUB, MUL, RND, INC, DEC, JMP, JZ, JNZ, GET, PUT, SLP };

uint8_t bin[1 << 12];
uint16_t mem[1 << 12], reg[8], pc, *a;

uint16_t fetch(uint8_t len) {
	uint16_t n = 0;
	while (len--) {
		n = n << 4 | bin[pc++];	// debug
//		uint8_t c = bin[pc / 2];
//		n = n << 4 | (c >> pc++ % 2 * 4 & 15);
	}
	return n;
}

uint16_t* dst() {
	uint8_t m = fetch(1);
	if (m < 8) return a = reg + m;
	return a = mem + reg[m % 8];
}

uint16_t src() {
	uint8_t m = fetch(1);
	if (m < 8) return reg[m];
	return mem[reg[m % 8]];
}

int main(int argc, char** argv) {
	assert(argc == 2);
	FILE* f = fopen(argv[1], "r");
	assert(f);
	fread(bin, 1, sizeof(bin), f);
	fclose(f);
	system("stty cbreak -echo min 0");
	uint16_t op, n;
	while ((op = fetch(1))) {
		switch (op) {
		case LD1:
		case LD2: dst(); *a = fetch(op - LD1 + 1); break;
		case MOV: dst(); *a = src(); break;
		case ADD: dst(); *a += src(); break;
		case SUB: dst(); *a -= src(); break;
		case MUL: dst(); *a *= src(); break;
		case RND: dst(); *a = rand() % src(); break;
		case INC: ++*dst(); break;
		case DEC: --*dst(); break;
		case JMP:
		case JZ:
		case JNZ: n = fetch(3); if (op == JMP || !*a ^ (op == JNZ)) pc = n; break;
		case GET: *dst() = getchar(); break;
		case PUT: putchar(*a); break;
		case SLP: usleep(50000); break;

		// TODO: merge SLP and GET
		// TODO: implement RND

		// debugging
		case 16:
			puts("");
			for ( int i = 0; i < 8; i++ ) printf(" %6d |", reg[i]);
			printf(" %03x\n", pc - 1);
			break;


		case 17:
			for ( int i = 0; i < 300; i++ ) printf(" %02x", mem[i]);
			printf("\n");
			break;

		default: return 1;


		}
	}
	system("stty sane");
	return 0;
}
