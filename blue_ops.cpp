#include "include/blue_ops.h"
#include "include/blue_machine.h"
#include <cstdint>

namespace blue {

void machine::LDA(size_t mem_dir) { this->at(mem_dir) = this->alu.acc; }
void machine::STA(size_t mem_dir) { this->alu.acc = this->at(mem_dir); }

blue16_t& machine::at(size_t index) { return this->memory_array.at(index); }

uint16_t machine::get_opcode(size_t index) {
  return this->memory_array.at(index)._register.op_code;
}

uint16_t machine::get_memaddr(size_t index) {
  return this->memory_array.at(index)._register.mem_addr;
}

void machine::write2memaddr(r_blue16_t data, size_t index) {
  this->memory_array.at(index)._register = data;
}

void machine::interpret_data(uint16_t &data, size_t index) {
  this->memory_array.at(index)._register =
      *reinterpret_cast<r_blue16_t *>(&data);
}

void machine::deposit() { this->alu.acc = this->switch_register; }

void ops::write2register(uint16_t &data, blue::blue16_t &operand) {
  operand._register = *reinterpret_cast<blue::r_blue16_t *>(&data);
}
} // namespace blue

