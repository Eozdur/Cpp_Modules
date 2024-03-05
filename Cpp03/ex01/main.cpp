#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    Claptrap c;
    Claptrap a(" Emre ");
    Claptrap b(" Ismaıl ");

    int i = 0;

    ScavTrap f;
    ScavTrap g("Timur");

    b.takeDamage(31);
    b.beRepaired(10);

    c.attack("Caner");
    c.attack("Caner");
    c.takeDamage(50);
    c.beRepaired(10);
    a.beRepaired(10);
    a.beRepaired(31);

    while(i < 10)
    {
        a.attack("III.Vlad");
        i++;
    }
    std::cout << std::endl;
    g.attack("Emre");
    f.attack("emre");
    g.takeDamage(50);
    g.beRepaired(10);
    g.beRepaired(10);
    g.beRepaired(31);

    i = 0;
    while(i < 54)
    {
        g.attack("Bayezid");
        i++;
    }

    g.takeDamage(55);
    g.takeDamage(50);
    g.beRepaired(10);
    g.guardGate();
}