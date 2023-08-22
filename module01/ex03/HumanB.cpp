#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {return;}

HumanB::~HumanB() {return;}

void HumanB::attack() const {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;

	return;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
