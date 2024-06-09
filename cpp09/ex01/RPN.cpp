#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(std::string expr) {
	_expr = expr;
}
RPN::RPN(RPN& rpn) {_stack = rpn._stack;}
RPN& RPN::operator=(RPN& rpn) {_stack = rpn._stack; return *this;}
RPN::~RPN() {}

int isoper(char c) {
	char oper[4] = {'+', '-', '*', '/'};

	for (int i=0; i<4; i++) {
		if (c == oper[i])
			return 1;
	}
	return 0;
}

/* 
	1. 숫자면 스택에 넣는다.
	2. 연산자면 스택에서 숫자 2개를 꺼내 연산한다.
	3. 연산된 숫자들 다시 스택에 넣는다.
	4. 숫자가 남거나, 연산자가 남는 경우 에러
*/
void RPN::calculate() {
	std::stringstream ss(_expr);
	std::string token;
	int n1, n2;

	while (std::getline(ss, token, ' ')) {
		// 1자리이고, 숫자 또는 연산자인가?
		if (token.size() != 1 || (!std::isdigit(token[0]) && !isoper(token[0])))
			throw std::invalid_argument("INVALID TOKEN");
		// 숫자라면 스택에 넣는다.
		if (std::isdigit(token[0]))
			_stack.push(token[0]-'0');
		// 연산자면 스택에서 2개 꺼내서 연산 후 다시 넣는다.
		else {
			if (_stack.size() < 2)
				throw std::invalid_argument("INVALID ORDER");
			n1 = _stack.top();
			_stack.pop();
			n2 = _stack.top();
			_stack.pop();
			switch (token[0])
			{
				case '+':
					_stack.push(n2 + n1);
					break;
				case '-':
					_stack.push(n2 - n1);
					break;
				case '*':
					_stack.push(n2 * n1);
					break;
				case '/':
					_stack.push(n2 / n1);
					break;
				default:
					break;
			}
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("INVALID EXPR");
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}