#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") {}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...";
    std::cout << std::endl;
}
