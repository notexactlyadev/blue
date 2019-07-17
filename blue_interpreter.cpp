#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>
#include <iomanip>

void blue_machine::sys_interpreter(uint16_t max_addr) {
	int halt_count = 0;
	for (int i = 0; i < max_addr; ++i) {
		std::cout << "Memory Position [" << std::oct << std::setfill('0') << std::setw(4) << i << std::dec << "] -> ";
		switch (get_opcode(i)) {
			default:
			case opcode_t::NOP: {
				std::cout << "[NOP " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				break;
			}
			case opcode_t::HLT: {
				halt_count++;
				std::cout << "[HLT " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);

				if(halt_count > 1) {
					goto exit_interpreter;
				}
				break;
			}
			case opcode_t::ADD: {
				std::cout << "[ADD " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				OP_ADD(get_memaddr(i));
				break;
			//ADD()
			}
			case opcode_t::XOR: {
				std::cout << "[XOR " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				break;
			}
			case opcode_t::AND: {
				std::cout << "[AND " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				OP_ADD(get_memaddr(i));
				break;
			}
			case opcode_t::IOR: {
				std::cout << "[IOR " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_IOR(get_memaddr(i));
				break;
			}
			case opcode_t::NOT: {
				std::cout << "[NOT " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_NOT(get_memaddr(i));
				break;
			}
			case opcode_t::SRJ: {
				std::cout << "[SRJ " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_SRJ(get_memaddr(i));
				break;
			}
			case opcode_t::JMA: {
				std::cout << "[JMA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_JMA(get_memaddr(i));
				break;
			}
			case opcode_t::JMP: {
				std::cout << "[JMP " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				i = get_memaddr(i) - 1;
				//OP_JMP(get_memaddr(i));
				break;
			}
			case opcode_t::RAL: {
				std::cout << "[RAL " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_RAL(get_memaddr(i));
				break;
			}
			case opcode_t::CSA: {
				std::cout << "[CSA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				//OP_CSA(get_memaddr(i));
				break;
			}
			case opcode_t::STA: {
				std::cout << "[STA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				OP_STA(get_memaddr(i));
				break;
			}
			case opcode_t::LDA: {
				std::cout << "[LDA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(i) << "] ";
				print_bits(at(i).u16);
				OP_LDA(get_memaddr(i));
				break;
			}
		}
	}
	exit_interpreter:
	return;
}	

