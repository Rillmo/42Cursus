#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	Bureaucrat bur0("master", 1);
	AForm *rrf;
	
	try {
		rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
		std::cout << *rrf << std::endl;
		bur0.signForm(*rrf);
		bur0.executeForm(*rrf);
	} catch (const std::exception& e) {}
}
