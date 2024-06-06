#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <algorithm>

template <typename T, typename C>
class MutantStack : public std::stack {
	public:
		MutantStack() {};
		MutantStack(const MutantStack& mstack) {*this = mstack;};
		MutantStack& operator=(const MutantStack& mstack) {
			*this = mstack;
			return *this;
		};
		~MutantStack() {};


};

#endif
