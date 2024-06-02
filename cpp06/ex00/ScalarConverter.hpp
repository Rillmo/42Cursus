#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		static void convert(const std::string& input);
};

#endif