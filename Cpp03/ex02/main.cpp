#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){

    FragTrap a("Donkey");
    FragTrap b("Cow");

    a.highFivesGuys();
    b.highFivesGuys();

    a.attack("Dog");
    a.takeDamage(100);
    a.beRepaired(20);
    a.highFivesGuys();
}