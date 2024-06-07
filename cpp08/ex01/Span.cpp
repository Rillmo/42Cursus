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
	std::vector<int>tmp(_vec);
	std::vector<int>::iterator i;
	int min = std::numeric_limits<int>::max();

	if (_vec.size() <= 1)
		throw Span::NotEnoughElemException();
	std::sort(tmp.begin(), tmp.end());
	for (i=tmp.begin(); i!=tmp.end()-1; i++) {
			if (min > *(i+1)-*i)
			min = *(i+1)-*i;
	}
	return min;
}

int Span::longestSpan() {
	std::vector<int>tmp(_vec);

	if (_vec.size() <= 1)
		throw Span::NotEnoughElemException();
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end()-1) - *tmp.begin();
}

void Span::fill(int num) {
	try {
		while (1)
			addNumber(num);
	} catch (...) {}
}

void Span::display() {
	std::vector<int>::iterator itr;
	for (itr = _vec.begin(); itr != _vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

const char* Span::TooManyElemException::what() const throw() {
	return "TOO MANY ELEMENT";
}

const char* Span::NotEnoughElemException::what() const throw() {
	return "NOT ENOUGH ELEMENT";
}