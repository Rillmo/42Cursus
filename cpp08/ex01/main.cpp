#include "Span.hpp"
#include <iostream>

int main() {
	Span sp = Span(5);
	Span sp_err(1);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(0);	// excpetion expected
		sp.fill(10);
		sp.display();
		sp_err.addNumber(1);
		// sp_err.longestSpan(); // exception expected
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}