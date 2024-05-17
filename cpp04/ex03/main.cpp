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
	AMateria *tmp1;
	tmp1 = new Ice();
	src->learnMateria(tmp1);
	tmp1 = new Cure();
	src->learnMateria(tmp1);
	tmp1 = new Cure();
	src->learnMateria(tmp1);
	tmp1 = new Cure();
	src->learnMateria(tmp1);
	tmp1 = new Cure();
	src->learnMateria(tmp1);
	delete tmp1;

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
	delete tmp;

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