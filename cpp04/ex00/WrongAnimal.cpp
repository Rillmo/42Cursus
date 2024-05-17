#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :_type("WrongAnimal") {
	std::cout << "CREATED <WrongAnimal>" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) :_type(obj._type) {
	std::cout << "Copy constructor of " << _type << " called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	_type = obj._type;
	std::cout << "Copy assignment operator of " << _type << " called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "DELETED <WrongAnimal>" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "🔉 " <<  _type << " : ??? " << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}