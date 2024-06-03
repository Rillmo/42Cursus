#include "whatever.hpp"
#include <iostream>

int main() {
	std::string a, b;

	a = "a";
	b = "b";
	std::cout << "A : " << a << std::endl;
	std::cout << "B : " << b << std::endl;
	swap(&a, &b);
	std::cout << "A : " << a << std::endl;
	std::cout << "B : " << b << std::endl;
	std::cout << "==============================" << std::endl;

	int c, d;
	c = 2;
	d = 3;
	std::cout << "C : " << c << std::endl;
	std::cout << "D : " << d << std::endl;
	std::cout << "MIN : " << min(c, d) << std::endl;
	std::cout << "==============================" << std::endl;

	std::cout << "C : " << c << std::endl;
	std::cout << "D : " << d << std::endl;
	std::cout << "MAX : " << max(c, d) << std::endl;
	std::cout << "==============================" << std::endl;
}