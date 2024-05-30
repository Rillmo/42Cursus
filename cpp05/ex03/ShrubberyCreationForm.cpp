#include "ShrubberyCreationForm.hpp"

/* Orthodox canonical form */
ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("ShrubberyCreationForm", 145, 137) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	(void)obj;
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: AForm(obj) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
/* ----------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (getGradeToExcute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream newFile(_target + "_shrubbery");
	if (newFile.is_open()) {
		newFile << "     *\n";
		newFile << "    /|\\\n";
		newFile << "   /*|O\\\n";
		newFile << "  /*/|\\*\\\n";
		newFile << " /X/O|*\\X\\\n";
		newFile << "/*/X/|\\X\\*\\\n";
		newFile << "    |X|  \n";
	}
}