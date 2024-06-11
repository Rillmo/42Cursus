#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _jacobsthal;
		std::vector<int> _vec;
		int _oddRemain;
		PmergeMe();
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& pm);
		PmergeMe& operator=(const PmergeMe& pm);
		~PmergeMe();
		void sort();
};

std::vector<int> getJacobsthalNumber(int n);

#endif