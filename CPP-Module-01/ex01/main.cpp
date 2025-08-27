#include "Zombie.hpp"

int main()
{
    Zombie *Horde;
    int     N;

    N = 5;
    Horde = zombieHorde(N, "Horde");
    if (Horde)
    {
        for (int i = 0; i < N; i++)
            Horde[i].announce();
        delete [] Horde;
    }
}
