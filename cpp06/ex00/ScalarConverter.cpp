#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input) {
	double val;
	char* end;
	
	val = std::strtod(input.c_str(), &end);
	if (val == 0.0 && !std::isdigit(input.at(0)) && (end && std::strcmp(end, "f") != 0))
		throw std::exception();

	std::cout << "char : ";
	if (std::isnan(val) || std::isinf(val))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(val)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(val) << std::endl;

	std::cout << "int : ";
	if (std::isnan(val) || std::isinf(val) \
		|| -2147483647 > val || val > 2147483647)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;

	std::cout << "float : ";
	if (std::isinf(val))
		std::cout << std::showpos << static_cast<float>(val);
	else {
		if (static_cast<float>(val) == static_cast<int>(static_cast<float>(val)))
			std::cout << static_cast<float>(val) << ".0";
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val);
	}
	std::cout << "f" << std::endl;

	std::cout << "double : ";
	if (std::isinf(val))
		std::cout << std::showpos << val;
	else {
		if (static_cast<float>(val) == static_cast<int>(static_cast<float>(val)))
			std::cout << static_cast<float>(val) << ".0";
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val);
	}
	std::cout << std::endl;
}