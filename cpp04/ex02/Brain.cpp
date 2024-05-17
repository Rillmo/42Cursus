#include "Brain.hpp"

Brain::Brain() {
	std::cout << "CREATED <Brain>" << std::endl;
	for(int i=0; i<100; i++)
		this->_ideas[i] = "idea";
}

Brain::Brain(const Brain& obj) {
	std::cout << "CREATED COPY <Brain>" << std::endl;
	for (int i=0; i<100; i++)
		this->_ideas[i] = obj._ideas[i];
}

Brain& Brain::operator=(const Brain& obj) {
	std::cout << "COPY ASSIGNMENT OPERATOR <Brain>" << std::endl;
	for (int i=0; i<100; i++)
		this->_ideas[i] = obj._ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "DELETED <Brain>" << std::endl;
}

void Brain::showIdeas() const {
	for (int i=0; i<3; i++)
		std::cout << _ideas[i] << " ";
	std::cout << "...." << std::endl;
}

void Brain::setIdeas(std::string idea) {
	for (int i=0; i<3; i++)
		_ideas[i] = idea;
}