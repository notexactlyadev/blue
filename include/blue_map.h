#pragma once
#include <unordered_map>
#include <string>
#include "blue_structures.h"

std::unordered_map<std::string, opcode_t> opc_map {
	{"HLT", HLT}, {"ADD", ADD}, {"XOR", XOR} , {"AND", AND},
	{"IOR", IOR}, {"NOT", NOT}, {"LDA", LDA} , {"STA", STA},
	{"SRJ", SRJ}, {"JMA", JMA}, {"JMP", JMP} , {"INP", INP},
	{"OUT", OUT}, {"RAL", RAL}, {"CSA", CSA} , {"NOP", NOP}
};