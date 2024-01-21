#include "PhoneBook.hpp"
#include <iostream>

int main() {
	std::string	line;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;


	while (1) {
		std::cout << "> ";
		std::cin >> line;
		if (line.compare("ADD") == 0) {
			std::cout << " first name : ";
			std::cin >> firstname;
			std::cout << " last name : ";
			std::cin >> lastname;
			std::cout << " nickname : ";
			std::cin >> nickname;
			std::cout << " phone number : ";
			std::cin >> phoneNumber;
			std::cout << " darkest secret : ";
			std::cin >> darkestSecret;
			std::cout << firstname << " " << lastname << " " << nickname;
		}
	}
}