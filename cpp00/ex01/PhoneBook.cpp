#include "PhoneBook.hpp"
#include <sstream>

int PhoneBook::add(int count) {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

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

	this->conatctList[count].setFirstName(firstName);
	this->conatctList[count].setLastName(lastName);
	this->conatctList[count].setNickName(nickName);
	this->conatctList[count].setPhoneNumber(phoneNumber);
	this->conatctList[count].setDarkestSecret(darkestSecret);

	return (0);
};

std::string PhoneBook::truncateString(std::string str) {
	if (str.size() > 10) {
		str = str.substr(0, 9);
		str.replace(9, 1, ".");
	}
	return (str);
}

int isNumStr(std::string str) {
	for (unsigned long i=0; i< str.size(); i++) {
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}

void PhoneBook::printContactList() {
	Contact contact;
	std::string input;
	std::stringstream ss;
	int		idx;

	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRSTNAME";
	std::cout << "|" << std::setw(10) << "LASTNAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i=0; i<8; i++) {
		contact = this->conatctList[i];
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncateString(contact.getFirstName());
		std::cout << "|" << std::setw(10) << truncateString(contact.getLastName());
		std::cout << "|" << std::setw(10) << truncateString(contact.getNickName()) << "|" << std::endl;
	}
	std::cout << "=============================================" << std::endl;

	std::cout << "INDEX > ";
	std::cin >> input;
	while (isNumStr(input) == 1) {
		std::cout << "[ERR] NOT A NUMBER" << std::endl;
		return ;
	}
	ss << input;
	ss >> idx;
	while (idx < 1 || idx > 8) {
		std::cout << "[ERR] OUT OF RANGE" << std::endl;
		return ;
	}
	std::cout << "FIRSTNAME : " + this->conatctList[idx - 1].getFirstName() << std::endl;
	std::cout << "LASTNAME : " + this->conatctList[idx - 1].getLastName() << std::endl;
	std::cout << "NICKNAME : " + this->conatctList[idx - 1].getNickName() << std::endl;

}