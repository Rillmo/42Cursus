#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {
	private:
		T* _arr;
		unsigned int size;
	public:
		Array() {
			_arr = new T();
			_size = 0;
		};

		Array(const Array& arr) {
			for (int i=0; i<size(); i++)
				_arr[i] = arr[i];
		};

		Array& operator=(const Array& arr) {
			for (int i=0; i<size(); i++)
				_arr[i] = arr[i];
			return *this;
		};

		Array(unsigned int n) {
			_arr = new T[n];
			_size = n;
		};

		unsigned int size() const {
			return _size;
		}
};

#endif