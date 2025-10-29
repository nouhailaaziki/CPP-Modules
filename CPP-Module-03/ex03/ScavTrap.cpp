#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
    : ClapTrap("Default_ScavTrap")
{
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    this->scavtrap_energy_points = this->energy_points;

    std::cout << "ScavTrap [ " << this->name << " ] constructed (default)!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name_value)
	: ClapTrap(name_value)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
    this->scavtrap_energy_points = this->energy_points;

    std::cout << "ScavTrap [ " << this->name << " ] constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap [ " << this->name << " ] copied!" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap [ " << this->name << " ] assigned!" << std::endl;
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        this->energy_points --;
        std::cout << "ScavTrap [ " << this->name << " ] attacks " << target
        << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else if (this->hit_points <= 0)
        std::cout << "ScavTrap [ " << this->name
        << " ] cannot perform action! Not enough hit points." << std::endl;
    else if (this->energy_points <= 0)
        std::cout << "ScavTrap [ " << this->name
        << " ] cannot perform action! Not enough energy points." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap [ " << this->name << " ] is now in Gate Keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap [ " << this->name << " ] destroyed!" << std::endl;
}
