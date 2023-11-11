#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, size_t arrLen, void (*func)(T)) {
	size_t i = 0;
	while (i < arrLen) {
		func(array[i]);
		i++;
	}
}

#endif
