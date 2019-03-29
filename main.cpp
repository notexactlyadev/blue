#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>
#include <iomanip>


int main() {
	// 0000000000000000
	// uint16_t data = 0b0001000000000000;
	//uint16_t packet1 = 0x7001;
	//uint16_t packet2 = 0x1020;
	uint16_t constraint = 15;
	Init();
	write2memaddr({0004, HLT}, 0U);
	write2memaddr({0000, LDA}, 1U);
	write2memaddr({0003, HLT}, 2U);
	write2memaddr({0002, ADD}, 3U);
	write2memaddr({0010, STA}, 4U);
	write2memaddr({0011, RAL}, 5U);
	write2memaddr({0000, SRJ}, 6U);
	write2memaddr({0000, JMP}, 10U);
	//write2register(packet2, blue_hw.switch_register);

	//blue_hw.deposit();
	//blue_hw.interpret_data(packet1, 1);

	while(true) {
		system("cls");
		if(getchar() == 'q') {
			break;
		}
		sys_interpreter(constraint);

		std::cout << "\n";
		for (size_t i = 0; i < constraint; ++i) {
			std::cout << "Memory Position [" << std::setw(4) << std::oct << i << "]: ";
			print_bits(at(i).u16);
		}
		std::cout << std::dec << std::setfill(' ');

		std::cout << "Blue Accumulator    " << std::setw(4) << " : ";
		print_bits(acc->i16);

	}

	return 0;
}