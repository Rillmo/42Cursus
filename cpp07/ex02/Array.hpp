#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
	private:
		T* _arr;
		std::size_t _size;
	public:
		Array() {
			_arr = new T();
			_size = 0;
		};

		Array(const Array& arr) {
			delete _arr;
			_arr = new T[arr.size()];
			for (std::size_t i=0; i<size(); i++)
				_arr[i] = arr[i];
			_size = arr.size();
		};

		Array& operator=(const Array& arr) {
			delete _arr;
			_arr = new T[arr.size()];
			for (std::size_t i=0; i<size(); i++)
				_arr[i] = arr[i];
			_size = arr.size();
			return *this;
		};

		Array(std::size_t n) {
			T* tmp = new T();
			_arr = new T[n];
			for (std::size_t i=0; i<n; i++)
				_arr[i] = *tmp;
			_size = n;
			delete tmp;
		};

		~Array() {
			delete _arr;
		}

		std::size_t size() const {
			return _size;
		};

		T& operator[](std::size_t idx) const {
			if (idx >= _size)
				throw std::out_of_range("OUT OF BOUND");
			return _arr[idx];
		}
};

#endif