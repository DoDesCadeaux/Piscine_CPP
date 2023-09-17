#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {
	std::cout << "Animal parametric constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = other._type;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << this->_type << " makes a weird sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}
