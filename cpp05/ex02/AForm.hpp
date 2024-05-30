#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExcute;
		/* Orthodox canonical form */
		AForm& operator=(const AForm& obj);
		AForm();
	public:
		AForm(const AForm& obj);
		~AForm();
		/* ----------------------- */
		AForm(std::string name, int gradeToSign, int gradeToExcute);
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
		class FormNotSignedException : public std::exception {
			const char* what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, AForm& obj);

#endif	