#include "Intern.hpp"

void check_leak() {
	system("leaks ex03");
}

int main() {
	atexit(check_leak);
	Intern someRandomIntern;
	Bureaucrat bur0("master", 1);
	AForm *rrf;
	
	try {
		rrf = someRandomIntern.makeForm("RobotomyReddquest", "Bender");
		std::cout << *rrf << std::endl;
		bur0.signForm(*rrf);
		bur0.executeForm(*rrf);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
}
