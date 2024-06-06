#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> arr1;
	Array<int> arr2(10);

	try {
		std::cout << "arr1: ";
		for (unsigned int i=0; i<arr1.size(); i++) {
			std::cout << arr1[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "arr2: ";
		for (unsigned int i=0; i<arr2.size(); i++) {
			std::cout << arr2[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "arr1: ";
		arr1 = arr2;
		for (unsigned int i=0; i<arr1.size(); i++) {
			std::cout << arr1[i] << " ";
		}
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}