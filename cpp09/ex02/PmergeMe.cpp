#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
	double dnum;
	char* end;

	if (argc < 2)
		throw std::invalid_argument("INVAILD ARGUMENT NUMBER");
	for (int i=1; i<argc; i++) {
		dnum = std::strtod(argv[i], &end);
		if (dnum == 0)
			throw std::invalid_argument("POSITIVE INT REQUIRED: " + std::string(argv[i]));
		if (dnum != static_cast<int>(dnum) || static_cast<int>(dnum) < 0)
			throw std::invalid_argument("POSITIVE INT REQUIRED: " + std::string(argv[i]));
		_vec.push_back(static_cast<int>(dnum));
	}
	_jacobsthal = getJacobsthalNumber(_vec.size()/2+1);
	_vorigin = _vec;
}

PmergeMe::PmergeMe(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++) {
		_vec.push_back(pm._vec[i]);
		_vorigin.push_back(pm._vorigin[i]);
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++) {
		_vec.push_back(pm._vec[i]);
		_vorigin.push_back(pm._vorigin[i]);
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void displayVector(const std::vector<int> vec) {
	std::vector<const int>::iterator it;

	for (it=vec.begin(); it!=vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int>& PmergeMe::getVec() {
	return _vec;
}

void displayPairVector(std::vector< std::pair<long, long> > pvec) {
	std::vector< std::pair<long, long> >::iterator it;

	for (it=pvec.begin(); it!=pvec.end(); it++)
		std::cout << "(" << it->first << "," << it->second << ") ";
	std::cout << std::endl;
}

std::vector<int> getJacobsthalNumber(int n) {
	std::vector<int> res;
	int now;
	std::size_t i;

	res.push_back(0);
	res.push_back(1);
	now = 1;
	i = 2;
	while (now <= n) {
		now = res[i-1] + 2 * res[i-2];
		res.push_back(now);
		i++;
	}
	// displayVector(res);
	return res;
}

std::size_t binarySearch(const std::vector<int>& vec, std::size_t low, std::size_t high, int target) {
	std::size_t mid = (low + high) / 2;

	std::cout << "mid : " << mid << std::endl;
	if (low > high)
		throw std::out_of_range("BINARY SEARCH FAILED");
	if (target < vec[mid] && (mid == 0 || vec[mid-1] < target))
		return mid;
	else if (target > vec[mid])
		return binarySearch(vec, mid+1, high, target);
	else
		return binarySearch(vec, low, mid, target);
}

void PmergeMe::binaryInsertion(std::vector<int>& mainchain, std::vector<int>& subchain) {
	std::size_t i;
	std::size_t j, k, lastInsert;
	int end = 0;
	std::vector<int>::iterator pos;

	// std::cout << "--binaryInsertion--" << std::endl;
	// displayVector(mainchain);
	lastInsert = 0;
	i = 2;
	while (!end) {
		j = _jacobsthal[i];
		if (j > subchain.size()) {
			j = subchain.size();
			end = 1;
		}
		// std::cout << "range:" << lastInsert << "~" << j << " ";
		for (k=j; k>lastInsert; k--) {
			pos = std::lower_bound(mainchain.begin(), mainchain.begin()+k-1, subchain.at(k-1));
			// std::cout << "(" << k-1 << "/" << *pos << ") ";
			if (*pos < subchain[k-1])
				mainchain.insert(pos+1, subchain[k-1]);
			else
				mainchain.insert(pos, subchain[k-1]);
			// displayVector(mainchain);
		}
		lastInsert = j;
		i++;
	}
	// displayVector(mainchain);
}

void PmergeMe::sort(std::vector<int>& vec) {
	std::size_t i;
	std::vector< std::pair<long, long> > pairs;
	std::vector<int> mainchain;
	std::vector<int> subchain;

	// vector를 둘씩 짝지어 pair로 나눈다.
	for (i=0; i<vec.size(); i+=2) {
		if (i == vec.size()-1)
			pairs.push_back(std::make_pair(LONG_MAX, vec[i]));
		else
			pairs.push_back(std::make_pair(vec[i], vec[i+1]));
	}
	// std::cout << "step01 : to pair" << std::endl;

	// 각 pair들의 내부 요소를 내림차순 정렬한다.
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
	// std::cout << "step02 : swap in descending order" << std::endl;

	// 각 pair들의 첫번째 요소들을 기준으로 pair들을 오름차순 정렬한다.
	// 이때 정렬은 재귀적으로 수행한다.
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first <= INT_MAX)
			mainchain.push_back(pairs[i].first);
		subchain.push_back(pairs[i].second);
	}
	// std::cout << "=====sort=====" << std::endl;
	// displayVector(mainchain);
	if (mainchain.size() > 1)
		sort(mainchain);
	if (_vmainchain.size() != 0)
		mainchain = _vmainchain;
	// 이제 이진탐색을 기반으로 삽입정렬을 수행한다.
	binaryInsertion(mainchain, subchain);
	_vmainchain = mainchain;
	_vec = _vmainchain;
	// displayVector(_vmainchain);
}