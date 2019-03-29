#pragma once

#include "blue_alu.h"
#include "blue_structures.h"
#include "blue_state.h"
#include <array>
#include <cstdint>
#include <memory>

	[[maybe_unused]] static std::array<blue16_t, memory_size> memory_array;
	extern blue16_t* instr_register;
	extern blue16_t* mbr;
	extern blue16_t* mar;
	extern blue16_t* program_counter;
	extern blue16_t* acc;
	extern blue16_t* switch_register;
	extern sequencer_t* sequencer;
	extern std::unique_ptr<alu_t> alu;
	/*
	*/
	void reset_memory();
	/* methods */

	void OP_LDA(size_t mem_dir);
	void OP_STA(size_t mem_dir);

	void OP_CSA();

	void OP_HLT();
	void OP_ADD(uint16_t);
	void OP_XOR();
	void OP_AND();
	void OP_IOR();
	void OP_NOT();

	void OP_SRJ(uint16_t);
	void OP_JMA(uint16_t);
	void OP_JMP(uint16_t);

	void OP_INP();
	void OP_OUT();

	void OP_RAL();
	void SearchRegister();
	void SearchOp();

	void Init();
	void Exit();

	blue16_t &at(size_t index);
	uint16_t get_opcode(size_t index);
	uint16_t get_memaddr(size_t index);
	void write2memaddr(const uint16_t data, const size_t index);
	void write2memaddr(const register_blue data, const size_t index);
	void interpret_data(uint16_t &data, size_t index);
	void sys_interpreter(uint16_t);
	void deposit();
	void sys_reset();