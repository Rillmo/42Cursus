#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fract;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * 256);
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = f.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	return _value;
}
void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat() const {
	return _value / 256.0f;
}

int Fixed::toInt() const {
	return _value >> _fract;
}

std::ostream& operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}