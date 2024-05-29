#include "Bureaucrat.hpp"

/* Orthodox canonical form */
Bureaucrat::Bureaucrat() : _name(""), _grade(1) {}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	_grade = obj._grade;
	return *this;
}
Bureaucrat::~Bureaucrat() {
}
/* ----------------------- */

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::upGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::downGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high : Bureaucrat";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade too low : Bureaucrat";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << _name << " couldn't sign " << form.getName() \
		<< " because grade is too low" << std::endl;
	}
}