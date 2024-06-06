#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyfind(T& container, int n) {
	for (typename T::iterator itr=container.begin(); itr!=container.end(); itr++) {
		if (*itr == n)
			return *itr;
	}
	throw std::runtime_error("DATA NOT FOUND");
}

#endif