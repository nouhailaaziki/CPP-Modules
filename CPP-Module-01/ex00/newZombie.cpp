#include "Zombie.hpp"

Zombie*     newZombie(std::string name)
{
    Zombie  *Foo;

    Foo = new Zombie(name);
    return (Foo);
}
