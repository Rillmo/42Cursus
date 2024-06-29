#include "PmergeMe.hpp"

std::deque<int>& PmergeMe::getDeq() {
	return _deq;
}

std::deque<int>& PmergeMe::getDorigin() {
	return _dorigin;
}

void displayD(std::deque< std::deque<int> >& deq) {
	std::deque< std::deque<int> >::iterator i;
	std::deque<int> now;

	for (i=deq.begin(); i!=deq.end(); i++) {
		std::cout << "(";
		now = *i;
		display(now, false);
		std::cout << ")";
	}
	std::cout << std::endl;
}

/* DEQUE ford-johnson */
void PmergeMe::fordJohnson(std::deque< std::deque<int> >& deq, int depth) {
	std::deque< std::deque<int> >::iterator it;
	std::deque<int>::iterator jt;
	std::deque<int> remain;

	for (it=deq.begin(); it!=deq.end();) {
		std::deque<int>& now = *it;
		if (it == deq.end()-1) {
			for (jt=now.begin(); jt!=now.end(); jt++)
				remain.push_back(*jt);
			it = deq.erase(it);
			it++;
			break;
		}
		std::deque<int>& next = *(it+1);
		if (now.size() != next.size())
			break;
		if (now[0] > next[0]) {
			for (jt=next.begin(); jt!=next.end(); jt++)
				now.push_back(*jt);
			it = deq.erase(it + 1);
		}
		else {
			for (jt=now.begin(); jt!=now.end(); jt++)
				next.push_back(*jt);
			it = deq.erase(it);
			it++;
		}
	}
	it = deq.begin();
	if (it+1 != deq.end() && it->size() == (it+1)->size())
		fordJohnson(deq, depth*2);

	// 3. 이진삽입 실시!
	binaryInsertion(deq, remain, depth);
}

/* DEQUE bianry insertion */
void PmergeMe::binaryInsertion(std::deque< std::deque<int> >&deq, std::deque<int>& remain, int depth) {
	std::deque< std::deque<int> >::iterator it;
	std::size_t i, idx;
	bool end_flag = false;

	it = deq.begin();
	i = 0;

	// 0. i=0 먼저 맨앞에 삽입
	it = insert(deq, 0, *it, false);
	i++;

	// 1. deq 이진삽입
	while (!end_flag) {
		// 1-1. 최대비교횟수 다를때까지(또는 벡터 끝까지) 앞으로 이동
		while (i < deq.size()) {
			i++; it++;
			if (it+1 == deq.end() || (int)std::log2(i) != (int)std::log2(i+1))
				break;
		}
		if (i == deq.size())
			end_flag = true;
		// 1-2. 최대비교횟수가 다르면서 삽입 불필요한 원소까지(또는 벡터 처음까지) 뒤로 이동하면서 이진삽입
		while (i > 0) {
			// std::cout << i << "\n";
			if (it != deq.end() && it->size() == static_cast<std::size_t>(depth*2)) {
				idx = binarySearch(deq, 0, i, it->at(it->size()/2), false);
				insert(deq, idx, *it, false);
				it = deq.begin() + i;
			} else {
				i--; it--;
				if (it->size() != static_cast<std::size_t>(depth*2) && (int)std::log2(i) != (int)std::log2(i-1))
					break;
			}
		}
		// 1-3. 다시 앞으로 밀기
		while (i < deq.size()-1 && it->size() != static_cast<std::size_t>(depth*2)) {
			it++; i++;
		}
	}
	// 2. 남아있던 remain 삽입
	if (remain.size() != 0) {
		idx = binarySearch(deq, 0, deq.size(), remain[0], true);
		it = insert(deq, idx, remain, true);
	}
}

/* DEQUE binary search */
std::size_t PmergeMe::binarySearch(std::deque< std::deque<int> >& deq, std::size_t low, std::size_t high, int target, bool remain) {
	std::size_t mid;

	// 벡터 1개인경우 예외처리
	if (deq.size() == 1)
		return 0;
	// 1. start와 end의 중간값 설정
	mid = (low+high) / 2;
	if (target > deq.at(mid).at(0) && mid == deq.size()-1)
		return mid+1;
	if (low == high)
		return mid;
	// 2. mid 인덱스 위치의 벡터의 0번 인덱스와 비교
	if (mid != 0 && deq.at(mid-1).at(0) <= target && target <= deq.at(mid).at(0))
		return mid;
	// 3. 재귀
	if (target > deq.at(mid).at(0)) {
		return binarySearch(deq, mid+1, high, target, remain);
	} else
		return binarySearch(deq, low, mid, target, remain);
}

/* DEQUE insert */
std::deque< std::deque<int> >::iterator insert(std::deque< std::deque<int> >& deq, std::size_t insertIdx, std::deque<int>& now, bool remain) {
	std::size_t targetIdx;
	std::deque<int> newdeq;
	std::deque<int>::iterator it;

	// 2. remain 삽입인 경우
	if (remain) {
		newdeq = now;
		now.clear();
		return deq.insert(deq.begin()+insertIdx, newdeq);
	}
	targetIdx = now.size() / 2;
	// 3. target부터 끝까지 추출
	for (it=now.begin()+targetIdx; it!=now.end(); it++)
		newdeq.push_back(*it);
	// 4. now에서 target~end까지 삭제
	now.erase(now.begin()+targetIdx, now.end());
	// 5. 삽입
	return deq.insert(deq.begin()+insertIdx, newdeq);
}
