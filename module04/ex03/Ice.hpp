#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const std::string & type);
	Ice(const Ice & other);

	Ice &operator=(const Ice & other);

	~Ice();

	virtual Ice * clone() const;
	virtual void use(ICharacter & target);
};

#endif