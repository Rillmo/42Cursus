#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leak() {
	system("leaks ex01");
}

int main() {
	// const Animal ani;
	const Dog* j = new Dog();
	const Cat* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	return 0;
}