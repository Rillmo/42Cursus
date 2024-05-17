#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "CREATED <Cat>" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	this->_type = "Cat";
	std::cout << "CREATED COPY <Cat>" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
	_type = obj._type;
	std::cout << "COPY ASSIGNMENT OPERATOR <Cat>" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "DELETED <Cat>" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "🔉 " <<  _type << " : Meow! " << std::endl;
}