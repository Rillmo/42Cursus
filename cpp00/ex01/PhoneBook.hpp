#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact conatctList[8];
	public:
		int add(int count);
		void printContactList();
};

#endif