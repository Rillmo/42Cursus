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
		std::vector<int> _vorigin;
		std::vector<int> _vmainchain;
		PmergeMe();
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& pm);
		PmergeMe& operator=(const PmergeMe& pm);
		~PmergeMe();
		void sort(std::vector<int>& vec);
		std::vector<int>& getVec();
		void binaryInsertion(std::vector<int>& mainchain, std::vector<int>& subchain);
};

void displayVector(const std::vector<int> vec);

std::vector<int> getJacobsthalNumber(int n);

#endif