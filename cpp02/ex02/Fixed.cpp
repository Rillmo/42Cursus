#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(const int value) {
	_value = value << _fract;
}

Fixed::Fixed(const float value) {
	_value = roundf(value * 256);
}

Fixed::Fixed(const Fixed &f) {
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &f) {
	this->_value = f.getRawBits();
	return *this;
}

Fixed::~Fixed() {
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

bool Fixed::operator>(const Fixed &f) {
	return _value > f._value;
}

bool Fixed::operator<(const Fixed &f) {
	return _value < f._value;
}

bool Fixed::operator>=(const Fixed &f) {
	return _value >= f._value;
}

bool Fixed::operator<=(const Fixed &f) {
	return _value <= f._value;
}

bool Fixed::operator==(const Fixed &f) {
	return _value == f._value;
}

bool Fixed::operator!=(const Fixed &f) {
	return _value != f._value;
}

Fixed Fixed::operator+(const Fixed &f) {
	Fixed result = *this;

	result.setRawBits(_value + f._value);
	return result;
}

Fixed Fixed::operator-(const Fixed &f) {
	Fixed result = *this;

	result.setRawBits(_value - f._value);
	return result;
}

Fixed Fixed::operator*(const Fixed &f) {
	Fixed result((_value * f._value) / 256.0f / 256.0f);                            

	return result;
}

Fixed Fixed::operator/(const Fixed &f) {
	Fixed result((256.0f * _value) / f._value / 256.0f);

	return result;
}

Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int n) {
	Fixed old(*this);

	n = 0;
	_value += 1;
	return old;
}

Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int n) {
	Fixed old(*this);

	n = 0;
	_value -= 1;
	return old;
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return f2;
	else
		return f1;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return f2;
	else
		return f1;
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	else
		return f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	else
		return f2;
}
