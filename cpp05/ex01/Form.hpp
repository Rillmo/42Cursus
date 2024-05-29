#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExcute;
		Form& operator=(const Form& obj);
	public:
		/* Orthodox canonical form */
		Form();
		Form(const Form& obj);
		~Form();
		/* ----------------------- */
		Form(std::string name, int gradeToSign, int gradeToExcute);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExcute() const;
		void beSigned(const Bureaucrat& bur);
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, Form& obj);

#endif	