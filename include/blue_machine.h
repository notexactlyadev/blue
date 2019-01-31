#pragma once

#include "blue_alu.h"
#include "blue_structures.h"
#include "blue_state.h"
#include <array>
#include <cstdint>

namespace blue {
using namespace structures;
using namespace internal;
using namespace state;

class machine {
friend alu_t;
private:
  std::array<blue16_t, memory_sz> memory_array;
  blue16_t instr_register;
  blue16_t mbr;
  blue12_t mar;
  blue12_t program_counter;
  blue16_t acc;
  sequencer_t sequencer;
  alu_t alu;
  /*
  */
  void reset_memory();

public:
  blue16_t switch_register;

  /* methods */

  void LDA(size_t mem_dir);
  void STA(size_t mem_dir);

  void CSA();

  void HLT();
  void ADD();
  void XOR();
  void AND();
  void IOR();
  void NOT();

  void SRJ(uint16_t);
  void JMA(uint16_t);
  void JMP(uint16_t);

  void INP();
  void OUT();

  void RAL();
  void SearchRegister();
  void SearchOp();

  blue16_t &at(size_t index);
  uint16_t get_opcode(size_t index);
  uint16_t get_memaddr(size_t index);
  void write2memaddr(r_blue16_t data, size_t index);
  void interpret_data(uint16_t &data, size_t index);
  void deposit();
  void sys_reset();
};

static machine blue_hw;
} // namespace blue