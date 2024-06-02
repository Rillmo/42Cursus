#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <random>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		/* Orthodox canonical form */
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	public:
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		/* ----------------------- */
		PresidentialPardonForm(std::string target);
		void execute(Bureaucrat const & executor) const;
};


#endif