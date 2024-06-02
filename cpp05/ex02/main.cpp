#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat bur0("master", 1);
	Bureaucrat bur1("bur1", 145);
	ShrubberyCreationForm shru("shru");
	
	std::cout << shru << std::endl;
	bur1.executeForm(shru);	// is not signed

	bur1.signForm(shru);
	std::cout << shru << std::endl;
	bur1.executeForm(shru);	// grade too low
	bur0.executeForm(shru);
	std::cout << "=========================================" << std::endl;

	Bureaucrat bur2("bur2", 72);
	RobotomyRequestForm robo("robo");

	std::cout << robo << std::endl;
	bur2.executeForm(robo);	// is not signed

	bur2.signForm(robo);
	std::cout << robo << std::endl;
	bur2.executeForm(robo);	// grade too low
	bur0.executeForm(robo);
	std::cout << "=========================================" << std::endl;

	Bureaucrat bur3("bur3", 25);
	PresidentialPardonForm pres("pres");

	std::cout << pres << std::endl;
	bur3.executeForm(pres);	// is not signed

	bur3.signForm(pres);
	std::cout << pres << std::endl;
	bur3.executeForm(pres);	// grade too low
	bur0.executeForm(pres);
}
