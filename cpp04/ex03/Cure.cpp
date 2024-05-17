#include "Cure.hpp"

/* Orthodox Canonical Form */
Cure::Cure() : AMateria() { _type = "cure"; }
Cure::Cure(const Cure& obj) : AMateria(obj) {}
Cure& Cure::operator=(const Cure& obj) {
	_type = obj._type;
	return *this;
}
Cure::~Cure() {}
/* ........................ */

// Returns a new instance of same type
AMateria* Cure::clone() const {
	return new Cure();
}

// Use Materia to target(ICharacter)
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}