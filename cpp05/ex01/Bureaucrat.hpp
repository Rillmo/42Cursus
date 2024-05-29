#ifndef BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		Bureaucrat& operator=(const Bureaucrat& obj);
	public:
		/* Orthodox canonical form */
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		/* ----------------------- */
		Bureaucrat(std::string name, int grade);
		std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj);

#endif