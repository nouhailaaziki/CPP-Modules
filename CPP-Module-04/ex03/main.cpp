#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    // --- BASIC SUBJECT TEST ---
    std::cout << "--- SUBJECT MAIN ---\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    // --- DEEP COPY & ASSIGNMENT TESTS ---
    std::cout << "\n--- DEEP COPY TEST (Copy Constructor) ---\n";
    Character* original = new Character("original");
    original->equip(src->createMateria("ice"));
    
    Character* copy = new Character(*original); // Calls copy constructor
    
    std::cout << "Original uses: ";
    original->use(0, *bob);
    std::cout << "Copy uses:     ";
    copy->use(0, *bob);

    std::cout << "\n--- DEEP COPY TEST (Assignment Operator) ---\n";
    Character* assignee = new Character("assignee");
    assignee->equip(src->createMateria("cure"));
    assignee->equip(src->createMateria("ice"));
    *assignee = *original; // Calls assignment operator

    std::cout << "Assignee (should now have ice): ";
    assignee->use(0, *bob);

    // --- EDGE CASE TESTS ---
    tmp = src->createMateria("unknown_type"); // Should return NULL
    me->equip(tmp); // Should handle NULL gracefully
    
    me->use(10, *bob); // Out of bounds index
    me->use(-1, *bob); // Out of bounds index
    me->unequip(1);    // Unequip slot 1 (Cure)
    me->unequip(2);    // Unequip slot 1 (Cure)
    
    // --- CLEANUP ---
    delete bob;
    delete me;
    delete src;
    delete original;
    delete copy;
    delete assignee;

    return (0);
}
