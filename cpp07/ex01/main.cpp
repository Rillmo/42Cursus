#include "iter.hpp"
#include <iostream>

void func1(const int& val) {
	std::cout << val + 1 << " ";
}

template <typename T>
void func2(const T& t) {
	std::cout << t * 2 << " ";
}

int main() {
	int arr[3] = {1, 2, 3};

	iter(arr, 3, func1);
	std::cout << std::endl;
	iter(arr, 3, func2);
	std::cout << std::endl;
}