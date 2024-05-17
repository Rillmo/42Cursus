#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->_type = "WrongCat";
	std::cout << "CREATED <WrongCat>" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj) {
	this->_type = "WrongCat";
	std::cout << "Copy constructor of " << _type << " called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	_type = obj._type;
	std::cout << "Copy assignment operator of " << _type << " called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "DELETED <WrongCat>" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "🔉 " <<  _type << " : Meow! " << std::endl;
}