#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	line;
	std::string	tmp;
	int			count;

	count = 0;
	while (1) {
		std::cout << "> ";
		std::cin >> line;
		if (line.compare("ADD") == 0)
			phoneBook.add(count % 9);
		count++;
	}
}