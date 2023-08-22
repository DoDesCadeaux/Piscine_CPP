#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {return;}
Weapon::~Weapon() {return;}

const std::string &Weapon::getType() const {
	return this->_type;
}

void Weapon::setType(const std::string &newType) {
	this->_type = newType;

	return;
}
