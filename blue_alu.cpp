#include "include/blue_alu.h"
#include "include/blue_machine.h"
#include "include/blue_state.h"
#include "include/blue_ops.h"

alu_t::alu_t() {
	z = new blue16_t;
	y = new blue16_t;
	alu_reset();
}

alu_t::~alu_t() {
	delete z;
	delete y;
}

void alu_t::exec_cycle() {
	z->raw_register = reinterpret_cast<blue_machine*>(machine_ptr)->acc->raw_register;
	y->raw_register = reinterpret_cast<blue_machine*>(machine_ptr)->mbr->raw_register;
}

void alu_t::ADD() {
	exec_cycle();
	int16_t result = z->raw_register.data + y->raw_register.data;
	if (result > 216 || result < -215) {
		reinterpret_cast<blue_machine*>(machine_ptr)->sequencer->togglestate();
		return;
	}
	reinterpret_cast<blue_machine*>(machine_ptr)->acc->i16 = result;
}

void alu_t::XOR() {
	reinterpret_cast<blue_machine*>(machine_ptr)->acc->u16 = z->u16 ^ y->u16;
}

void alu_t::AND() {
	reinterpret_cast<blue_machine*>(machine_ptr)->acc->u16 = z->u16 & y->u16;
}

void alu_t::IOR() {
	reinterpret_cast<blue_machine*>(machine_ptr)->acc->u16 = z->u16 | y->u16;
}

void alu_t::alu_reset() {
	z->u16 = 0;
	y->u16 = 0;
}

