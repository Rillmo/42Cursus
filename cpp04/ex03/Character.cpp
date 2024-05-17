#include "Character.hpp"

/* Orthodox Canonical Form */
Character::Character() {
	_name = "";
	for (int i=0; i<4; i++)
		_slots[i] = 0;
}
Character::Character(const Character& obj) {
	_name = obj.getName() + "_copy";
	for(int i=0; i<4; i++) {
		if (!obj._slots[i])
			return;
		delete _slots[i];
		_slots[i] = (obj._slots[i])->clone();
	}
}
Character& Character::operator=(const Character& obj) {
	for (int i=0; i<4; i++) {
		if (!obj._slots[i])
			return *this;
		delete _slots[i];
		_slots[i] = (obj._slots[i])->clone();
	}
	return *this;
}
Character::~Character() {
	for (int i=0; i<4; i++) {
		delete _slots[i];
	}
}
/* ........................ */

// Constructor to set name
Character::Character(std::string name) {
	_name = name;
	for (int i=0; i<4; i++)
		_slots[i] = 0;
}

// Get name
std::string const& Character::getName() const {
	return _name;
}

// Equip a materia to slot
void Character::equip(AMateria* m) {
	if (!m)
		return;
	int i=0;
	while (i < 4 && _slots[i] && _slots[i] != m)
		i++;
	if (i >= 4) {
		std::cout << "⚠️ All slots are full!" << std::endl;
		return;
	}
	if (_slots[i] == m)
		return;
	_slots[i] = m;
	std::cout << _name << " equiped " << m->getType() << " in " << i << std::endl;
}

// Unequip a materia from slot
void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid index" << std::endl;
	else if (!_slots[idx])
		std::cout << "⚠️ Caannot unequip empty slot" << std::endl;
	else {
		_trash = _slots[idx];	// save trash
		std::cout << _name << " unequiped " << _slots[idx]->getType() << std::endl;
		_slots[idx] = 0;
	}
}

// Use materia in slot to target
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		std::cout << "Invalid index" << std::endl;
	else if (!_slots[idx])
		std::cout << "⚠️ Cannot use empty slot" << std::endl;
	else
		_slots[idx]->use(target);
}

// Pick trash that unequiped
AMateria* Character::pickTrash() {
	return _trash;
}