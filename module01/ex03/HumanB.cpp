#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {return;}

HumanB::~HumanB() {return;}

void HumanB::attack() const {
	if (this->_weapon == NULL) {
		std::cout << this->_name << " doesn't have a weapon" << std::endl;
	} else {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}

	return;
}


void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
