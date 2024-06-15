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
		_deq.push_back(static_cast<int>(dnum));
	}
	_jacobsthal = getJacobsthalNumber(_vec.size()*2);
	_vorigin = _vec;
	_dorigin = _deq;
}

PmergeMe::PmergeMe(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++) {
		_vec.push_back(pm._vec[i]);
		_vorigin.push_back(pm._vorigin[i]);
	}
	_deq.clear();
	for (std::size_t i=0; i<pm._deq.size(); i++) {
		_deq.push_back(pm._deq[i]);
		_dorigin.push_back(pm._dorigin[i]);
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pm) {
	_vec.clear();
	for (std::size_t i=0; i<pm._vec.size(); i++) {
		_vec.push_back(pm._vec[i]);
		_vorigin.push_back(pm._vorigin[i]);
	}
	_deq.clear();
	for (std::size_t i=0; i<pm._deq.size(); i++) {
		_deq.push_back(pm._deq[i]);
		_dorigin.push_back(pm._dorigin[i]);
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int>& PmergeMe::getVec() {
	return _vec;
}

std::vector<int>& PmergeMe::getVorigin() {
	return _vorigin;
}

std::deque<int>& PmergeMe::getDeq() {
	return _deq;
}

std::deque<int>& PmergeMe::getDorigin() {
	return _dorigin;
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
	display(res);
	return res;
}

void displayPairVector(std::vector< std::pair<long, long> > pvec) {
	std::vector< std::pair<long, long> >::iterator it;

	for (it=pvec.begin(); it!=pvec.end(); it++)
		std::cout << "(" << it->first << "," << it->second << ") ";
	std::cout << std::endl;
}

void setIdxpairs(std::vector<int> log, std::vector< std::pair<long,long> >& idxpairs) {
	std::size_t i;

	for (i=0; i<log.size(); i+=2) {
		if (i == log.size()-1)
			idxpairs.push_back(std::make_pair(-1, log[i]));
		else
			idxpairs.push_back(std::make_pair(log[i], log[i+1]));
	}
	std::cout << "idxpairs";
	displayPairVector(idxpairs);
}

std::size_t binarySearch(std::vector< std::pair<long,long> > pairs, std::size_t low, std::size_t high, int target) {
	std::size_t mid;

	mid = (low + high) / 2;
	if (low == high)
		return mid;
	if (mid != 0 && pairs[mid-1].first < target && pairs[mid].first > target)
		return mid;
	if (pairs[mid].first < target) {
		if (mid == pairs.size()-1)
			return mid+1;
		return binarySearch(pairs, mid+1, high, target);
	}
	else {
		if (mid == 0)
			return 0;
		return binarySearch(pairs, low, mid, target);
	}
}

/* VECTOR */
void PmergeMe::binaryInsertion(std::vector< std::pair<long,long> > pairs, std::vector<int>& log, std::vector<int>& mainchain) {
	std::size_t i;
	std::size_t j, k, lastInsert;
	int end = 0, target;
	std::size_t idx;
	std::vector< std::pair<long,long> > idxpairs;

	std::cout << "binaryInsertion" << std::endl;
	// 1. log를 기준으로 inxpairs를 세팅
	setIdxpairs(log, idxpairs);
	lastInsert = 0;
	i = 2;
	while (!end) {
		// 야곱스탈 수열의 i항을 가져온다.
		j = _jacobsthal[i];
		if (j > pairs.size()) {
			j = pairs.size();
			end = 1;
		}
		// 야곱스탈 수 -> 마지막 삽입 인덱스 순으로 이진삽입
		for (k=j; k>lastInsert; k--) {
			if (pairs[k-1].second == -1)
				continue;
			target = pairs[k-1].second;
			idx = binarySearch(pairs, 0, k-1, target);
			std::cout << "target:" << target << " range(0," << k-1 << ") idx:" << idx << std::endl;
			pairs[k-1].second = -1;
			pairs.insert(pairs.begin()+idx, std::make_pair(target, -1));
			idxpairs.insert(idxpairs.begin()+idx, std::make_pair(idxpairs[k-1].second, -1));
			displayPairVector(pairs);
			displayPairVector(idxpairs);
		}
		lastInsert = j;
		i++;
	}
	// idxpairs를 기준으로 log를 재배치한다.
	log.clear();
	for (i=0; i<idxpairs.size(); i++) {
		if (idxpairs[i].first != -1)
			log.push_back(idxpairs[i].first);
	}
	// pairs를 기준으로 mainchain도 재배치한다.
	mainchain.clear();
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first < INT_MAX)
			mainchain.push_back(pairs[i].first);
	}
	std::cout << "==========\n";
}

/*
	1. pair로 쪼갠다.
		0  1  2  3  4  5		0  1  2
		59 69 74 77 43 92	->	59 74 43
								69 77 92
	2. 재귀 레이어를 내려가며 짝이 1개일때까지 쪼갠다.
		2-1. 전체 수열의 log를 만든다.
			0  1  2			0  1  2
			59 74 43	->  0  2  4
			69 77 92		1  3  5
		2-2. 각 pair들의 내부를 내림차순 swap한다.
			0  1  2
			69 77 92	
			59 74 43   
		2-3. 1개일때까지 2-1~2-2 반복
			0  1  2			0  1  2			0	1
			69 77 92  -> 	77 69 92   ->	77	X
			59 74 43		74 59 43		69 	92
			0  1  2			1  0  2
	3. 쪼개진 짝을 이진삽입으로 다시 합친다. ([idx순서배열]과 [pair] 필요)
		3-1. 이때 pair는 아래와 같다.
			0  1  2
			69 77 92
			59 74 43
		3-2. 이 pair들을 이진삽입한다.
			0  1  2			0  1  2  3			0  1  2  3  4			0  1  2  3  4  5
			69 77 92   ->	59 69 77 92   ->	43 59 69 77 92   -> 	43 59 69 74 77 92
	      	59 74 43		X  59 74 43			X  X  59 74 43			X  X  59 X  74 43
		3-3. 이진삽입과 동시에 정렬되는 인덱스의 변화를 기준으로 [idx순서배열]도 바꾼다.
			0  1  2	 3  4  5		0  1  2			0  1  2  3		0  1  2  3  4		0  1  2  3  4  5
			1  0  3  2  5  4   ->	1  3  5   -> 	0  1  3  5	->	4  0  1  3  5	->	4  0  1  2  3  5
									0  2  4			X  0  2  4		X  X  0  2  4		X  X  0  X  2  4
		3-4. 완성된 pair에서 mainchain 추출해 _vmainchain에 저장하고, [idx순서배열]도 _vlog에 저장한다.
			_vmainchain :	43 59 69 74 77 92
			_vlog : 		4  0  1  2  3  5
	4. _vlog로 기존의 pair를 재배치한다.
*/

