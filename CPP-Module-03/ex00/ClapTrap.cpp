#include "ClapTrap.hpp"
#include <iostream>
        
ClapTrap::ClapTrap()
    : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap [ " << this->name << " ] constructed (default)!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name_value)
    : name(name_value), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap [ " << this->name << " ] constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hit_points(other.hit_points),
      energy_points(other.energy_points), attack_damage(other.attack_damage)
{
    std::cout << "ClapTrap [ " << this->name << " ] copied!" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    std::cout << "ClapTrap [ " << this->name << " ] assigned!" << std::endl;
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        this->energy_points --;
        std::cout << "ClapTrap [ " << this->name << " ] attacks " << target
        << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
    else if (this->hit_points <= 0)
        std::cout << "ClapTrap [ " << this->name
        << " ] cannot perform action! Not enough hit points." << std::endl;
    else if (this->energy_points <= 0)
        std::cout << "ClapTrap [ " << this->name
        << " ] cannot perform action! Not enough energy points." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        if (amount >= this->hit_points)
            this->hit_points = 0;
        else
            this->hit_points -= amount;
        std::cout << "ClapTrap [ " << this->name << " ] takes " << amount 
        << " points of damage! Remaining HP: " << this->hit_points << std::endl;
    }
    else
        std::cout << "ClapTrap [ " << this->name
        << " ] is already destroyed!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        this->hit_points += amount;
        this->energy_points --;
        std::cout << "ClapTrap [ " << this->name
        << " ] repairs itself, recovering " << amount << " hit points! Current HP: "
        << this->hit_points << std::endl;
    }
    else if (this->hit_points <= 0)
        std::cout << "ClapTrap [ " << this->name
        << " ] has no hit points left and cannot be repaired!" << std::endl;
    else if (this->energy_points <= 0)
        std::cout << "ClapTrap [ " << this->name
        << " ] has no energy points left and cannot be repaired!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap [ " << this->name << " ] destroyed!" << std::endl;
}
