#include "Cat.hpp"

Cat::Cat() {
	std::cout << "CREATED <Cat>" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& obj) {
	std::cout << "CREATED COPY <Cat>" << std::endl;
	this->_type = obj.getType();
	delete _brain;
	this->_brain = new Brain(*obj._brain);
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "COPY ASSIGNMENT OPERATOR <Cat>" << std::endl;
	_type = obj.getType();
	delete _brain;
	_brain = new Brain(*obj._brain);
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "DELETED <Cat>" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "🔉 " <<  _type << " : Meow! " << std::endl;
}

Brain& Cat::getBrain() const {
	return *_brain;
}