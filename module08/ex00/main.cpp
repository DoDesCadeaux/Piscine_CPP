#include "easyfind.hpp"

int main(void) {
	std::vector<int> vect;

	vect.push_back(5);
	vect.push_back(6);
	vect.push_back(7);
	vect.push_back(8);
	vect.push_back(9);

	std::vector<int>::iterator it = easyfind(vect, 8);
	std::cout << *it << std::endl;
	return 0;
}
