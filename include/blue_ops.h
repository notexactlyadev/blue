#pragma once

#include "blue_structures.h"
#include <cstdint>

namespace blue::ops {

//template <typename R, typename cast>
//void write2register(uint16_t &data, R &operand);
template <typename T>
void write2register(uint16_t data, T &operand);

structures::r_blue16_t to_rb16t(int data);

} // namespace blue::ops