#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: INVALID ARGUMENT NUMBER" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
		rpn.calculate();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}