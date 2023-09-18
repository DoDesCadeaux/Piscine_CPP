#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;	
}

Cure::Cure(const std::string &type) : AMateria(type) {
	std::cout << "Cure parametric constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	this->_materiaType = other._materiaType;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure *Cure::clone() const {
	Cure *cloned = new Cure(this->_materiaType);

	return cloned;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds" << " *" << std::endl;
}
