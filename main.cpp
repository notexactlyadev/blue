#include "include/blue_machine.h"
#include "include/blue_ops.h"
#include "include/blue_util.h"
#include "include/blue_interpreter.h"
#include "include/blue_file.h"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv) {
	if (argc != 2) {
        fprintf(stdout, "\nUsage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
	blue_hw = std::make_unique<blue_machine>();

	#ifdef __linux__
		system("clear");
	#else
		system("cls");
	#endif

	std::cout << "\nReading file: " << argv[1];
	open(blue_hw.get(), argv[1]);
	std::cout << "\nSystem ready, press any key to process\n";
	while(true) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		blue_hw->sys_interpreter(memory_size);

		std::cout << "\n";
		// for (size_t i = 0; i < memory_size; ++i) {
		// 	std::cout << "Memory Position [" << std::setw(4) << std::oct << i << "]: ";
		// 	print_bits(blue_hw->at(i).u16);
		// }
		// std::cout << std::dec << std::setfill(' ');

		std::cout << "Blue Accumulator    " << std::setw(4) << " : ";
		print_bits(blue_hw->access_acc().u16);
		auto pc = blue_hw->program_counter.get()->u16;
		std::cout << "Program Counter: " << std::oct << pc << std::dec << " (DECIMAL: " << pc << ")\n";
	}

	return 0;
}