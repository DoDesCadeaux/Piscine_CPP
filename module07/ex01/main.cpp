#include "iter.hpp"

template<typename T>
void printElements(T arrElement) {std::cout << arrElement << std::endl;}

int main(void) {
	int arrInt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	std::string arrString[] = {"Bonjour", "Salut", "Yo", "Wesh", "Ciao"};

	iter(arrInt, 10, printElements);
	iter(arrString, 5, printElements);

}