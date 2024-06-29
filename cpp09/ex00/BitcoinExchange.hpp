#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <utility>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
		BitcoinExchange();
	public:
		BitcoinExchange(std::ifstream& file);
		BitcoinExchange(BitcoinExchange& btc);
		BitcoinExchange& operator=(BitcoinExchange& btc);
		~BitcoinExchange();
		void displayDB();
		double calculatePrice(std::string date, float value);
};

template <typename T>
T strToDigit(std::string str) {
	char* end;
	double f;
	T res;
	std::string type;

	if (typeid(T) == typeid(int))
		type = "INT";
	else if (typeid(T) == typeid(float))
		type = "FLOAT";
	else
		throw std::invalid_argument("INVALID TYPE");
	f = std::strtod(str.c_str(), &end);
	if (*end != 0)
		throw std::invalid_argument(type + " REQUIRED : " + str);
	if (type == "INT" && (f < -2147483648 || f > 2147483647))
		throw std::invalid_argument(type + " REQUIRED : " + str);
	res = static_cast<T>(f);
	if (type == "INT" && res != f)
		throw std::invalid_argument(type + " REQUIRED : " + str);
	return res;
}

#endif