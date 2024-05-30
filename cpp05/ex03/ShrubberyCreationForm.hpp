#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		/* Orthodox canonical form */
		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();
		/* ----------------------- */
		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const & executor) const;
		AForm& clone(std::string target) const;
};


#endif