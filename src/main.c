#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>


enum {
	END,
	LD1, // 1
	LD2,
	LD3,
	MOV, // 4
	ADD,
	SUB,
	MUL,
	INC, // 8
	DEC,
	JMP, // 10
	JZ,
	JNZ,
	GET, // 13
	PUT,
	SLP,
};

uint8_t		bin[1 << 12];
uint16_t	mem[1 << 12];
uint16_t	reg[8];
uint16_t	pc;
uint16_t*	a;

uint8_t fetch() {
	uint8_t c = bin[pc / 2];
	return (c >> pc++ % 2 * 4) & 0xf;
}

uint16_t number(uint8_t len) {
	uint16_t n = 0;
	while (len--) n = n << 4 | fetch();
	return n;
}

uint16_t* dst() {
	uint8_t m = fetch();
	if (m < 8) return a = reg + m;
	return a = mem + reg[m % 8];
}

uint16_t src() {
	uint8_t m = fetch();
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
	uint8_t op, n;
	while ((op = fetch())) {
		switch (op) {
		case LD1:
		case LD2:
		case LD3: dst(); *a = number(op - LD1 + 1); break;
		case MOV: dst(); *a = src(); break;
		case ADD: dst(); *a += src(); break;
		case SUB: dst(); *a -= src(); break;
		case MUL: dst(); *a *= src(); break;
		case INC: ++*dst(); break;
		case DEC: --*dst(); break;
		case JMP:
		case JZ:
		case JNZ: n = number(3); if (op == JMP || !*a ^ (op == JNZ)) pc = n; break;
		case GET: *dst() = getchar(); break;
		case PUT: putchar(*a); break;
		case SLP: usleep(50000); break;
		}
	}
	system("stty sane");
	return 0;
}
