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
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif