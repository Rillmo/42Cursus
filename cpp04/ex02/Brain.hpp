#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain();
		void showIdeas() const;
		void setIdeas(std::string idea);
};

#endif