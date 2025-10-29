#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
    : ClapTrap("Default_FragTrap")
{
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;

    std::cout << "FragTrap [ " << this->name << " ] constructed (default)!" << std::endl;
}

FragTrap::FragTrap(const std::string& name_value)
	: ClapTrap(name_value)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;

    std::cout << "FragTrap [ " << this->name << " ] constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap [ " << this->name << " ] copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap [ " << this->name << " ] assigned!" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap [ " << this->name << " ] requests a high five!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap [ " << this->name << " ] destroyed!" << std::endl;
}
