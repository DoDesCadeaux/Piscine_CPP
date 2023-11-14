#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Span {
private:
	std::vector<unsigned int>	_numbers;
	unsigned int				_nMax;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span & other);
	~Span();

	void						addNumber(unsigned int numberToAdd);
	unsigned int				longestSpan(void);
	unsigned int				shortestSpan(void);
	std::vector<unsigned int>	getNumbers(void) const;
	void						displayNumbers(void) const;
	void						fillVectorRandomlySafely(void);

	template<typename It>
	void			addRange(It begin, It end) {
		for (It it = begin; it != end; ++it) {
			if (this->_numbers.size() == this->_nMax) {
				break;
			}
			this->addNumber(*it);
		}
	}
};

#endif
