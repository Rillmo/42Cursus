#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat bur1("bur1", 150);
	Bureaucrat bur2("bur2", 2);
	Form form1("form1", 1, 100);
	Form form2("form2", 150, 100);

	bur1.signForm(form1);	// exception
	bur1.signForm(form2);

	bur2.signForm(form1);	// exception
	bur2.signForm(form2);
}