#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <utility>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _jacobsthal;
		std::vector<int> _vec;
		std::vector<int> _vorigin;
		std::vector<int> _vmainchain;
		std::vector<int> _vlog;
		std::deque<int> _deq;
		std::deque<int> _dorigin;
		std::deque<int> _dmainchain;
		PmergeMe();
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& pm);
		PmergeMe& operator=(const PmergeMe& pm);
		~PmergeMe();
		std::vector<int>& getVec();
		std::vector<int>& getVorigin();
		void sort(std::vector<int>& vec);
		void fordJohnson(std::vector< std::vector<int> >& vec, int depth);
		void binaryInsertion(std::vector< std::vector<int> >& vec, int depth);
		std::size_t binarySearch(const std::vector< std::vector<int> >& vec, std::size_t low, std::size_t high, int target);
		std::deque<int>& getDeq();
		std::deque<int>& getDorigin();
		void sort(std::deque<int>& deq);
		void binaryInsertion(std::deque<int>& mainchain, std::deque<int>& subchain);
};

template <typename T>
void display(T& container, bool endl) {
	typename T::iterator it;

	for (it=container.begin(); it!=container.end(); it++)
		std::cout << *it << " ";
	if (endl)
		std::cout << std::endl;
}

std::vector<int> getJacobsthalNumber(int n);

#endif