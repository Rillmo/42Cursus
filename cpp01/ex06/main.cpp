#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl harl;

	if (argc != 2) {
		std::cout << "argument error ocuured\n";
		return 1;
	}
	std::string input(argv[1]);
	harl.complain(input);
}