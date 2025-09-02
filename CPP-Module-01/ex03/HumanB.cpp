#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->_weapon = NULL;
}

void    HumanB::attack(void)
{
    if (_weapon) {
        std::cout << this->name << " attacks with their ";
        std::cout << this->_weapon->getType();
        std::cout << std::endl;
    }
    else
        std::cout << name << " has no weapon!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
