#include "include/blue_ops.h"
#include "include/blue_machine.h"
#include "include/blue_util.h"
#include "include/blue_state.h"
#include <cstdint>
#include <cstring>
#include <iostream>

namespace blue {
blue16_t& machine::at(size_t index) { return this->memory_array.at(index); }

uint16_t machine::get_opcode(size_t index) {
	return this->memory_array.at(index)._register.op_code;
}

uint16_t machine::get_memaddr(size_t index) {
	return this->memory_array.at(index)._register.mem_addr;
}

void machine::reset_memory() {
	for (size_t i = 0; i < memory_sz; ++i) {
		machine::write2memaddr(ops::to_rb16t(0), i);
	}
}

void machine::write2memaddr(r_blue16_t data, size_t index) {
	this->memory_array.at(index)._register = data;
}

void machine::interpret_data(uint16_t &data, size_t index) {
	std::memcpy(&this->memory_array.at(index)._register, &data, sizeof(r_blue16_t));
}

void machine::deposit() { this->acc = this->switch_register; }


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
Util cuando se trata de escribir a registros de distintos tamaños,
como el mar o el contador de programas, dado que son de tipo
blue12_t (12 bits).
*/
template <typename T>
void ops::write2register(uint16_t data, T &operand) {
	std::memcpy(&operand._register, &data, sizeof(decltype(operand._register)));
}

/* sys_reset():
Reiniciar el estado de la maquina virtual.
*/
void machine::sys_reset() {
	std::cout << "DEBUG: SYSTEM RESET!!!\n";
	for (size_t i = 0; i < memory_sz; ++i) {
		write2memaddr(ops::to_rb16t(0), i);
	}
	ops::write2register(0, switch_register);
	ops::write2register(0, mbr);
	ops::write2register(0, mar);
	ops::write2register(0, instr_register);
	ops::write2register(0, program_counter);
	/*
	alu reset es accesible debido a que esta funcion es
	parte del objeto machine::
	*/
	alu.alu_reset();
}
/* reinterpretar datos de tipo int -> r_blue16_t */
structures::r_blue16_t ops::to_rb16t(int data) {
	structures::r_blue16_t temp;
	std::memcpy(&temp, &data, sizeof(structures::r_blue16_t));
	return temp;
}

void state::sequencer_t::togglestate() {
	this->working = !this->stopped;
	this->stopped = !this->working;
}

void machine::LDA(size_t mem_dir) { this->at(mem_dir) = this->acc; }
void machine::STA(size_t mem_dir) { this->acc = this->at(mem_dir); }
void machine::CSA() { this->acc = this->switch_register;}

void machine::NOT() {
	uint16_t result = ~this->acc._int;
	std::memcpy(&this->acc, &result, sizeof(blue16_t));
}

void machine::SRJ(uint16_t memaddr) {
	this->acc._register.mem_addr = program_counter._register.mem_addr;
	this->acc._register.op_code = 0;
	ops::write2register(memaddr, program_counter);
}

void machine::JMA(uint16_t memaddr) {
	if (this->acc._int < 0) {
		ops::write2register(memaddr, program_counter);
	} else {
		return;
	}
}

void machine::JMP(uint16_t memaddr) {
	ops::write2register(memaddr, program_counter);
}

void machine::RAL() {
	
}

} // namespace blue

