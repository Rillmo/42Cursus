#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int> _vec;
		unsigned int _n;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& span);
		Span& operator=(const Span& span);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void fill(int num);
		void display();
		class TooManyElemException : public std::exception {
			const char* what() const throw();
		};
		class NotEnoughElemException : public std::exception {
			const char* what() const throw();
		};
};

#endif