/* VECTOR */
void PmergeMe::sort(std::vector<int>& vec) {
	std::size_t i;
	std::vector< std::pair<long, long> > pairs;
	std::vector< std::pair<long, long> > tmpPairs;
	std::vector<int> mainchain;
	std::vector<int> log;

	// 1. vector를 둘씩 짝지어 pair로 만든다.
	for (i=0; i<vec.size(); i+=2) {
		if (i == vec.size()-1)
			pairs.push_back(std::make_pair(LONG_MAX, vec[i]));
		else
			pairs.push_back(std::make_pair(vec[i], vec[i+1]));
	}

	// 2-1. 전체 수열 기준으로 log 생성.
	for (i=0; i<vec.size(); i++) {
		log.push_back(i);
	}
	// std::cout << "log ";
	// display(log);

	// 2-2. 각 pair들의 내부 요소를 내림차순 swap한다.
	for (std::size_t j=0, i=0; i<pairs.size(); i++, j+=2) {
		if (pairs[i].first < pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
			std::swap(log[j], log[j+1]);
		}
	}
	std::cout << "log ";
	display(log);

	// 3. 각 pair들의 첫번째 요소들을 기준으로 pair들을 오름차순 정렬한다. (재귀)
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first <= INT_MAX)
			mainchain.push_back(pairs[i].first);
	}
	displayPairVector(pairs);
	if (mainchain.size() > 1)
		sort(mainchain);
	// 하위 deps에서 저장했던 _vmainchain과 _vlog를 가져온다.
	if (_vmainchain.size() != 0) {
		mainchain = _vmainchain;
	}
	// _vlog를 기반으로 pair들을 재배치한다.
	if (_vlog.size() != 0) {
		tmpPairs = pairs;
		pairs.clear();
		std::cout << "_vlog: ";
		display(_vlog);
		std::cout << "tmpPairs: ";
		displayPairVector(tmpPairs);
		for (i=0; i<_vlog.size(); i++) {
			pairs.push_back(tmpPairs[_vlog[i]]);
		}
		std::cout << "주목! ";
		displayPairVector(pairs);
	}
	// 3-1. 이제 이진탐색을 기반으로 삽입정렬을 수행한다.
	binaryInsertion(pairs, log, mainchain);
	// 3-2. 삽입정렬이 끝나면, mainchin을 _vmainchain에 저장한다.
	std::cout << "3-1: ";
	display(log);
	display(mainchain);
	_vmainchain = mainchain;
	_vlog = log;
	display(_vlog);
	_vec = _vmainchain;
}

/* DEQUE */
void PmergeMe::binaryInsertion(std::deque<int>& mainchain, std::deque<int>& subchain) {
	std::size_t i;
	std::size_t j, k, lastInsert;
	int end = 0;
	std::deque<int>::iterator pos;

	lastInsert = 0;
	i = 2;
	while (!end) {
		j = _jacobsthal[i];
		if (j > subchain.size()) {
			j = subchain.size();
			end = 1;
		}
		for (k=j; k>lastInsert; k--) {
			pos = std::lower_bound(mainchain.begin(), mainchain.begin()+k-1, subchain.at(k-1));
			if (*pos < subchain[k-1])
				mainchain.insert(pos+1, subchain[k-1]);
			else
				mainchain.insert(pos, subchain[k-1]);
		}
		lastInsert = j;
		i++;
	}
}

void PmergeMe::sort(std::deque<int>& deq) {
	std::size_t i;
	std::deque< std::pair<long, long> > pairs;
	std::deque<int> mainchain;
	std::deque<int> subchain;

	// deque를 둘씩 짝지어 pair로 나눈다.
	for (i=0; i<deq.size(); i+=2) {
		if (i == deq.size()-1)
			pairs.push_back(std::make_pair(LONG_MAX, deq[i]));
		else
			pairs.push_back(std::make_pair(deq[i], deq[i+1]));
	}

	// 각 pair들의 내부 요소를 내림차순 정렬한다.
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	// 각 pair들의 첫번째 요소들을 기준으로 pair들을 오름차순 정렬한다.
	// 이때 정렬은 재귀적으로 수행한다.
	for (i=0; i<pairs.size(); i++) {
		if (pairs[i].first <= INT_MAX)
			mainchain.push_back(pairs[i].first);
		subchain.push_back(pairs[i].second);
	}
	if (mainchain.size() > 1)
		sort(mainchain);
	if (_dmainchain.size() != 0)
		mainchain = _dmainchain;
	// 이제 이진탐색을 기반으로 삽입정렬을 수행한다.
	binaryInsertion(mainchain, subchain);
	_dmainchain = mainchain;
	_deq = _dmainchain;
}