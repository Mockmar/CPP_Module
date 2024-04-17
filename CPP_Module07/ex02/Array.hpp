
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template<typename T>
class Array
{
    private :
        T 				*_array;
        unsigned int	_size;
    public :
        ~Array() {
			delete[] _array;
		}

        Array() {
			_size = 0;
			_array = new T[0];
		}

		Array(unsigned int n) {
			_size = n;
			_array = new T[n];
		}

		Array(const Array<T> &A) {
			_size = A._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = A._array[i];
		}

		Array& operator=(const Array<T> &A) {
			_size = A._size;
			delete[] _array;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = A._array[i];
			return (*this);
		}

		T& operator[](unsigned int i) {
			if (i >= _size)
				throw std::out_of_range("tu segfault!!");
			else
				return (_array[i]);
		}

		unsigned int size(void) const {
			return (_size);
		}
};

#endif