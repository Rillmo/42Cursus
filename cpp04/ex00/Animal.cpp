#include "Animal.hpp"

Animal::Animal() :_type("Animal") {
	std::cout << "Default constructor of Animal " << _type << " called" << std::endl;
}

Animal::Animal(const Animal& obj) :_type(obj._type) {
	std::cout << "Copy constructor of Animal " << _type << " called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	_type = obj._type;
	std::cout << "Copy assignment operator of Animal " << _type << " called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Destructor of Animal " << _type << " called" << std::endl;
}