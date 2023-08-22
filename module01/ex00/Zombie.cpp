#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {return;}

Zombie::~Zombie() {
	std::cout << this->_name << " destructor called" << std::endl;

	return;
}

void Zombie::announce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
