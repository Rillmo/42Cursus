#include "RobotomyRequestForm.hpp"

/* Orthodox canonical form */
RobotomyRequestForm::RobotomyRequestForm() 
: AForm("RobotomyRequestForm", 72, 45) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	(void)obj;
	return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
: AForm(obj) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
/* ----------------------- */

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (getGradeToExcute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "🚧 drilling....!!" << std::endl;
	std::srand(std::time(nullptr));
	int random = std::rand();
	if (random % 2 == 0)
		std::cout << _target << " has been robotomized " << std::endl;
	else
		std::cout << _target << " failed to robotomized " << std::endl;
}