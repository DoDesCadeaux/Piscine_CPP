#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const std::string & type);
	Cure(const Cure & other);

	Cure &operator=(const Cure & other);

	~Cure();

	virtual Cure * clone() const;
	virtual void use(ICharacter & target);
};

#endif