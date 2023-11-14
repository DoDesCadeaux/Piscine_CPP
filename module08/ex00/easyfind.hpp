#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T container, int valueToFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), valueToFind);

	if (it != container.end())
		return it;
	else {
		throw std::runtime_error("Element not found");
	}
}

#endif
