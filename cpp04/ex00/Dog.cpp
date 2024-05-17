#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "CREATED <Dog>" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	this->_type = "Dog";
	std::cout << "CREATED COPY <Dog>" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
	_type = obj._type;
	std::cout << "COPY ASSIGNMENT OPERATOR <Dog>" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "DELETED <Dog>" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "🔉 " <<  _type << " : Bark! " << std::endl;
}