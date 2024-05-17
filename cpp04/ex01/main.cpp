#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void check_leak() {
	system("leaks ex01");
}

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	atexit(check_leak);

	std::cout << "==========================================" << std::endl;

	const Animal* animals[2];
	animals[0] = new Dog();
	animals[1] = new Cat();


	for (int i=0; i<2; i++)
		delete animals[i];

	std::cout << "==========================================" << std::endl;

	Dog* dog1 = new Dog();

	dog1->getBrain().setIdeas("play");
	dog1->getBrain().showIdeas();

	Dog dog2 = *dog1;
	dog2.getBrain().setIdeas("eat");
	
	dog1->getBrain().showIdeas();
	dog2.getBrain().showIdeas();

	delete dog1;
	return 0;
}