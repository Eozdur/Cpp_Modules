#include "Zombie.hpp"
int main()
{
    Zombie zombie1("First Zombie");
    Zombie zombie2("Second zombie");
    zombie1.announce();
    zombie2.announce();
    Zombie *zombie3 = newZombie("Third Zombie");
    zombie3->announce();
    delete zombie3;
    randomChump("Random Zombie");
    return 0;
}