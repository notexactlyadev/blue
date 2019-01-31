#pragma once
#include "blue_structures.h"

namespace blue::internal {
struct alu_t {
	structures::blue16_t z, y;
	void alu_reset();
	void exec_cycle();
	void ADD();
	void XOR();
	void AND();
	void IOR();
};
} // namespace blue::internal