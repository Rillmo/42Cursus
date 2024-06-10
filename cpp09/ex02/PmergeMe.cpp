#include "PmergeMe.hpp"

PMerge::PMerge() {}

PMerge::PMerge(int seq[], int size) {
	for (int i=0; i<size; i++)
		_vec.push_back(seq[i]);
}

PMerge::PMerge(const PMerge& pm) {
	_vec.clear();
	for (int i=0; i<pm._vec.size(); i++)
		_vec.push_back(pm._vec.at(i));
}

PMerge& PMerge::operator=(const PMerge& pm) {
	_vec.clear();
	for (int i=0; i<pm._vec.size(); i++)
		_vec.push_back(pm._vec.at(i));
}

PMerge::~PMerge() {}


void PMerge::displayVector() {
	std::vector<int>::iterator it;

	for (it=_vec.begin(); it!=_vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}