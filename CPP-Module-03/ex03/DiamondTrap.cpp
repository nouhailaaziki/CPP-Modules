#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_Diamond_clap_name"), ScavTrap(), FragTrap(), name("Default_Diamond")
{
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::scavtrap_energy_points;
    this->attack_damage = FragTrap::attack_damage;

    std::cout << "DiamondTrap [ " << this->name << " ] constructed (default)!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name_value)
    : ClapTrap(name_value + "_clap_name"), ScavTrap(name_value), FragTrap(name_value), name(name_value)
{
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::scavtrap_energy_points;
    this->attack_damage = FragTrap::attack_damage;

    std::cout << "DiamondTrap [ " << this->name << " ] constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;

    std::cout << "DiamondTrap [ " << this->name << " ] copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "DiamondTrap [ " << this->name << " ] assigned!" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap name: " << this->name
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap [ " << this->name << " ] destroyed!" << std::endl;
}
