#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int	value;
	static const int FRACTIONAL_BITS = 8;

public:
	Fixed();
	Fixed(const int valueToSet);
	Fixed(const float valueToSet);
	Fixed(const Fixed &f);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif