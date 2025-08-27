#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *Horde;

    if (N <= 0)
    {
        std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
        return (NULL);
    }
    Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        Horde[i].setName(name);
    return (Horde);
}
