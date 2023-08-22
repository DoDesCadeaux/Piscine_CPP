#include "Zombie.hpp"

int main(void) {
	Zombie *horde;
	static const int HORDE_SIZE = 10;

	horde = zombieHorde(HORDE_SIZE, "François");

	for (unsigned long i = 0; i < HORDE_SIZE; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
