#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*(other._brain));
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;
		delete this->_brain;

		this->_brain = new Brain(*(other._brain));
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Miauw" << std::endl;
}

Brain *Cat::getBrain() const {
	return this->_brain;
}