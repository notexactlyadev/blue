#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_util.h"
#include <iostream>

int main() {
    blue::machine blue_hw;
    //0000000000000000
    //uint16_t data = 0b0001000000000000;
    uint16_t packet1 = 0x7001;
    uint16_t packet2 = 0x1020;

    blue::ops::write2register(packet2, blue_hw.switch_register);
    blue_hw.deposit();

    blue_hw.interpret_data(packet1, 1);
    
    for (int i = 0; i < 2; ++i) {
    switch (blue_hw.get_opcode(i)) {
        case blue::structures::opcodes::ADD: {
            std::cout << "opcode is ADD\n";
        }
        break;
        case blue::structures::opcodes::XOR: {
            std::cout << "opcode is XOR\n";
        }
        break;
        case blue::structures::opcodes::STA: {
            std::cout << "opcode is STA\n";
            blue_hw.STA(blue_hw.get_memaddr(i));
        }
        break;
    }
    }
    for (int i = 0; i < 2; ++i) {
        printf("memory position %i: ", i);
        blue::util::print_bits(blue_hw.at(i)._int);
    }

    getchar();
}