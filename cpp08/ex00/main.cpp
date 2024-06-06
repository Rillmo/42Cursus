#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include "easyfind.hpp"

int main() {
	/* vector */
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	
	try {
		std::cout << easyfind(vec, 0) << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	/* set */
	std::set<int> set;

	set.insert(10);
	set.insert(20);
	set.insert(30);
	set.insert(40);
	
	try {
		std::cout << easyfind(vec, 10) << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	/* stack */
	std::stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	try {
		std::cout << easyfind(vec, 30) << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}