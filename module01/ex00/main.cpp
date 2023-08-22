#include "Zombie.hpp"

int main(void) {
	Zombie	bibi("Babour");
	Zombie* baki = newZombie("Kaka");

	bibi.announce();
	baki->announce();
	randomChump("Makaka");
	delete(baki);

	return 0;
}
