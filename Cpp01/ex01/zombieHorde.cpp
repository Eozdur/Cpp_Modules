#include "Zombie.hpp"

Zombie *zombieHorde(int N,std::string name)
{
    Zombie *zhorde = new Zombie[N];
    int i = 0;
    while(i<N)
    {
        zhorde[i].setname(name); 
        i++;
    }
    return zhorde;
}