#pragma once
#include <cstdint>

/* The memory size for the emulated machine */
constexpr unsigned memory_size = 4096;

/* opcode_t */
enum opcode_t : uint16_t {
	HLT, ADD, XOR, AND,
	IOR, NOT, LDA, STA,
	SRJ, JMA, JMP, INP,
	OUT, RAL, CSA, NOP
};


struct alignas(sizeof(uint16_t)) register_blue {
	/* 16 bits structure */
	volatile uint16_t data : 12; // memory address
	volatile opcode_t op_code : 4;   // operation code
};

/* The register as a Union for ease of use. */
union blue16_t {
	register_blue raw_register; // register structure
	int16_t i16; // interpreted value as int
	uint16_t u16 = 0;
	// blue16_t() = default;
};

struct alu_t {
	blue16_t *z, *y;
	void* machine_ptr;
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