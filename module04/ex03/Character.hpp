#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	AMateria*	_inventoryMaterias[4];
	std::string	_name;

public:
	Character(const std::string & name);
	Character(const Character & other);

	Character &operator=(const Character & other);

	~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};

#endif
