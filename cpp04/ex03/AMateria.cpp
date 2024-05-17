#include "AMateria.hpp"

/* Orthodox Canonical Form */
AMateria::AMateria() {}
AMateria::AMateria(const AMateria& obj) :_type(obj._type) {}
AMateria& AMateria::operator=(const AMateria& obj) {
	_type = obj._type;
	return *this;
}
AMateria::~AMateria() {}
/* ........................ */

// Constructor to set type
AMateria::AMateria(std::string const& type) {
	_type = type;
}

// Get type
std::string const& AMateria::getType() const {
	return _type;
}

// Use Materia to target(ICharacter)
void AMateria::use(ICharacter& target) {
	std::cout << "* used Materia to " << target.getName() << " *" << std::endl;
}