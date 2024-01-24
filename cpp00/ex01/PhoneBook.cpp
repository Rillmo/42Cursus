#include "PhoneBook.hpp"

int PhoneBook::add(int count) {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	std::cout << count << std::endl;
	std::cout << " first name : ";
	std::cin >> firstName;
	std::cout << " last name : ";
	std::cin >> lastName;
	std::cout << " nickname : ";
	std::cin >> nickName;
	std::cout << " phone number : ";
	std::cin >> phoneNumber;
	std::cout << " darkest secret : ";
	std::cin >> darkestSecret;

	this->conatctList[count].firstName = firstName;
	this->conatctList[count].lastName = lastName;
	this->conatctList[count].nickName = nickName;
	this->conatctList[count].phoneNumber = phoneNumber;
	return (0);
};

void PhoneBook::printContactList() {
	Contact contact;

	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "firstName";
	std::cout << "|" << std::setw(10) << "lastName";
	std::cout << "|" << std::setw(10) << "nickName" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i=0; i<8; i++) {
		contact = this->conatctList[i];
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << contact.firstName;
		std::cout << "|" << std::setw(10) << contact.lastName;
		std::cout << "|" << std::setw(10) << contact.nickName << "|" << std::endl;
	}
	std::cout << "=============================================" << std::endl;
}