#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)  {
	std::cout << "ScavTrap Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
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

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead, you're hitting a corpse" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "ScavTrap " << this->_name << " lost " << amount << " hit points" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " is dead, can't repair" << std::endl;
		return;
	} else if (this->_energyPoints <= 0) {
		std::cout << "ScavTrap " << this->_name << " have 0 energy" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	std::cout << "ScavTrap " << this->_name << " repaired " << amount << " hit points" << std::endl;
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is on gate keeper mode" << std::endl;
}


scavCopy = ScavTrap(other)