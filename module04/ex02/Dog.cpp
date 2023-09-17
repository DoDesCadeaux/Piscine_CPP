#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*(other._brain));
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*(other._brain));
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
