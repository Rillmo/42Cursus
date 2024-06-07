#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int n) : _n(n) {}
Span::Span(const Span& span) : _vec(span._vec), _n(span._n) {}
Span& Span::operator=(const Span& span) {
	_vec = span._vec;
	_n = span._n;
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
	if (_vec.size() == _n)
		throw Span::TooManyElemException();
	_vec.push_back(num);
}

int Span::shortestSpan() {
	return 1;
}

int Span::longestSpan() {
	return 1;
}

void Span::fill(int num) {
	std::vector<int>::iterator itr;
	for (itr=_vec.begin();)
}

const char* Span::TooManyElemException::what() const throw() {
	return "TOO MANY ELEMENT";
}