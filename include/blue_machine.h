#pragma once

#include "blue_structures.h"
#include "blue_alu.h"
#include "blue_state.h"
#include <array>
#include <cstdint>
#include <memory>

class blue_machine {
	friend alu_t;
private:
	std::array<blue16_t, memory_size> memory_array;
	std::unique_ptr<blue16_t> instr_register;
	std::unique_ptr<blue16_t> mbr;
	std::unique_ptr<blue16_t> mar;
	std::unique_ptr<blue16_t> program_counter;
	std::unique_ptr<blue16_t> acc;
	std::unique_ptr<blue16_t> switch_register;
	std::unique_ptr<sequencer_t> sequencer;
	std::unique_ptr<alu_t> alu;
public:
	/*
	*/
	void reset_memory();
	/* methods */

	blue_machine();
	~blue_machine();

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
	blue16_t access_acc();
	uint16_t get_opcode(size_t index);
	uint16_t get_memaddr(size_t index);
	void write2memaddr(const uint16_t data, const size_t index);
	void write2memaddr(const register_blue data, const size_t index);
	void interpret_data(uint16_t &data, size_t index);
	void sys_interpreter(uint16_t);
	void deposit();
	void sys_reset();
};


extern std::unique_ptr<blue_machine> blue_hw;