#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <cmath>

enum type {
	VEC, DEQ
};

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::vector<int> _vorigin;
		std::deque<int> _deq;
		std::deque<int> _dorigin;
		PmergeMe();
	public:
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& pm);
		PmergeMe& operator=(const PmergeMe& pm);
		~PmergeMe();
		std::vector<int>& getVec();
		std::vector<int>& getVorigin();
		void sort(int type);
		void fordJohnson(std::vector< std::vector<int> >& vec, int depth);
		void binaryInsertion(std::vector< std::vector<int> >& vec, std::vector<int>& remain, int depth);
		std::size_t binarySearch(std::vector< std::vector<int> >& vec, std::size_t low, std::size_t high, int target, bool remain);
		std::deque<int>& getDeq();
		std::deque<int>& getDorigin();
		void fordJohnson(std::deque< std::deque<int> >& vec, int depth);
		void binaryInsertion(std::deque< std::deque<int> >& vec, std::deque<int>& remain, int depth);
		std::size_t binarySearch(std::deque< std::deque<int> >& vec, std::size_t low, std::size_t high, int target, bool remain);
};

template <typename T>
void display(T& container, bool endl) {
	typename T::iterator it;

	for (it=container.begin(); it!=container.end(); it++)
		std::cout << *it << " ";
	if (endl)
		std::cout << std::endl;
}

void insert(std::vector< std::vector<int> >& vec, std::size_t insertIdx, std::vector<int>& now, bool remain);
std::deque< std::deque<int> >::iterator  insert(std::deque< std::deque<int> >& vec, std::size_t insertIdx, std::deque<int>& now, bool remain);

#endif