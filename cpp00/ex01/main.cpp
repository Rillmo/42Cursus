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
		if (line.compare("ADD") == 0) {
			if (phoneBook.add(count % 8) == 0)
				count++;
		} else if (line.compare("SEARCH") == 0) {
			phoneBook.printContactList();
		} else if (line.compare("EXIT") == 0) {
			exit(EXIT_SUCCESS); 
		} else {
			std::cout << "NO SUCH COMMAND" << std::endl;
		}
	}
}