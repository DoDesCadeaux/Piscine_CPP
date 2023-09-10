#include "FragTrap.hpp"

int main(void) {
	FragTrap scav("SVTP");
	FragTrap scav2("SVTP2");

	// Test de la fonction attack
	scav.attack("SVTP2");
	scav2.takeDamage(scav.getAttackDamage());  // supposez que getAttackDamage() retourne la valeur d'Attack damage

	scav2.takeDamage(100);
	// Test de la fonction beRepaired
	scav2.beRepaired(5);

	// Test de l'attaque sans points d'énergie
	for (int i = 0; i < 12; ++i) {
		scav.attack("SVTP2");
	}

	// Test de la réparation sans points d'énergie
	for (int i = 0; i < 12; ++i) {
		scav2.beRepaired(1);
	}

	// Test de takeDamage pour "tuer" le ClapTrap
	scav2.takeDamage(15);

	// Test de la tentative de réparation après "mort"
	scav2.beRepaired(5);
	return 0;
}
