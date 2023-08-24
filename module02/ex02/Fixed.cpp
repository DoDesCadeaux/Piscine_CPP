#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int valueToSet) {
	this->value = valueToSet << this->FRACTIONAL_BITS;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float valueToSet) {
	int	rounded;

	rounded = roundf(valueToSet * std::pow(2, this->FRACTIONAL_BITS));
	this->value = rounded;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->value = other.getRawBits();
	}

	return *this;
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->value > other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
	return (this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	this->value++;

	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;

	++*this;

	return temp;
}

Fixed &Fixed::operator--() {
	this->value--;

	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;

	--*this;

	return temp;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	return (first < second) ? first : second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
	return (first < second) ? first : second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	return (first > second) ? first : second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
	return (first > second) ? first : second;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->value) / (1 << 8);
}

int Fixed::toInt() const {
	return this->value >> 8;
}

int Fixed::getRawBits() const {
	return this->value;
}

void Fixed::setRawBits(const int raw) {
	this->value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();

	return out;
}
