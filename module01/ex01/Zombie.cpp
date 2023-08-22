#include "Zombie.hpp"

Zombie::Zombie() {return;}

Zombie::~Zombie() {return;}

void Zombie::announce() const {
	std::cout << this->_name << ": Brainzzzz" << std::endl;

	return;
}

void Zombie::setName(std::string name) {
	if (this->_name.empty())
		this->_name = name;

	return;
}
