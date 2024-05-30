#ifndef BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		/* Orthodox canonical form */
		Bureaucrat& operator=(const Bureaucrat& obj);
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		/* ----------------------- */
		Bureaucrat(std::string name, int grade);
		std::string getName();
		int getGrade();
		void upGrade();
		void downGrade();
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj);

#endif