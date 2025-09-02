#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

void Weapon::setType(std::string new_value)
{
    this->type = new_value;
}

const std::string& Weapon::getType(void) const
{
    return (this->type);
}

