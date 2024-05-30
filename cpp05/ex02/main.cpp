#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat bur("bur1", 100);
	ShrubberyCreationForm shru("shru");
	
	std::cout << shru << std::endl;
	bur.executeForm(shru);
}