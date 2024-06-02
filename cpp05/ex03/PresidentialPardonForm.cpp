#include "PresidentialPardonForm.hpp"

/* Orthodox canonical form */
PresidentialPardonForm::PresidentialPardonForm() 
: AForm("PresidentialPardonForm", 25, 5) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	(void)obj;
	return *this;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm(obj) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
/* ----------------------- */

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (getGradeToExcute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}