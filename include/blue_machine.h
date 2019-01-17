#pragma once

#include "blue_alu.h"
#include "blue_structures.h"
#include <array>
#include <cstdint>

namespace blue {
using namespace structures;
using namespace internal;

class machine {
private:
  std::array<blue16_t, memory_sz> memory_array;
  blue16_t mbr;
  blue12_t mar;
  blue12_t program_counter;
  ALU alu;
public:
  blue16_t switch_register;

  /* methods */

  void LDA(size_t mem_dir);
  void STA(size_t mem_dir);
  blue16_t &at(size_t index);
  uint16_t get_opcode(size_t index);
  uint16_t get_memaddr(size_t index);
  void write2memaddr(r_blue16_t data, size_t index);
  void interpret_data(uint16_t &data, size_t index);
  void deposit();

}; // namespace blue
}