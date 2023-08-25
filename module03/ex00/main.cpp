#include "ClapTrap.hpp"

int main(void) {

	ClapTrap clap1("CLTP1");
	ClapTrap clap2("CLTP2");

	// Test de la fonction attack
	clap1.attack("CLTP2");
	clap2.takeDamage(clap1.getAttackDamage());  // supposez que getAttackDamage() retourne la valeur d'Attack damage

	// Test de la fonction beRepaired
	clap2.beRepaired(5);

	// Test de l'attaque sans points d'énergie
	for (int i = 0; i < 12; ++i) {
		clap1.attack("CLTP2");
	}

	// Test de la réparation sans points d'énergie
	for (int i = 0; i < 12; ++i) {
		clap2.beRepaired(1);
	}

	// Test de takeDamage pour "tuer" le ClapTrap
	clap2.takeDamage(15);

	// Test de la tentative de réparation après "mort"
	clap2.beRepaired(5);
	return 0;
}