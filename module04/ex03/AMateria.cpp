#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _materiaType(type) {
	// std::cout << "AMateria " << this->_materiaType << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	this->_materiaType = other._materiaType;
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        this->_materiaType = other._materiaType;
    }
    return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMAteria destructor called" << std::endl;
}

const std::string &AMateria::getType() const {
	return this->_materiaType;
}

void AMateria::use(ICharacter &target) {
	std::cout << "A default Materia is used against " << target.getName() << std::endl;
}
