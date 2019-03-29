#pragma once
#include <cstdint>

/* The memory size for the emulated machine */
constexpr unsigned memory_size = 4096;

/* opcode_t */
enum opcode_t : uint16_t {
	HLT = 0b0000,
	ADD = 0b0001,
	XOR = 0b0010,
	AND = 0b0011,
	IOR = 0b0100,
	NOT = 0b0101,
	LDA = 0b0110,
	STA = 0b0111,
	SRJ = 0b1000,
	JMA = 0b1001,
	JMP = 0b1010,
	INP = 0b1011,
	OUT = 0b1100,
	RAL = 0b1101,
	CSA = 0b1110,
	NOP = 0b1111
};

struct alignas(sizeof(uint16_t)) register_blue {
	/* 16 bits structure */
	uint16_t data : 12; // memory address
	opcode_t op_code : 4;   // operation code
};

/* The register as a Union for ease of use. */
union blue16_t {
	register_blue raw_register; // register structure
	int16_t i16; // interpreted value as int
	uint16_t u16;
};

struct alu_t {
	blue16_t *z, *y;
	alu_t();
	~alu_t();
	void alu_reset();
	void exec_cycle();
	void ADD();
	void XOR();
	void AND();
	void IOR();
};

struct sequencer_t {
	bool stopped;
	bool working;
	bool search;
	bool exec;
	void togglestate();
};