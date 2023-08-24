#include "Fixed.hpp"
#include <iostream>
#include <cassert>

int main() {
	// 1. Test des constructeurs et de la conversion en float/int
	Fixed a(5);
	std::cout << "Fixed a (from int): " << a << std::endl;

	Fixed b(5.5f);
	std::cout << "Fixed b (from float): " << b << std::endl;


	Fixed c = a + b;
	std::cout << "c = a + b: " << c << std::endl;

	Fixed d = a - b;
	std::cout << "d = a - b: " << d << std::endl;


	++a;
	std::cout << "After pre-increment, a: " << a << std::endl;

	Fixed e = a++;
	std::cout << "After post-increment, a: " << a << " and e: " << e << std::endl;

	if (a < b) std::cout << "a is less than b" << std::endl;
	else std::cout << "a is not less than b" << std::endl;

	return 0;
}
