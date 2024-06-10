#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>

class PMerge {
	private:
		std::vector<int> _vec;
		PMerge();
	public:
		PMerge(int seq[], int size);
		PMerge(const PMerge& pm);
		PMerge& operator=(const PMerge& pm);
		~PMerge();
		void displayVector();
};

#endif