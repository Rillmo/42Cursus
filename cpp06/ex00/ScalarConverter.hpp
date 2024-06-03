#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>

class ScalarConverter {
	private:
		/* Orthodox Canonical Form */
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		/* ----------------------- */
		static void convert(const std::string& input);
};

#endif