#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int numOfFixedPoint;
		static const int numOfFractional = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
};

#endif