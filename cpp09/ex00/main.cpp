#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: INVALID ARGUMENT NUMBER" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1], std::ios::in);
	if (!file.is_open()) {
		std::cerr << "Error: CANNNOT OPEN FILE" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc(file);
		// btc.displayDB();
	} catch (const std::exception& e) {
		std::cerr << "Error: " <<  e.what() << std::endl;
	}
	return 0;
}