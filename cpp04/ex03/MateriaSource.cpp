#include "MateriaSource.hpp"

/* Orthodox Canonical Form */
MateriaSource::MateriaSource() { 
	for (int i=0; i<4; i++)
		_sources[i] = 0;
}
MateriaSource::MateriaSource(const MateriaSource& obj) {
	for (int i=0; i<4; i++) {
		if (!obj._sources[i])
			return;
		delete _sources[i];
		_sources[i] = (obj._sources[i])->clone();
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	for (int i=0; i<4; i++) {
		if (!obj._sources[i])
			return *this;
		delete _sources[i];
		_sources[i] = (obj._sources[i])->clone();
	}
	return *this;
}
MateriaSource::~MateriaSource() {
	for (int i=0; i<4; i++)
		delete _sources[i];
}
/* ........................ */


// Learn materia to materiaSource
void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	int i=0;
	while (i < 4 && _sources[i])
		i++;
	if (i >= 4) {
		std::cout << "⚠️ All slots are full!" << std::endl;
		return;
	}
	if (_sources[i])
		delete _sources[i];
	_sources[i] = m;
	std::cout << m->getType() << " learned in " << i << std::endl;
}

// Create new materia from sources
AMateria* MateriaSource::createMateria(std::string const& type) {
	int i;
	for (i=0; i<4; i++) {
		if (type == _sources[i]->getType())
			break;
	}
	if (i >= 4 || !_sources[i]) {
		std::cout << "⚠️ Cannot find " << type << std::endl;
		return 0;
	}
	std::cout << _sources[i]->getType() << " created!" << std::endl;
	return _sources[i]->clone();
}