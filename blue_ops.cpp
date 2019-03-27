#include "include/blue_ops.h"
#include "include/blue_machine.h"
#include "include/blue_util.h"
#include "include/blue_state.h"
#include <cstdint>
#include <cstring>
#include <iostream>

blue16_t* instr_register;
blue16_t* mbr;
blue16_t* mar;
blue16_t* program_counter;
blue16_t* acc;
blue16_t* switch_register;
sequencer_t* sequencer;
alu_t* alu;

void Init() {
	acc = new blue16_t;
	mbr = new blue16_t;
	mar = new blue16_t;
	program_counter = new blue16_t;
	instr_register = new blue16_t;
	switch_register = new blue16_t;
	alu = new alu_t();
	sys_reset();
}

void Exit() {
	sys_reset();
	delete acc;
	delete mbr;
	delete mar;
	delete program_counter;
	delete instr_register;
	delete switch_register;
}

blue16_t& at(size_t index) { return memory_array.at(index); }

uint16_t get_opcode(size_t index) {
	return memory_array.at(index).raw_register.op_code;
}

uint16_t get_memaddr(size_t index) {
	return memory_array.at(index).raw_register.data;
}

void reset_memory() {
	for (size_t i = 0; i < memory_size; ++i) {
		memory_array.at(i).i16 = 0;
	}
}

void write2memaddr(const uint16_t data, const size_t index) {
	memory_array.at(index).u16 = data;
}

void write2memaddr(const register_blue data, const size_t index) {
	memory_array.at(index).raw_register = data;
}

void interpret_data(uint16_t &data, size_t index) {
	std::memcpy(&memory_array.at(index), &data, sizeof(blue16_t));
}

void deposit() { acc = switch_register; }


/*
template <typename T, typename R>
void ops::write2register(uint16_t &data, blue::blue16_t &operand) {
	operand._register = *reinterpret_cast<blue::r_blue16_t *>(&data);
}
*/
//template <typename R, typename cast>
/*void ops::write2register(uint16_t &data, R &operand) {
	operand._register = *reinterpret_cast<cast *>(&data);
}*/

/* write2register: 
Escribir en un registro, puede ser cualquier registro.
Util cuando se trata de escribir a registros de distintos tama�os,
como el mar o el contador de programas, dado que son de tipo
blue12_t (12 bits).
*/

template <typename T>
void write2register(uint16_t data, T &operand) {
	std::memcpy(&operand, &data, sizeof(decltype(operand)));
}

/* sys_reset():
Reiniciar el estado de la maquina virtual.
*/
void sys_reset() {
	std::cout << "DEBUG: SYSTEM RESET!!!\n";
	for (size_t i = 0; i < memory_size; ++i) {
		memory_array.at(0).u16 = 0;
	}
	acc->u16 = 0;
	switch_register->u16 = 0;
	mbr->u16 = 0;
	mar->u16 = 0;
	mar->u16 = 0;
	instr_register->u16 = 0;
	program_counter->u16 = 0;
}
/* reinterpretar datos de tipo int -> r_blue16_t */
// structures::r_blue16_t ops::to_rb16t(int data) {
// 	structures::r_blue16_t temp;
// 	std::memcpy(&temp, &data, sizeof(structures::r_blue16_t));
// 	return temp;
// }

void sequencer_t::togglestate() {
	working = !stopped;
	stopped = !working;
}

void OP_STA(const size_t mem_dir) { at(mem_dir).u16 = acc->u16; }
void OP_LDA(const size_t mem_dir) { acc->u16 = at(mem_dir).u16; }
void OP_CSA() { acc->u16 = switch_register->u16; }

void OP_NOT() {
	acc->u16 = ~acc->u16;
}

void OP_SRJ(const uint16_t memaddr) {
	acc->raw_register = program_counter->raw_register;
	acc->raw_register.op_code = static_cast<opcodes>(0);
	at(memaddr).u16 = program_counter->u16;
}

void OP_JMA(uint16_t memaddr) {
	if (acc->i16 < 0) {
		at(memaddr).u16 = program_counter->u16;
	} else {
		return;
	}
}

void OP_JMP(uint16_t memaddr) {
	at(memaddr).u16 = program_counter->u16;
}

void OP_RAL() {
	
}

void OP_ADD(uint16_t memaddr) {
	mbr->raw_register = memory_array.at(memaddr).raw_register;
	alu->ADD();
}

