#include "Character.hpp"

Character::Character() : name("unknown"), size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    garbageCollector = NULL;
}

Character::Character(const std::string& name)
    : name(name), size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    garbageCollector = NULL;
}

Character::Character(const Character& other)
    : name(other.name), size(0), garbageCollector(NULL)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
        for (int i = 0; i < size; i++)
            delete garbageCollector[i];
        delete[] garbageCollector;
        size = 0;
        garbageCollector = NULL;
        for (int i = 0; i < 4; i++)
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
    }
    return *this;
}

std::string const& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{        
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == m)
            return ;
        if (!inventory[i])
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        size++;
        AMateria**  tmp = garbageCollector;
        garbageCollector = new AMateria*[size];
        for (int i = 0; i < size - 1; i++)
            garbageCollector[i] = tmp[i];
        garbageCollector[size - 1] = inventory[idx];
        delete[] tmp;
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    for (int i = 0; i < size; i++)
        delete garbageCollector[i];
    delete[] garbageCollector;
}
