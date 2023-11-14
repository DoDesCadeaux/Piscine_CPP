#include "Span.hpp"

Span::Span(unsigned int N) : _nMax(N) {}

Span::Span(const Span &other) : _numbers(other._numbers), _nMax(other._nMax) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_nMax = other._nMax;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(unsigned int numberToAdd) {
	if (this->_numbers.size() == this->_nMax)
		throw std::range_error("Maximum numbers allocated");
	this->_numbers.push_back(numberToAdd);
}

unsigned int Span::longestSpan() {
	if (this->_numbers.size() == 1 || this->_numbers.empty())
		throw std::range_error("Need at least 2 values for shortest Span");

	std::sort(this->_numbers.begin(), this->_numbers.end());

	unsigned int longestSpan = this->_numbers.back() - this->_numbers.front();

	return longestSpan;
}

unsigned int Span::shortestSpan() {
	if (this->_numbers.size() == 1 || this->_numbers.empty())
		throw std::range_error("Need at least 2 values for shortest Span");

	unsigned int shortestSpan = INT_MAX;

	std::sort(this->_numbers.begin(), this->_numbers.end());

	for (size_t i = 0; i < this->_numbers.size() - 1; ++i) {
		if (this->_numbers[i] && ((this->_numbers[i + 1] - this->_numbers[i]) < shortestSpan))
			shortestSpan = this->_numbers[i + 1] - this->_numbers[i];
	}

	return shortestSpan;
}

std::vector<unsigned int> Span::getNumbers() const {
	if (this->_numbers.empty())
		throw std::range_error("Vector is empty");
	return this->_numbers;
}

void Span::displayNumbers() const {
	if (this->_numbers.empty())
		throw std::range_error("Vector is empty");
	for (size_t i = 0; i < this->_numbers.size(); ++i) {
		std::cout << this->_numbers[i] << " ";
	}
	std::cout << std::endl;
}

void Span::fillVectorRandomlySafely() {
	unsigned int random_variable = std::rand();

	for (size_t i = 0; i < this->_nMax; ++i) {
		this->_numbers.push_back(random_variable);
		random_variable = std::rand();
	}
}
