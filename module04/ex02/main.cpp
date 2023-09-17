#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
//	Animal shouldNotWork;
	Animal** zoo = new Animal * [10];

	Cat ogRory;

	ogRory.getBrain()->setIdea(0, "I want to eat !");
	ogRory.getBrain()->setIdea(1, "I should sleep !");

	std::cout << "RORY IDEA 0 HERE ----> " << ogRory.getBrain()->getIdea(0) << std::endl;
	std::cout << "RORY IDEA 1 HERE ----> " << ogRory.getBrain()->getIdea(1) << std::endl;

	Cat copiedRory(ogRory);

	copiedRory.getBrain()->setIdea(0, "Zoomies time !");

	std::cout << "RORY IDEA 0 HERE ----> " << ogRory.getBrain()->getIdea(0) << std::endl;
	std::cout << "DEEP COPY RORY IDEA 0 HERE ----> " << copiedRory.getBrain()->getIdea(0) << std::endl;

	for (int i = 0; i < 5; i++) {
		zoo[i] = new Dog();
	}

	for (int i = 5; i < 10; i++) {
		zoo[i] = new Cat();
	}


	for (int i = 0; i < 10; i++) {
		zoo[i]->makeSound();
	}

	for (int i = 0; i < 10; i++) {
		delete zoo[i];
	}

	delete [] zoo;
	return 0;
}
