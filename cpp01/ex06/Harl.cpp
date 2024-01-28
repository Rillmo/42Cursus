#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[DEBUG]\nI love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void) {
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) {
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month.\n";
}

void Harl::error(void) {
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

static int	switchFunc(std::string level) {
	std::string list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i=0; i<4; i++) {
		if (list[i].compare(level) == 0)
			return i;
	}
	return -1;
}

void Harl::complain(std::string level) {
	int funcNum;
	funcNum = switchFunc(level);
	switch (funcNum) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
