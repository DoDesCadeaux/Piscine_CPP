#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &n, int hp, int ep, int ad) : _name(n), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad) {
	std::cout << "ClapTrap Parametric Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead, cannot attack anymore" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " battery empty, cannot attack anymore. Please recharge" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name <<  " attacks " << target <<", causing " << this->_attackDamage <<  " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead, you're hitting a corpse" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead, can't repair" << std::endl;
		return;
	} else if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy, can't repair" << std::endl;
		return;
	}

	this->_energyPoints--;

	this->_hitPoints += amount;
	if (this->_hitPoints > 10)
		this->_hitPoints = 10;

	std::cout << "ClapTrap " << this->_name << " repaired and now has " << this->_hitPoints << " hit points" << std::endl;
}

int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}
