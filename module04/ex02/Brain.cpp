#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return this->_ideas[0];
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}