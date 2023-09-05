#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << this->_name << " default constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap" << this->_name << " is dead, cannot attack anymore" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << "ScavTrap" << this->_name << " battery empty, cannot attack anymore. Please recharge" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name <<  " attacks " << target <<", causing " << this->_attackDamage <<  " points of damage!" << std::endl;

}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is on gate keeper mode" << std::endl;
}
