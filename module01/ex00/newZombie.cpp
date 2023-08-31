#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* newZombie = NULL;

	try {
		newZombie = new Zombie(name);
	} catch (const std::bad_alloc& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return NULL;
	}

	return newZombie;
}
