#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>

void sys_interpreter(uint16_t max_addr) {
    for (size_t i = 0; i < max_addr; ++i) {
		std::cout << "position: " << std::oct << i << std::dec << " -> ";
		switch (get_opcode(i)) {
			case opcodes::NOP: {
				std::cout << "No operation\n";
				break;
			}
			case opcodes::ADD: {
				std::cout << "ADD ";
				print_bits(get_memaddr(i));
				OP_ADD(get_memaddr(i));
				break;
			//ADD()
			}
			case opcodes::XOR: {
				std::cout << "XOR ";
				print_bits(get_memaddr(i));
				break;
			}
			case opcodes::STA: {
				std::cout << "STA ";
				print_bits(get_memaddr(i));
				OP_STA(get_memaddr(i));
				break;
			}
			case opcodes::LDA: {
				std::cout << "LDA ";
				print_bits(get_memaddr(i));
				OP_LDA(get_memaddr(i));
				break;
			}
			default: {
				std::cout << "Unrecognized OP \n";
				break;
			}
	}
}
}
	