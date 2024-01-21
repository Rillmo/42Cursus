#include "PhoneBook.hpp"

void PhoneBook::add(int count) {
	Contact now;
	std::string tmp;
	
	now = this->conatctList[count];
	std::cout << " first name : ";
	std::cin >> tmp;
	now.setFirstName(tmp);
	std::cout << " last name : ";
	std::cin >> tmp;
	now.setLastName(tmp);
	std::cout << " nickname : ";
	std::cin >> tmp;
	now.setNickName(tmp);
	std::cout << " phone number : ";
	std::cin >> tmp;
	now.setPhoneNumber(tmp);
	std::cout << " darkest secret : ";
	std::cin >> tmp;
	now.setDarkestSecret(tmp);

	// remove later...
	std::cout << "Contact ADDED! no : " << count << std::endl; 
}