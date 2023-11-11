#include "Array.hpp"
#include <iostream>

int main() {
	// Test du constructeur par défaut
	Array<int> defaultArray;
	std::cout << "Taille du tableau par défaut : " << defaultArray.size() << std::endl;

	// Test du constructeur avec paramètre
	Array<int> paramArray(10);
	std::cout << "Taille du tableau paramétré : " << paramArray.size() << std::endl;

	// Test du constructeur de copie
	Array<int> copyArray = paramArray;
	copyArray[0] = 1; // Modifier le premier élément de la copie
	std::cout << "Premier élément du tableau original : " << paramArray[0] << std::endl;
	std::cout << "Premier élément du tableau copié : " << copyArray[0] << std::endl;

	// Test de l'opérateur d'affectation
	Array<int> assignedArray;
	assignedArray = paramArray;
	assignedArray[0] = 2; // Modifier le premier élément du tableau assigné
	std::cout << "Premier élément du tableau original après assignation : " << paramArray[0] << std::endl;
	std::cout << "Premier élément du tableau assigné : " << assignedArray[0] << std::endl;

	// Test d'accès hors limites
	try {
		std::cout << "Accès à un élément hors limites : " << paramArray[10] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "Exception capturée : " << e.what() << std::endl;
	}

	return 0;
}
