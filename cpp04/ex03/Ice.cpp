#include "Ice.hpp"

/* Orthodox Canonical Form */
Ice::Ice() :AMateria() { _type = "ice"; }
Ice::Ice(const Ice& obj) : AMateria(obj) {}
Ice& Ice::operator=(const Ice& obj) {
	_type = obj._type;
	return *this;
}
Ice::~Ice() {}
/* ........................ */

// Returns a new instance of same type
AMateria* Ice::clone() const {
	return new Ice();
}

// Use Materia to target(ICharacter)
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}