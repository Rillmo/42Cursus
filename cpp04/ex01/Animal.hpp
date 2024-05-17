#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif