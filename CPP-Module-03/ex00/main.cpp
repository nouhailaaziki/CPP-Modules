#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== TESTING CLAPTRAP ===\n" << std::endl;

    ClapTrap a("ALPHA");

    std::cout << "\n--- ATTACK TEST ---" << std::endl;
    a.attack("Target Dummy");   // Successful attack

    std::cout << "\n--- DAMAGE TEST ---" << std::endl;
    a.takeDamage(5);            // Reduce some HP
    a.takeDamage(6);            // Reduce more than current HP (HP should become 0)
    a.attack("Another Target"); // Try to attack after death (should fail)

    std::cout << "\n--- REPAIR TEST ---" << std::endl;
    a.beRepaired(3);            // Try to repair after death (should fail)
    
    ClapTrap b("BETTA");
    
    std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
    for (int i = 0; i < 11; ++i)
        b.attack("Target");     // Each attack costs 1 energy, 11th attack should fail

    std::cout << "\n--- REPAIR ENERGY TEST ---" << std::endl;
    ClapTrap c("GAMMA");
    for (int i = 0; i < 10; ++i)
        c.beRepaired(1);        // Repair itself until energy runs out
    c.beRepaired(1);            // Try to repair without energy (should fail)

    std::cout << "\n=== END OF TESTS ===\n" << std::endl;
    return (0);
}
