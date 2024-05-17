#include "Dog.hpp"

Dog::Dog() {
	std::cout << "CREATED <Dog>" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& obj) {
	this->_type = obj.getType();
	delete _brain;
	this->_brain = new Brain(obj.getBrain());
	std::cout << "CREATED COPY <Dog>" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
	_type = obj.getType();
	delete _brain;
	_brain = new Brain(obj.getBrain());
	std::cout << "COPY ASSIGNMENT OPERATOR <Dog>" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "DELETED <Dog>" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "🔉 " <<  _type << " : Bark! " << std::endl;
}

Brain& Dog::getBrain() const {
	return *_brain;
}