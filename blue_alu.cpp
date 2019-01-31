#include "include\blue_alu.h"
#include "include\blue_machine.h"
#include "include\blue_state.h"
#include "include\blue_ops.h"

namespace blue {

using namespace internal;

void alu_t::exec_cycle() {
	this->z = blue_hw.acc;
	this->y = blue_hw.mbr;
}

void alu_t::ADD() {
	uint16_t result = this->z._int + this->y._int;
	if (result > 216 || result < (uint16_t)-215) {
		blue_hw.sequencer.togglestate();
		return;
	}
	ops::write2register(result, blue_hw.acc);
}

void alu_t::XOR() {
	uint16_t result = this->z._int ^ this->y._int;
	ops::write2register(result, blue_hw.acc);
}

void alu_t::AND() {
	uint16_t result = this->z._int & this->y._int;
	ops::write2register(result, blue_hw.acc);
}

void alu_t::IOR() {
	uint16_t result = this->z._int | this->y._int;
	ops::write2register(result, blue_hw.acc);
}

void alu_t::alu_reset() {
	ops::write2register(0, this->z);
	ops::write2register(0, this->y);
}
} // blue

