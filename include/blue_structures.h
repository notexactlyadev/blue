#pragma once
#include <cstdint>

namespace blue::structures {

/* The memory size for the emulated machine */
constexpr unsigned memory_sz = 4096;

enum opcodes : uint16_t {
  HLT = 0b0000,
  ADD = 0b0001,
  XOR = 0b0010,
  AND = 0b0011,
  IOR = 0b0100,
  NOT = 0b0101,
  LDA = 0b0110,
  STA = 0b0111,
  SRJ = 0b1000,
  JMA = 0b1001,
  JMP = 0b1010,
  INP = 0b1011,
  OUT = 0b1100,
  RAL = 0b1101,
  CSA = 0b1110,
  NOP = 0b1111
};

struct alignas(sizeof(uint16_t)) r_blue16_t {
  /* 16 bits structure */
  uint16_t mem_addr : 12; // memory address
  uint16_t op_code : 4;   // operation code
};

struct r_blue12_t {
  /* 12 bits structure */
  uint16_t mem_addr : 12; // memory address
};

/* The register as a Union for ease of use. */
union blue16_t {
  r_blue16_t _register; // register structure
  int16_t _int;         // interpreted value as int
};

union blue12_t {
  r_blue12_t _register; // register structure
  int16_t _int;         // interpreted value int
};
} // namespace blue::structures