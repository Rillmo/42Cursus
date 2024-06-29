#include "BitcoinExchange.hpp"

int isLeapYear(int year) {
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    return 0;
}

std::string isValidDate(std::string date) {
	std::stringstream ss(date);
	std::string tmp;
	int year;
	int month;
	int day;
	int m30[4] = {4, 6, 9, 11};

	std::getline(ss, tmp, '-');
	year = strToDigit<int>(tmp);
	if (year < 1970 || year > 2024)
		throw std::invalid_argument("INVALID YEAR : " + date);
	std::getline(ss, tmp, '-');
	month = strToDigit<int>(tmp);
	if (month < 1 || month > 12)
		throw std::invalid_argument("INVALID MONTH : " + date);
	std::getline(ss, tmp, '-');
	day = strToDigit<int>(tmp);
	if (day < 1 || day > 31)
		throw std::invalid_argument("INVALID DAY : " + date);
	if ((!isLeapYear(year) && month == 2 && day > 28) || (isLeapYear(year) && month == 2 && day > 29))
		throw std::invalid_argument("INVALID DAY : " + date);
	for (int i=0; i<4; i++) {
		if (m30[i] == month && day > 30)
			throw std::invalid_argument("INVALID DAY : " + date);
	}
	return date;
}

float isValidValue(std::string val) {
	float res;

	if (val.size() == 0)
		throw std::invalid_argument("INVALID VALUE : none");
	res = strToDigit<float>(val);
	if (res < 0 || res > 1000)
		throw std::invalid_argument("INVALID VALUE : " + val);
	return res;
}

float isValidPrice(std::string price) {
	float res;

	res = strToDigit<float>(price);
	if (res < 0)
		throw std::invalid_argument("INVALID PRICE : " + price);
	return res;
}

double BitcoinExchange::calculatePrice(std::string date, float value) {
	std::map<std::string, float>::iterator it;

	it = _db.find(date);
	if (it != _db.end())
		return value * it->second;
	it = _db.upper_bound(date);
	if (it == _db.begin())
		return value * _db.begin()->second;
	return (--it)->second * value;
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::ifstream& file) {
	std::string line;
	std::string date;
	std::string price;
	std::string value;
	float valueFloat;
	std::ifstream dbfile("data.csv", std::ios::in);

	std::getline(dbfile, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::invalid_argument("INVALID HEADER STRING");
	while (std::getline(dbfile, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price);
		_db.insert(std::make_pair(isValidDate(date), isValidPrice(price)));
	}
	std::getline(file, line);
	if (line.compare("date | value") != 0)
		throw std::invalid_argument("INVALID HEADER STRING");
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ' ');
		std::getline(ss, value, ' ');
		std::getline(ss, value, ' ');
		try {
			date = isValidDate(date);
			valueFloat = isValidValue(value);
			std::cout << date << " => " << valueFloat << " = " << calculatePrice(date, valueFloat) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& btc) {
	_db = btc._db;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& btc) {
	_db = btc._db;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::displayDB() {
	std::map<std::string, float>::iterator it;

	std::cout << "<DATABASE>" << std::endl;
	for (it = _db.begin(); it != _db.end(); it++)
		std::cout << it->first << "  " << it->second << std::endl;
}