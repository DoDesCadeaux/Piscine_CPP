#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie* heapZombie = new Zombie(name);

	heapZombie->announce();
	delete(heapZombie);
}
