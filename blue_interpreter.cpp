#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>
#include <iomanip>

void blue_machine::sys_interpreter(uint16_t max_addr) {
	for (int i = 0; i < max_addr; ++i) {
		std::cout << "Memory Position [" << std::oct << std::setfill('0') << std::setw(4) << i << std::dec << "] -> ";
		switch (get_opcode(i)) {
			default: {
				print_bits(get_memaddr(i));
				std::cout << " -> Unrecognized OP \n";
				break;
			}
			case opcode_t::HLT: {
				std::cout << "[HLT] ";
				print_bits(get_memaddr(i));
				break;
			}
			case opcode_t::NOP: {
				std::cout << "[NOP] ";
				std::cout << "\n";
				break;
			}
			case opcode_t::ADD: {
				std::cout << "[ADD] ";
				print_bits(get_memaddr(i));
				OP_ADD(get_memaddr(i));
				break;
			//ADD()
			}
			case opcode_t::XOR: {
				std::cout << "[XOR] ";
				print_bits(get_memaddr(i));
				break;
			}
			case opcode_t::AND: {
				std::cout << "[AND] ";
				print_bits(get_memaddr(i));
				OP_ADD(get_memaddr(i));
				break;
			}
			case opcode_t::IOR: {
				std::cout << "[IOR] ";
				print_bits(get_memaddr(i));
				//OP_IOR(get_memaddr(i));
				break;
			}
			case opcode_t::NOT: {
				std::cout << "[NOT] ";
				print_bits(get_memaddr(i));
				//OP_NOT(get_memaddr(i));
				break;
			}
			case opcode_t::SRJ: {
				std::cout << "[SRJ] ";
				print_bits(get_memaddr(i));
				//OP_SRJ(get_memaddr(i));
				break;
			}
			case opcode_t::JMA: {
				std::cout << "[JMA] ";
				print_bits(get_memaddr(i));
				//OP_JMA(get_memaddr(i));
				break;
			}
			case opcode_t::JMP: {
				std::cout << "[JMP] ";
				print_bits(get_memaddr(i));
				i = get_memaddr(i) - 1;
				//OP_JMP(get_memaddr(i));
				break;
			}
			case opcode_t::RAL: {
				std::cout << "[RAL] ";
				print_bits(get_memaddr(i));
				//OP_RAL(get_memaddr(i));
				break;
			}
			case opcode_t::CSA: {
				std::cout << "[CSA] ";
				print_bits(get_memaddr(i));
				//OP_CSA(get_memaddr(i));
				break;
			}
			case opcode_t::STA: {
				std::cout << "[STA] ";
				print_bits(get_memaddr(i));
				OP_STA(get_memaddr(i));
				break;
			}
			case opcode_t::LDA: {
				std::cout << "[LDA] ";
				print_bits(get_memaddr(i));
				OP_LDA(get_memaddr(i));
				break;
			}
		}
	}
}	

