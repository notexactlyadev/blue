#pragma once

#include "blue_structures.h"
#include <cstdint>

namespace blue::ops {

void write2register(uint16_t &data, structures::blue16_t &operand);

} // namespace blue::ops