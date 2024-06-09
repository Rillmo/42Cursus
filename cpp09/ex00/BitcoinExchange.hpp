#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <stdexcept>

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
};

template <typename T>
T strToDigit(std::string str) {
	char* end;
	double d;
	T res;

	d = std::strtod(str.c_str(), &end);
	if (*end != 0)
		throw std::invalid_argument("INT REQUIRED : " + str);
	res = static_cast<T>(d);
	if (res != d)
		throw std::invalid_argument("INT REQUIRED : " + str);
	return res;
}

#endif