#include "Span.hpp"
#include <iostream>

// int main() {
// 	Span sp = Span(5);

// 	try {
// 		sp.addNumber(6);
// 		sp.addNumber(3);
// 		// sp.addNumber(0);	// excpetion expected
// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	} catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return 0;
// }

int main() {
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::cout << *vec.begin() << std::endl;
	std::cout << *(vec.end()-1) << std::endl;
}