#include "BitcoinExchange.hpp"

int isLeapYear(int year) {
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    return 0;
}

void isValidDate(std::string date) {
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
}

void isValidValue(std::string val) {
	strToDigit<float>(val);
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::ifstream& file) {
	std::string line;
	std::string date;
	std::string price;

	std::getline(file, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::invalid_argument("INVALID HEADER STRING");
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price);
		isValidDate(date);
		isValidValue(price);
		std::cout << date << " | " << price << std::endl;
	}
}
BitcoinExchange::BitcoinExchange(BitcoinExchange& btc) {
	(void)btc;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& btc) {
	(void)btc;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {

}