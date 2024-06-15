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
	_jacobsthal = getJacobsthalNumber(_vec.size()/2+1);
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
	return res;
}

void displayPairVector(std::vector< std::pair<int, int> > pvec) {
	std::vector< std::pair<int, int> >::iterator it;

	for (it=pvec.begin(); it!=pvec.end(); it++)
		std::cout << "(" << it->first << "," << it->second << ") ";
	std::cout << std::endl;
}

void setSubchainIdx(std::vector<int>& subchainIdx, std::vector<int>& subchain) {
	std::size_t i;

	for(i=0; i<subchain.size(); i++)
			subchainIdx.push_back(2*i);
}

void setMainchainIdx(std::vector<int>& mainchainIdx, std::vector<int>& mainchain) {
	std::size_t i;

	for (i=0; i<mainchain.size(); i++) {
		mainchainIdx.push_back(i * 2 + 1);
	}
}

/* VECTOR */
std::vector<int>* PmergeMe::binaryInsertion(std::vector<int>& mainchain, std::vector<int>& subchain) {
	std::size_t i;
	std::size_t j, k, lastInsert;
	int end = 0;
	int idx;
	std::vector<int>::iterator pos;
	std::vector< std::pair<int,int> > tmp;
	std::vector<int> *log = new std::vector<int>();
	std::vector<int> subchainIdx;
	std::vector<int> mainchainIdx;

	std::cout << "binaryInsertion" << std::endl;
	setSubchainIdx(subchainIdx, subchain);
	setMainchainIdx(mainchainIdx, mainchain);
	// mainchain의 인덱스를 순서대로 log에 저장
	for (i=0; i<mainchainIdx.size(); i++)
		log->push_back(mainchainIdx[i]);
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
			idx = std::distance(mainchain.begin(), pos);
			if (*pos < subchain[k-1]) {
				mainchain.insert(pos+1, subchain[k-1]);
				log->insert(log->begin()+idx+1, subchainIdx[k-1]);
			}
			else {
				mainchain.insert(pos, subchain[k-1]);
				log->insert(log->begin()+idx, subchainIdx[k-1]);
			}
			display(mainchain);
		}
		lastInsert = j;
		i++;
	}
	display(mainchain);
	std::cout << "==========\n";
	return log;
}

/*
	1. 하나의 수열을 둘씩 짝지어 쪼갠다.
	2. 재귀 레이어를 내려가며 짝이 1개일때까지 쪼갠다.
		2-1. 각 pair들의 내부를 내림차순 swap한다.
			0  1  2  3  4  5		0  1  2  3  4  5
			59 69 74 77 43 92   ->	69 59 77 74 92 43
		2-2. pair로 쪼갠다.
			0  1  2
			69 77 92
			59 74 43
		2-3. 1개일때까지 2-1~2-2 반복
		    0  1  2			0  1  2			0		1
			69 77 92  -> 	77 69 92   ->	(77,74)	X
			59 74 43		74 59 43		(69,59) (92,43)
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
			3-3-1. [idx순서배열]을 mainchain만 추출한다.
			0  1  2		0  1  2  3  4  5
			0  2  4  ->	1  0  3  2  5  4   ->	
*/

/* VECTOR */
void PmergeMe::sort(std::vector<int>& vec) {
	std::size_t i;
	std::vector< std::pair<long, long> > pairs;
	std::vector<int> mainchain;
	std::vector<int> subchain;
	std::vector<int> *log;
	std::vector<int> tmp;

	// vector를 둘씩 짝지어 pair로 나눈다.
	for (i=0; i<vec.size(); i+=2) {
		if (i == vec.size()-1)
			pairs.push_back(std::make_pair(LONG_MAX, vec[i]));
		else
			pairs.push_back(std::make_pair(vec[i], vec[i+1]));
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
	if (_vmainchain.size() != 0 && _vlog.size() != 0) {
		mainchain = _vmainchain;
		tmp = subchain;
		subchain.clear();
		std::cout << "log ";
		for (i=0; i<_vlog.size(); i++) {
			subchain.push_back(tmp[_vlog[i]]);
			std::cout << tmp[_vlog[i]] << " ";
		}
		std::cout << std::endl;
	}
	display(mainchain);
	display(subchain);
	// 이제 이진탐색을 기반으로 삽입정렬을 수행한다.
	// 이때, 정렬된 mainchain의 인덱스 변화 기록(log)를 받는다.
	log = binaryInsertion(mainchain, subchain);
	_vmainchain = mainchain;
	_vlog = *log;
	display(_vlog);
	delete log;
	// 서브체인을 정렬된 메인체인의 log에 맞게 재배치한다.
	// _vmainchain.clear();
	// for (i=0; i<log->size(); i++) {
	// 	// _vsubchain.push_back(subchain[log->at(i)]);
	// }
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