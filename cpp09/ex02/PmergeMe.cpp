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

void displayV(std::vector< std::vector<int> >& vec) {
	std::vector< std::vector<int> >::iterator i;
	std::vector<int> now;

	for (i=vec.begin(); i!=vec.end(); i++) {
		std::cout << "(";
		now = *i;
		display(now, false);
		std::cout << ")";
	}
	std::cout << std::endl;
}

/* VECTOR sort */
void PmergeMe::sort() {
	std::size_t i;
	std::vector< std::vector<int> > vec;

	// 1. 전부다 2차원 벡터로 만든다.
	for (i=0; i<_vec.size(); i++) {
		std::vector<int> newvec;
		newvec.push_back(_vec[i]);
		vec.push_back(newvec);
	}
	std::cout << "------- 1. initialize -------\n";
	displayV(vec);
	fordJohnson(vec, 1);
	// 2. 결과를 다시 1차원 벡터로 변경
	_vec.clear();
	for (i=0; i<vec.size(); i++) {
		_vec.push_back(vec[i].at(0));
	}
}

/* VECTOR ford-johnson */
void PmergeMe::fordJohnson(std::vector< std::vector<int> >& vec, int depth) {
	std::vector< std::vector<int> >::iterator it;
	std::vector<int>::iterator jt;
	std::vector<int> remain;

	std::cout << "------- 2. next depth... ------\n";
	// 2. mainchain 벡터에 subchain 을 내부 내림차순으로 넣는다.
	for (it=vec.begin(); it!=vec.end(); it++) {
		std::vector<int>& now = *it;
		if (it == vec.end()-1) {
			for (jt=now.begin(); jt!=now.end(); jt++)
				remain.push_back(*jt);
			vec.erase(it);
			std::cout << "remain: ";
			display(remain, true);
			break;
		}
		std::vector<int>& next = *(it+1);
		if (now.size() != next.size())
			break;
		if (now[0] > next[0]) {
			for (jt=next.begin(); jt!=next.end(); jt++)
				now.push_back(*jt);
			vec.erase(it+1);
		}
		else {
			for (jt=now.begin(); jt!=now.end(); jt++)
				next.push_back(*jt);
			vec.erase(it);
		}
	}
	displayV(vec);
	it = vec.begin();
	if (it+1 != vec.end() && it->size() == (it+1)->size())
		fordJohnson(vec, depth*2);

	std::cout << "------ 3. binary insertion -------\n";
	// 3. 이진삽입 실시!
	displayV(vec);
	binaryInsertion(vec, remain, depth);
}

/* VECTOR bianry insertion */
void PmergeMe::binaryInsertion(std::vector< std::vector<int> >&vec, std::vector<int>& remain, int depth) {
	std::vector< std::vector<int> >::iterator it;
	std::vector<int>::iterator jt;
	std::vector<int> newvec;
	int target;
	std::size_t targetIdx;
	std::size_t i, idx;

	// 1. 모든 벡터들에 대해 실시
	for (it=vec.begin(), i=0; it!=vec.end(); it++, i++) {
		// 1-1. 현재 벡터 설정
		std::vector<int>& now = *it;
		if (now.size() != static_cast<std::size_t>(depth*2))
			continue;
		// 1-2. target 설정
		targetIdx = now.size()/2;
		target = now[targetIdx];
		// 1-3. target부터 끝까지 추출해 newvec에 저장
		newvec.clear();
		for (jt=now.begin()+targetIdx; jt!=now.end(); jt++) {
			newvec.push_back(*jt);
		}
		// 1-4. now에서 target~end 까지 삭제
		now.erase(now.begin()+targetIdx, now.end());
		std::cout << "newvec: ";
		display(newvec, true);
		std::cout << "vec: ";
		displayV(vec);
		// 1-5. 이진탐색으로 삽입할 인덱스 설정
		std::cout << "=====[basic bs]=====\n";
		idx = binarySearch(vec, 0, i, target);
		std::cout << "idx: " << idx;
		std::cout << "\n========================\n";
		// 1-6. 삽입
		vec.insert(vec.begin()+idx, newvec);
	}
	// 2. 남아있던 remain 삽입
	if (remain.size() != 0) {
		// 2-1. 이진탐색으로 삽입할 인덱스 설정
		std::cout << "=====[remain bs]=====\n";
		target = remain[0];
		idx = binarySearch(vec, 0, vec.size()-1, target);
		std::cout << "idx: " << idx;
		std::cout << "\n========================\n";
		// 2-2. 삽입
		newvec.clear();
		newvec = remain;
		vec.insert(vec.begin()+idx, newvec);
	}
	displayV(vec);
	std::cout << "---------------------------------\n";
}

/* VECTOR binary search */
std::size_t PmergeMe::binarySearch(std::vector< std::vector<int> >& vec, std::size_t low, std::size_t high, int target) {
	std::size_t mid;

	std::cout << "vec: ";
	displayV(vec);
	std::cout << "target: " << target << " " << low << "~" << high << " \n";

	// 벡터 1개인경우 예외처리
	if (vec.size() == 1)
		return 0;
	// 1. start와 end의 중간값 설정
	mid = (low+high) / 2;
	if (low == high)
		return mid;
	// 2. mid 인덱스 위치의 벡터의 0번 인덱스와 비교
	// 2-1. target이 작은경우
	if (mid != 0 && vec.at(mid-1).at(0) <= target && target <= vec.at(mid).at(0))
		return mid;

	if (target > vec.at(mid).at(0)) {
		if (mid == vec.size()-1)
			return mid+1;
		return binarySearch(vec, mid+1, high, target);
	} else
		return binarySearch(vec, low, mid, target);
}
