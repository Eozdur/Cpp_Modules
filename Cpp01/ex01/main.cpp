#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = zombieHorde(5,"Emre");
    Zombie *zombie2 = zombieHorde(2,"ASD");
    int i = 0;
    int j = 0;
    while(i<5)
    {
        zombie1[i].announce();
        i++;
    }
    while(j<2)
    {
        zombie2[j].announce();
        j++;
    }
    delete[] (zombie1);
    delete[] (zombie2);
    return 0;
}