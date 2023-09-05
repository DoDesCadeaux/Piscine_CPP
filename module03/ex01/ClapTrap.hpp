#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap(const std::string &n, int hp, int ep, int ad);
	ClapTrap(const ClapTrap &other);

	ClapTrap	&operator=(const ClapTrap &other);

	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	int 	getAttackDamage() const;
};

#endif