#include "Animal.hpp"

Animal::Animal() :_type("Animal") {
	std::cout << "CREATED <Animal>" << std::endl;
}

Animal::Animal(const Animal& obj) :_type(obj._type) {
	std::cout << "CREATED COPY <Animal>" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	_type = obj._type;
	std::cout << "COPY ASSIGNMENT OPERATOR <Animal>" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "DELETED <Animal>" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "🔉 " <<  _type << " : ??? " << std::endl;
}

std::string Animal::getType() const {
	return _type;
}