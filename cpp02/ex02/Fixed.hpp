#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fract = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &f);
		Fixed& operator=(const Fixed &f);
		~Fixed();
		int	getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		bool operator>(const Fixed &f);
		bool operator<(const Fixed &f);
		bool operator>=(const Fixed &f);
		bool operator<=(const Fixed &f);
		bool operator==(const Fixed &f);
		bool operator!=(const Fixed &f);
		Fixed operator+(const Fixed &f);
		Fixed operator-(const Fixed &f);
		Fixed operator*(const Fixed &f);
		Fixed operator/(const Fixed &f);
		Fixed& operator++();
		Fixed operator++(int n);
		Fixed& operator--();
		Fixed operator--(int n);
		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif