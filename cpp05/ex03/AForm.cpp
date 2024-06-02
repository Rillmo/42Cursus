#include "AForm.hpp"

/* Orthodox canonical form */
AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(150), _gradeToExcute(150) {}
AForm::AForm(const AForm& obj) : _name(obj._name), _isSigned(obj._isSigned),\
_gradeToSign(obj._gradeToSign), _gradeToExcute(obj._gradeToExcute) {}
AForm& AForm::operator=(const AForm& obj) { 
	_isSigned = obj._isSigned;
	return *this;
}
AForm::~AForm() {}
/* ----------------------- */

AForm::AForm(std::string name, int gradeToSign, int gradeToExcute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExcute(gradeToExcute) {
	if (_gradeToSign < 1 || _gradeToExcute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExcute > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExcute() const {
	return _gradeToExcute;
}

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high : Form";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low : Form";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed : Form";
}

std::ostream& operator<<(std::ostream& out, AForm& obj) {
	out << obj.getName() << ", AForm grade (" << obj.getGradeToSign() \
	<< "/" << obj.getGradeToExcute() \
	<< "/" << std::boolalpha << obj.getIsSigned() \
	<< ") (toSign/toExcute/isSigned)";
	return out;
}
