#include <iostream>
#include <vector>
#include <deque>
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

	/* deque */
	std::deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(40);
	dq.push_back(40);
	
	try {
		std::cout << easyfind(dq, 40) << std::endl;
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