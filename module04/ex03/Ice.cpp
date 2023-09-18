#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type) {
	std::cout << "Ice parametric constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	this->_materiaType = other._materiaType;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice *Ice::clone() const {
	Ice *cloned = new Ice(this->_materiaType);

	return cloned;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
