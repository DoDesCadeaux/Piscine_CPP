#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Bad argument" << std::endl;
		exit(1);
	}

	std::vector<int> vect;
	std::list<int> list;

	fillVector(argv, argc, vect);
	fillList(argv, argc, list);

	std::cout << "Before : " << std::endl;
	displayContainer(vect);

	clock_t tempsDebutVect = clock();
	triFusionInsertionVect(vect);
	clock_t tempsFinVect = clock();
	std::cout << "After : " << std::endl;
	displayContainer(vect);
	double tempsEcouleVect = double(tempsFinVect - tempsDebutVect) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vect.size() << " elements with std::[vector] : "
			  << tempsEcouleVect * 1e6 << " us" << std::endl;

	clock_t tempsDebutList = clock();
	triFusionInsertionList(list);
	clock_t tempsFinList = clock();
	double tempsEcouleList = double(tempsFinList - tempsDebutList) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << list.size() << " elements with std::[list] : "
			  << tempsEcouleList * 1e6 << " us" << std::endl;
	return 0;
}