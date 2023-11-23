#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

void fillVector(char **argv, int argc, std::vector<int> &vect);
void fillList(char **argv, int argc, std::list<int> &list);
void triFusionInsertionVect(std::vector<int> &vect);
void fusionVect(const std::vector<int> &left, const std::vector<int> &right, std::vector<int> &vect);
void splitList(const std::list<int> &list, std::list<int> &left, std::list<int> &right);
std::list<int> fusionList(const std::list<int> &left, const std::list<int> &right);
void triFusionInsertionList(std::list<int> &list);

template<typename T>
void displayContainer(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif
