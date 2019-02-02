#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include <iostream>
#include <Windows.h>


void ui_init() {
	std::cout << "DEBUG: UI INIT!\n";
	SetConsoleTitle("Emublue Debug");
}

	using namespace blue;
	using namespace ops;
	using namespace structures;

int main() {
	// 0000000000000000
	// uint16_t data = 0b0001000000000000;
	uint16_t packet1 = 0x7001;
	uint16_t packet2 = 0x1020;

	blue_hw.sys_reset();

	ui_init();

	write2register(packet2, blue_hw.switch_register);

	blue_hw.deposit();
	blue_hw.interpret_data(packet1, 1);

	for (size_t i = 0; i < 2; ++i) {
		switch (blue_hw.get_opcode(i)) {
		case opcodes::ADD: {
			std::cout << "opcode is ADD\n";
			break;
		//machine::ADD()
		}
		case opcodes::XOR: {
			std::cout << "opcode is XOR\n";
			break;
		}
		case opcodes::STA: {
			std::cout << "opcode is STA\n";
			blue_hw.STA(blue_hw.get_memaddr(i));
			break;
		}
		}
	}

	for (size_t i = 0; i < memory_sz; ++i) {
	printf("memory position %o: ", i);
		blue::util::print_bits(blue_hw.at(i)._int);
	}

	getchar();

	return 0;
}