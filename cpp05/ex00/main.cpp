#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat test0("test0", 151);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat test1("test1", 150);
	Bureaucrat test2("test2", 1);

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;

	try {
		test1.downGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		test2.upGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}