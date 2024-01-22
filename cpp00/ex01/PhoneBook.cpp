#include "PhoneBook.hpp"

int PhoneBook::add(int count) {
	Contact now;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	now = this->conatctList[count];
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

	now.setFirstName(firstName);
	now.setLastName(lastName);
	now.setNickName(nickName);
	now.setPhoneNumber(phoneNumber);
	now.setDarkestSecret(darkestSecret);

	return (0);
};

void PhoneBook::printContactList() {
	Contact contact;

	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "firstName";
	std::cout << "|" << std::setw(10) << "lastName";
	std::cout << "|" << std::setw(10) << "nickName" << "|" << std::endl;
	for (int i=0; i<8; i++) {
		contact = this->conatctList[i];
		std::cout << std::setw(10) << contact.getFirstName();
		std::cout << std::setw(10) << contact.getLastName();
		std::cout << std::setw(10) << contact.getNickName();
		std::cout << std::setw(10) << contact.getPhoneNumber();
		std::cout << std::setw(10) << contact.getDarkestSecret() << std::endl;
	}
}