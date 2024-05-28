#include "Bureaucrat.hpp"

/* Orthodox canonical form */
Bureaucrat::Bureaucrat() : _name(""), _grade(1) {}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	_name = obj._name;
	_grade = obj._grade;
	return *this;
}
Bureaucrat::~Bureaucrat() {}
/* ----------------------- */

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade too low\n";
}