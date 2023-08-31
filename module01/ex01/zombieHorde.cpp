#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* newZombieHorde = NULL;

	try {
		newZombieHorde = new Zombie[N];
	} catch (const std::bad_alloc& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return NULL;
	}

	for (int i = 0; i < N; i++) {
		newZombieHorde[i].setName(name);
	}

	return newZombieHorde;
}


