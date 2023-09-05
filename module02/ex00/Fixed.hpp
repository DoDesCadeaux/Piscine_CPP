#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	value;
	static const int FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int valueToSet);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif