#include "Point.hpp"
#include "Fixed.hpp"

int main() {
	Point a(0.0f, 0.0f);
	Point b(3.0f, 0.0f);
	Point c(0.0f, 3.0f);
	Point p(1.0f, 4.0f);
	Fixed result;

	result = bsp(a, b, c, p);
	if (bsp(a, b, c, p) == true)
		std::cout << "true";
	else
		std::cout << "false";
	std::cout << std::endl;

	Point p1 = Point(0.0f, 0.0f);
	result = bsp(a, b, c, p1);
	if (bsp(a, b, c, p1) == true)
		std::cout << "true";
	else
		std::cout << "false";
	std::cout << std::endl;

	Point p2 = Point(1.0f, 1.0f);
	result = bsp(a, b, c, p2);
	if (bsp(a, b, c, p2) == true)
		std::cout << "true";
	else
		std::cout << "false";
	std::cout << std::endl;
}