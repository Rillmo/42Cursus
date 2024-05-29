#include "Form.hpp"

/* Orthodox canonical form */
Form::Form() : _name(""), _isSigned(false), _gradeToSign(150), _gradeToExcute(150) {}
Form::Form(const Form& obj) : _name(obj._name), _isSigned(obj._isSigned),\
_gradeToSign(obj._gradeToSign), _gradeToExcute(obj._gradeToExcute) {}
Form& Form::operator=(const Form& obj) { (void)obj; return *this; }
Form::~Form() {}
/* ----------------------- */

Form::Form(std::string name, int gradeToSign, int gradeToExcute)
: _name(name), _gradeToSign(gradeToSign), _gradeToExcute(gradeToExcute) {
	if (gradeToSign < 1 || gradeToExcute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExcute() const {
	return _gradeToExcute;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
}


const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high : Form";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low : Form";
}

std::ostream& operator<<(std::ostream& out, Form& obj) {
	out << obj << ", Form grade (" << obj.getGradeToSign() \
	<< "/" << obj.getGradeToExcute() << ") (toSign/toExcute)";
	return out;
}
