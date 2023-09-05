#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int valueToSet) : value(valueToSet) {
	std::cout << "Parametric constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(const int raw) {
	this->value = raw;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->value = other.getRawBits();
	}

	return *this;
}
