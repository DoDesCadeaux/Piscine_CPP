#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &n) : _name(n), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Parametric Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;

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
		std::cout << "ClapTrap" << this->_name << " is dead, cannot attack anymore" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap" << this->_name << " battery empty, cannot attack anymore. Please recharge" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name <<  " attacks " << target <<", causing " << this->_attackDamage <<  " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << " is dead, you're hitting a corpse" << std::cout;
		return;
	}
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << " lost " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead, can't repair" << std::endl;
		return;
	} else if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " have 0 energy" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " hit points" << std::endl;
}

int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}
