#include "Intern.hpp"

/* Orthodox canonical form */
Intern::Intern() {}
Intern::Intern(const Intern& obj) {(void)obj;}
Intern& Intern::operator=(const Intern& obj) {(void)obj; return *this;}
Intern::~Intern() {}
/* ----------------------- */

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm* Intern::cloneShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::clonePres(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::cloneRoboto(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string type, std::string target) {
	AForm* (Intern::*funcs[3])(std::string) = {&Intern::cloneShrubbery, &Intern::clonePres, &Intern::cloneRoboto};
	std::string types[3] = {"ShrubberyCreation", "PresidentialPardon", "RobotomyRequest"};

	for (int i=0; i<3; i++) {
		if (type == types[i])
            return (this->*funcs[i])(target);
	}
	throw Intern::FormNotFoundException();
}
