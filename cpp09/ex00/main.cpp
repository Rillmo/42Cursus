#include "BitcoinExchange.hpp"

int main() {
	std::ifstream file("test.csv", std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("FILE NOT OPEN");
	try {
		BitcoinExchange btc(file);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
}