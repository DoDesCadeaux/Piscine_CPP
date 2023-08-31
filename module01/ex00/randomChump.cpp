#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie* heapZombie = NULL;

	try {
		heapZombie = new Zombie(name);
	} catch (const std::bad_alloc& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}

	heapZombie->announce();
	delete heapZombie;
}
