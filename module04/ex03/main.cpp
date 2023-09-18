#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // Test: Equip with valid materias
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Test: Use the materias
    me->use(0, *bob);
    me->use(1, *bob);

    // Test: Unequip a materia
    me->unequip(0);
    me->use(0, *bob);  // Should not work as it's unequipped

    // Test: Equip more materias than the inventory can handle
    for (int i = 0; i < 5; ++i) {
        tmp = src->createMateria("ice");
        me->equip(tmp);
    }

    // Test: Create an unknown materia
    tmp = src->createMateria("fire");
    if (!tmp) {
        std::cout << "Unknown materia type!" << std::endl;
    }

    // Test: Equip and unequip multiple times
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(2, *bob);
    me->unequip(2);
    me->use(2, *bob);  // Should not work as it's unequipped
    me->use(1, *bob);

    // Test: Deep copy of character
    ICharacter* clone = new Character(*static_cast<Character*>(me));
    clone->use(1, *bob);

    delete clone;
    delete bob;
    delete me;
    delete src;

    return 0;
}
