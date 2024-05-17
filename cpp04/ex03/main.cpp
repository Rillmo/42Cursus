#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void check_leak() {
	system("leaks ex03");
}

int main()
{
	atexit(check_leak);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	delete me->pickTrash();
	me->unequip(1);
	delete me->pickTrash();
	me->unequip(2);
	delete me->pickTrash();
	me->unequip(3);
	delete me->pickTrash();

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}