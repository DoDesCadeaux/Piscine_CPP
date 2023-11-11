#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
private:
	size_t	_size;
	T*		_array;
public:
	Array() : _size(0), _array(NULL) {}

	Array(unsigned int n) : _size(n) {this->_array = new T[n];}

	Array(const Array &other) {
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; ++i) {
			_array[i] = other._array[i];
		}
	}

	Array & operator=(const Array &other) {
		if (this != &other) {
			delete [] _array;
			_size = other._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; ++i) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	}

	~Array() {if (this->_array != NULL) delete [] this->_array;}

	T & operator[](size_t position) {
		if (position >= this->_size)
			throw std::out_of_range("Index out of bounds");
		return this->_array[position];
	}

	size_t size() const {return this->_size;}
};

#endif
