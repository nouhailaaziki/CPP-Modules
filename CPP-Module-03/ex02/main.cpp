#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== TESTING CLAPTRAP ===\n" << std::endl;

	ClapTrap a("ALPHA");

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	a.attack("Target Dummy");   // Attack succeeds, consumes 1 energy point

	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	a.takeDamage(5);            // HP decreases from 10 to 5
	a.takeDamage(6);            // HP drops to 0, ClapTrap "dies"
	a.attack("Another Target"); // Cannot attack, HP = 0 → should fail

	std::cout << "\n--- REPAIR TEST ---" << std::endl;
	a.beRepaired(3);            // Cannot repair, HP = 0 → should fail
    
	ClapTrap b("BETTA");
    
	std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
	for (int i = 0; i < 11; ++i)
		b.attack("Target");     // 10 attacks succeed, 11th fails → energy depleted

	std::cout << "\n--- REPAIR ENERGY TEST ---" << std::endl;
	ClapTrap c("GAMMA");
	for (int i = 0; i < 10; ++i)
		c.beRepaired(1);        // 10 repairs succeed, consuming all energy
	c.beRepaired(1);            // Cannot repair → energy = 0

	std::cout << "\n=== END OF CLAPTRAP TESTS ===\n" << std::endl;

	std::cout << "=== TESTING SCAVTRAP ===\n" << std::endl;

	ScavTrap d("DELTA");

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	d.attack("Target Dummy");   // Attack succeeds, consumes 1 energy point

	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	d.takeDamage(5);            // HP decreases from 100 to 95
	d.takeDamage(6);            // HP decreases from 95 to 89 → still alive
	d.attack("Another Target"); // Attack succeeds → still has HP and energy

	std::cout << "\n--- REPAIR TEST ---" << std::endl;
	d.beRepaired(3);            // Repairs succeed, EP decreases by 1
    
	std::cout << "\n--- GUARD GATE TEST ---" << std::endl;
	d.guardGate();                     // ScavTrap enters Gate Keeper mode

	ScavTrap e("OMEGA");
    
	std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
	for (int i = 0; i < 51; ++i)
		e.attack("Target");     // 50 attacks succeed, 51st fails → energy depleted

	std::cout << "\n--- REPAIR ENERGY TEST ---" << std::endl;
	ScavTrap f("SIGMA");
	for (int i = 0; i < 50; ++i)
		f.beRepaired(1);        // 50 repairs succeed, consuming all energy
	f.beRepaired(1);            // Cannot repair → energy = 0

	std::cout << "\n=== END OF SCAVTRAP TESTS ===\n" << std::endl;

	std::cout << "=== TESTING FRAGTRAP ===\n" << std::endl;

	FragTrap g("EPSIL");

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	g.attack("Target Dummy");   // Attack succeeds, consumes 1 energy point

	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	g.takeDamage(5);            // HP decreases from 100 to 95
	g.takeDamage(6);            // HP decreases from 95 to 89
	g.attack("Another Target"); // Attack succeeds → still alive

	std::cout << "\n--- REPAIR TEST ---" << std::endl;
	g.beRepaired(3);            // Repairs succeed, EP decreases by 1
    
	std::cout << "\n--- HIGH FIVES TEST ---" << std::endl;
	g.highFivesGuys();          	   // FragTrap requests a high five

	FragTrap h("THETA");
    
	std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
	for (int i = 0; i < 51; ++i)
		h.attack("Target");     // 50 attacks succeed, 51st fails → energy depleted

	std::cout << "\n--- REPAIR ENERGY TEST ---" << std::endl;
	FragTrap j("KAPPA");
	for (int i = 0; i < 50; ++i)
		j.beRepaired(1);        // 50 repairs succeed, consuming all energy
	j.beRepaired(1);            // Cannot repair → energy = 0

	std::cout << "\n=== END OF FRAGTRAP TESTS ===\n" << std::endl;
	return (0);
}
