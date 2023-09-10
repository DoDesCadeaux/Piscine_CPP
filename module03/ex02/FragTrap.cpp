#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)  {
	std::cout << "FragTrap Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0) {
		std::cout << "FragTrap" << this->_name << " is dead, cannot attack anymore" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << "FragTrap" << this->_name << " battery empty, cannot attack anymore. Please recharge" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name <<  " attacks " << target <<", causing " << this->_attackDamage <<  " points of damage!" << std::endl;

}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead, you're hitting a corpse" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "FragTrap " << this->_name << " lost " << amount << " hit points" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "FragTrap " << this->_name << " is dead, can't repair" << std::endl;
		return;
	} else if (this->_energyPoints <= 0) {
		std::cout << "FragTrap " << this->_name << " have 0 energy" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	std::cout << "FragTrap " << this->_name << " repaired " << amount << " hit points" << std::endl;
}

void FragTrap::highFiveGuys() {
	std::cout << this->_name << " wants a high five!" << std::endl;
}
