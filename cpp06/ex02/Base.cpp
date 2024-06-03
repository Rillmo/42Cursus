#include "Base.hpp"

Base::~Base() {}

Base* generate() {
	int random;

	std::srand(std::time(0));
	random = std::rand();
	if (random % 3 == 0)
		return new A();
	else if (random % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	std::cout << "Actual type (*): ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p) {
	std::cout << "Actual type (&): ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {}
}