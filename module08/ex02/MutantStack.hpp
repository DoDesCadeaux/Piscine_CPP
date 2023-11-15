#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}

	MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

	MutantStack & operator=(const MutantStack<T>& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}

};

#endif
