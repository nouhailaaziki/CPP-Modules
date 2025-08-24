#include "Zombie.hpp"

int main()
{
    Zombie* Foo;

    randomChump("Bar");
    Foo = newZombie("Foo");
    Foo->announce();
    delete Foo;
}
