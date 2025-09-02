#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
: _weapon(weapon), name(name) {}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->_weapon.getType();
    std::cout << std::endl;
}
