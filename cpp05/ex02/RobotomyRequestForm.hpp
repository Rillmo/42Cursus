#ifndef ROBOTO_MY_REQUEST_FORM_HPP
#define ROBOTO_MY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		/* Orthodox canonical form */
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	public:
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		/* ----------------------- */
		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const & executor) const;
};


#endif