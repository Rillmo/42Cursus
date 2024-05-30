#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		/* Orthodox canonical form */
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
	public:
		Intern();
		~Intern();
		/* ----------------------- */
		class FormNotFoundException : public std::exception {
			const char* what() const throw();
		};
		AForm* cloneShrubbery(std::string target);
		AForm* cloneRoboto(std::string target);
		AForm* clonePres(std::string target);
		AForm* makeForm(std::string name, std::string target);
};


#endif