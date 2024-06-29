#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
	double dnum;
	char* end;

	if (argc < 3)
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

std::vector<int> getJacobsthalNumber(std::size_t n) {
	std::vector<int> res;
	int now;
	std::size_t i;

	res.push_back(0);
	res.push_back(1);
	i = 2;
	while (i <= n) {
		now = res[i/2] + 1;
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
void PmergeMe::sort(int type) {
	std::size_t i;
	std::vector< std::vector<int> > vec;
	std::deque< std::deque<int> > deq;

	if (type == VEC) {
		// 1. 전부다 2차원 벡터로 만든다.
		for (i=0; i<_vec.size(); i++) {
			std::vector<int> newvec;
			newvec.push_back(_vec[i]);
			vec.push_back(newvec);
		}
		fordJohnson(vec, 1);
		// 2. 결과를 다시 1차원 벡터로 변경
		_vec.clear();
		for (i=0; i<vec.size(); i++) {
			_vec.push_back(vec[i].at(0));
		}
	} else {
		// 1. 전부다 2차원 덱으로 만든다.
		for (i=0; i<_deq.size(); i++) {
			std::deque<int> newdeq;
			newdeq.push_back(_deq[i]);
			deq.push_back(newdeq);
		}
		fordJohnson(deq, 1);
		// 2. 결과를 다시 1차원 덱으로 변경
		_deq.clear();
		for (i=0; i<deq.size(); i++) {
			_deq.push_back(deq[i].at(0));
		}
	}
}

/* VECTOR ford-johnson */
void PmergeMe::fordJohnson(std::vector< std::vector<int> >& vec, int depth) {
	std::vector< std::vector<int> >::iterator it;
	std::vector<int>::iterator jt;
	std::vector<int> remain;

	// 2. mainchain 벡터에 subchain 을 내부 내림차순으로 넣는다.
	for (it=vec.begin(); it!=vec.end(); it++) {
		std::vector<int>& now = *it;
		if (it == vec.end()-1) {
			for (jt=now.begin(); jt!=now.end(); jt++)
				remain.push_back(*jt);
			vec.erase(it);
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
	it = vec.begin();
	if (it+1 != vec.end() && it->size() == (it+1)->size())
		fordJohnson(vec, depth*2);
	// 3. 이진삽입
	binaryInsertion(vec, remain, depth);
}

/* VECTOR bianry insertion */
void PmergeMe::binaryInsertion(std::vector< std::vector<int> >&vec, std::vector<int>& remain, int depth) {
	std::vector< std::vector<int> >::iterator it;
	std::size_t i, idx;
	bool end_flag = false;
	double test;

	it = vec.begin();
	i = 0;

	// 0. i=0 먼저 맨앞에 삽입
	insert(vec, 0, *it, false);
	it++; i++;

	// 1. vec 이진삽입
	while (!end_flag) {
		// 1-1. 최대비교횟수 다를때까지(또는 벡터 끝까지) 앞으로 이동
		while (i < vec.size()) {
			i++; it++;
			test = i;
			if (it + 1 == vec.end() || (int)log2(test) != (int)log2(test+1))
				break;
		}
		if (i == vec.size())
			end_flag = true;

		// 1-2. 최대비교횟수가 다르면서 삽입 불필요한 원소까지(또는 벡터 처음까지) 뒤로 이동하면서 이진삽입
		while (i > 0) {
			if (it != vec.end() && it->size() == static_cast<std::size_t>(depth*2)) {
				idx = binarySearch(vec, 0, i, it->at(it->size()/2), false);
				insert(vec, idx, *it, false);
			} else {
				i--; it--;
				if (it->size() != static_cast<std::size_t>(depth*2) && (int)log2(i) != (int)log2(i-1))
					break;
			}
		}
		// 1-3. 다시 앞으로 밀기
		while (i < vec.size()-1 && it->size() != static_cast<std::size_t>(depth*2)) {
			// std::cout << i << " ";
			it++; i++;
		}
	}
	// 2. 남아있던 remain 삽입
	if (remain.size() != 0) {
		idx = binarySearch(vec, 0, vec.size(), remain[0], true);
		insert(vec, idx, remain, true);
	}
}

/* VECTOR binary search */
std::size_t PmergeMe::binarySearch(std::vector< std::vector<int> >& vec, std::size_t low, std::size_t high, int target, bool remain) {
	std::size_t mid;

	// 벡터 1개인경우 예외처리
	if (vec.size() == 1)
		return 0;
	// 1. low와 high 중간값 설정
	mid = (low+high) / 2;
	if (target > vec.at(mid).at(0) && mid == vec.size()-1)
		return mid+1;
	if (low == high)
		return mid;
	// 2. mid 인덱스 위치의 벡터의 0번 인덱스와 비교
	if (mid != 0 && vec.at(mid-1).at(0) <= target && target <= vec.at(mid).at(0))
		return mid;
	// 3. 재귀
	if (target > vec.at(mid).at(0)) {
		return binarySearch(vec, mid+1, high, target, remain);
	} else
		return binarySearch(vec, low, mid, target, remain);
}

/* VECTOR insert */
void insert(std::vector< std::vector<int> >& vec, std::size_t insertIdx, std::vector<int>& now, bool remain) {
	std::size_t targetIdx;
	std::vector<int> newvec;
	std::vector<int>::iterator it;

	// 2. remain 삽입인 경우
	if (remain) {
		newvec = now;
		now.clear();
		vec.insert(vec.begin()+insertIdx, newvec);
		return ;
	}
	targetIdx = now.size() / 2;
	// 3. target부터 끝까지 추출
	for (it=now.begin()+targetIdx; it!=now.end(); it++)
		newvec.push_back(*it);
	// 4. now에서 target~end까지 삭제
	now.erase(now.begin()+targetIdx, now.end());
	// 5. 삽입
	vec.insert(vec.begin()+insertIdx, newvec);
}


