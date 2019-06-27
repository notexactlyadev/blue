#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include <iostream>
#include <iomanip>

// pepe estuvo aqui

int main() {
	// 0000000000000000
	// uint16_t data = 0b0001000000000000;
	//uint16_t packet1 = 0x7001;
	//uint16_t packet2 = 0x1020;
	blue_hw = std::make_unique<blue_machine>();
	uint16_t constraint = 0552;
	//blue_hw->Init();
	// blue_hw->write2memaddr({0004, HLT}, 0U);
	// blue_hw->write2memaddr({0000, LDA}, 1U);
	// blue_hw->write2memaddr({0003, HLT}, 2U);
	// blue_hw->write2memaddr({0002, ADD}, 3U);
	// blue_hw->write2memaddr({0010, STA}, 4U);
	// blue_hw->write2memaddr({0011, RAL}, 5U);
	// blue_hw->write2memaddr({0034, NOP}, 6U);
	// blue_hw->write2memaddr({0010, LDA}, 7U);
	// blue_hw->write2memaddr({0006, ADD}, 8U);
	// blue_hw->write2memaddr({11, STA}, 9U);
	// blue_hw->write2memaddr({0000, JMP}, 10U);

	blue_hw->write2memaddr({0400, JMP}, 0);
	blue_hw->write2memaddr({0550, LDA}, 0400);
	blue_hw->write2memaddr({0552, STA}, 0401);
	blue_hw->write2memaddr({0551, LDA}, 0402);
	blue_hw->write2memaddr({0550, STA}, 0403);
	blue_hw->write2memaddr({0552, LDA}, 0404);
	blue_hw->write2memaddr({0551, STA}, 0405);
	blue_hw->write2memaddr({0000, HLT}, 0406);
	blue_hw->write2memaddr({0547, JMP}, 0407);
	blue_hw->write2memaddr({0333, NOP}, 0550);
	blue_hw->write2memaddr(instruction_cast(NOP, 0555), 0551);
	// blue_hw->write2memaddr({0555, NOP}, 0551);
	//write2memaddr({0000, SRJ}, 6U);
	
	//write2register(packet2, blue_hw.switch_register);

	//blue_hw.deposit();
	//blue_hw.interpret_data(packet1, 1);
	#ifdef __linux__
		system("clear");
	#else
		system("cls");
	#endif

	while(true) {
		
		if(getchar() == 'q') {
			break;
		}
		blue_hw->sys_interpreter(constraint);

		std::cout << "\n";
		for (size_t i = 0; i < constraint; ++i) {
			std::cout << "Memory Position [" << std::setw(4) << std::oct << i << "]: ";
			print_bits(blue_hw->get_memaddr(i));
		}
		std::cout << std::dec << std::setfill(' ');

		std::cout << "Blue Accumulator    " << std::setw(4) << " : ";
		print_bits(blue_hw->access_acc().u16);
	}

	return 0;
}