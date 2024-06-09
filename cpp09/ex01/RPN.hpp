#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN {
	private:
		std::string _expr;
		std::stack<int> _stack;
		RPN();
	public:
		RPN(std::string expr);
		RPN(RPN& rpn);
		RPN& operator=(RPN& rpn);
		~RPN();
		void calculate();
};

#endif