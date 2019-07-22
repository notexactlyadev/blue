#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>
#include <iomanip>

void blue_machine::sys_interpreter(uint16_t max_addr) {
	int halt_count = 0;
	auto& pc = program_counter.get()->i16;
	for (pc = 0; pc < max_addr; ++pc) {
		std::cout << "Memory Position [" << std::oct << std::setfill('0') << std::setw(4) << pc << std::dec << "] -> ";
		switch (get_opcode(pc)) {
			default:
			case opcode_t::NOP: {
				std::cout << "[NOP " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				break;
			}
			case opcode_t::HLT: {
				halt_count++;
				std::cout << "[HLT " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);

				if(halt_count > 1) {
					goto exit_interpreter;
				}
				break;
			}
			case opcode_t::ADD: {
				std::cout << "[ADD " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				OP_ADD(get_memaddr(pc));
				break;
			//ADD()
			}
			case opcode_t::XOR: {
				std::cout << "[XOR " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				break;
			}
			case opcode_t::AND: {
				std::cout << "[AND " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				OP_ADD(get_memaddr(pc));
				break;
			}
			case opcode_t::IOR: {
				std::cout << "[IOR " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_IOR(get_memaddr(pc));
				break;
			}
			case opcode_t::NOT: {
				std::cout << "[NOT " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_NOT(get_memaddr(pc));
				break;
			}
			case opcode_t::SRJ: {
				std::cout << "[SRJ " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_SRJ(get_memaddr(pc));
				break;
			}
			case opcode_t::JMA: {
				std::cout << "[JMA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_JMA(get_memaddr(pc));
				break;
			}
			case opcode_t::JMP: {
				std::cout << "[JMP " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				pc = get_memaddr(pc) - 1;
				//OP_JMP(get_memaddr(pc));
				break;
			}
			case opcode_t::RAL: {
				std::cout << "[RAL " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_RAL(get_memaddr(pc));
				break;
			}
			case opcode_t::CSA: {
				std::cout << "[CSA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				//OP_CSA(get_memaddr(pc));
				break;
			}
			case opcode_t::STA: {
				std::cout << "[STA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				OP_STA(get_memaddr(pc));
				break;
			}
			case opcode_t::LDA: {
				std::cout << "[LDA " << std::oct << std::setfill('0') << std::setw(4) << get_memaddr(pc) << "] ";
				print_bits(at(pc).u16);
				OP_LDA(get_memaddr(pc));
				break;
			}
		}
	}
	exit_interpreter:
	std::cout << "Stopping after " << halt_count << " HLT counts\n";
	return;
}	

