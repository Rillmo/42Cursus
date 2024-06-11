#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) :_oddRemain(-1) {
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
}

PmergeMe::PmergeMe(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++)
		_vec.push_back(pm._vec.at(i));
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++)
		_vec.push_back(pm._vec.at(i));
	return *this;
}

PmergeMe::~PmergeMe() {}

void displayVector(const std::vector<int> vec) {
	std::vector<const int>::iterator it;

	for (it=vec.begin(); it!=vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void displayPairVector(std::vector< std::pair<int, int> > pvec, int oddRemain) {
	std::vector< std::pair<int, int> >::iterator it;

	for (it=pvec.begin(); it!=pvec.end(); it++)
		std::cout << "(" << it->first << "," << it->second << ") ";
	if (oddRemain != -1)
		std::cout << "( ," << oddRemain << ")";
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
		now = res.at(i-1) + 2 * res.at(i-2);
		res.push_back(now);
		i++;
	}
	displayVector(res);
	return res;
}

void PmergeMe::sort() {
	std::size_t i;
	std::vector< std::pair<int, int> > pairs;
	std::vector<int> res;
	
	// divide vectors to pairs
	for (i=0; i<_vec.size(); i+=2) {
		if (i == _vec.size()-1)
			_oddRemain = _vec.at(i);
		else
			pairs.push_back(std::make_pair(_vec.at(i), _vec.at(i+1)));
	}
	displayPairVector(pairs, _oddRemain);

	// sort every each pairs in descending order
	for (i=0; i<pairs.size(); i++) {
		if (pairs.at(i).first < pairs.at(i).second)
			std::swap(pairs.at(i).first, pairs.at(i).second);
	}
	displayPairVector(pairs, _oddRemain);

	// sort all pairs in ascending order based on first elem
	std::sort(pairs.begin(), pairs.end());
	displayPairVector(pairs, _oddRemain);

	// add every first elem to result vector
	for (i=0; i<pairs.size(); i++)
		res.push_back(pairs.at(i).first);
	displayVector(res);

	// insert seconde elem to result vector
	// - 현재 인덱스가 jacob이면 현재 인덱스부터 뒤로 삽입 (삽입된 pair는 삭제처리??)
	// 		- 삽입시에는 이진탐색 사용
	// - 현재 인덱스가 jacob이 아니면 넘어감
	int j;
	int lastInsert = 0;
	int end = 0;
	i = 2;
	while (1) {
		j = _jacobsthal.at(i);
		// 만약 jacob이 마지막 인덱스보다 크면 마지막 인덱스부터 삽입하며, 현재 반복을 마지막으로 한다.
		if (j > pairs.size()-1 && _oddRemain == -1) {	// 짝수인경우 (남은수 없음)
			j = pairs.size()-1;
			end = 1;
		}
		if (j > pairs.size() && _oddRemain != -1) {		// 홀수인경우 (남은수 있음)
			j = pairs.size();
			end = 1;
		}
		// 뒤로 삽입(이진탐색)
		for (int k=j; k>lastInsert; k--) {
			// 이진탐색
		}
		if (end)
			break;
		i++;
	}
}