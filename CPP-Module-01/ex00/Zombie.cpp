#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string _name) : name(_name) {}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...";
    std::cout << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed!" << std::endl;
}
