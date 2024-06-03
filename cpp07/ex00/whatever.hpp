#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T *v1, T *v2) {
	T tmp;

	tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
};

template <typename T>
T min(T v1, T v2) {
	if (v1 < v2)
		return v1;
	else
		return v2;
}

template <typename T>
T max(T v1, T v2) {
	if (v1 > v2)
		return v1;
	else
		return v2;
}

#endif