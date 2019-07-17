#include "include/blue_file.h"
#include "include/blue_map.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void open(blue_machine* machine_ptr, std::string filename) {
	if (!machine_ptr) {
		fprintf(stderr, "Error opening machine_ptr\n");
		exit(EXIT_FAILURE);
	}
	std::string buffer, line;
	std::stringstream line_buf;
	auto file = std::ifstream(filename);
	blue16_t magic;
	int addr = 0;
	if (file.is_open()) {
		while(getline(file, line)) {
			line_buf = std::stringstream(line);
			line_buf >> buffer;
			if (buffer.at(0) == 'o') {
				addr = std::stoi(buffer.substr(1), nullptr, 8);
			} else if (buffer.at(0) == 'h') {
				addr = std::stoi(buffer.substr(1), nullptr, 16);
			} else if (std::isdigit(buffer.at(0))) {
				addr = std::stoi(buffer.substr(0), nullptr, 10);
			}
			line_buf >> buffer;
			magic.raw_register.op_code = opc_map[buffer];
			line_buf >> buffer;
			if (buffer.at(0) == 'o') {
				magic.raw_register.data = std::stoi(buffer.substr(1), nullptr, 8);
			} else if (buffer.at(0) == 'h') {
				magic.raw_register.data = std::stoi(buffer.substr(1), nullptr, 16);
			} else if (std::isdigit(buffer.at(0))) {
				magic.raw_register.data = std::stoi(buffer.substr(0), nullptr, 10);
			}
			machine_ptr->at(static_cast<size_t>(addr)) = magic;
		}
		
	} else {
		fprintf(stderr, "\nError opening file %s, bailing out!\n" , filename.c_str());
		exit(EXIT_FAILURE);
	}

}