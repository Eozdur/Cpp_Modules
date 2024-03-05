#include "ClapTrap.hpp"

Claptrap::Claptrap()
{
    name = "Default";
    hitpoint = 10;
    energypoint = 10;
    attackdamage = 0;
    std::cout << "Claptrap Default constructor called" << std::endl;
}
Claptrap::Claptrap(std::string name)
{
    this->name = name;
    hitpoint = 10;
    energypoint = 10;
    attackdamage = 0;
    std::cout << "Claptrap" << this->name << "constructor called" << std::endl;
}
Claptrap::Claptrap(const Claptrap& r)
{
    std::cout << "Claptrap" << "Copy constructor called" << std::endl;
    *this = r;
}
Claptrap::~Claptrap()
{
    std::cout << "Scavtrap " << this->name << " Destructor Called" << std::endl;
}
Claptrap &Claptrap::operator=(const Claptrap& r)
{
    if(this == &r)
        return *this;
    this->name = r.name;
    this->hitpoint = r.hitpoint;
    this->energypoint = r.energypoint;
    this->attackdamage = r.attackdamage;
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
}
void Claptrap::attack(const std::string& target) 
{
    if (this->hitpoint <= 0)
    {
        std::cout << this->name << "is dead :(" << std::endl; 
        return ;
    }
    if (this->energypoint <= 0) 
    {
        std::cout << "ClapTrap " << this->name << " does not have any energy points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", with " << this->attackdamage << " points!\n";
    this->energypoint--;
}
void Claptrap::takeDamage(unsigned int amount) {
    if(this->hitpoint <= 0)
    {
        std::cout << this->name << "Already dead :(" << std::endl;
        return;
    }
    if((int)amount > 0)
    {
        std::cout << this->name << " Take " <<(int)amount << " damage " << std::endl;
        this->hitpoint -= (int)amount;
    }
    if(this->hitpoint <= 0)
        std::cout << this->name << "left from this world " << std::endl;
}
void Claptrap::beRepaired(unsigned int amount) {
    if (this->hitpoint <= 0)
    {
        std::cout << this->name << " cant repaired itself" << std::endl;
        return ;
    }
    if (this->energypoint <= 0) 
    {
        std::cout << "ClapTrap " << this->name << "does not have any energy points to repair itself\n";
        return ;
    }
    std::cout << "ClapTrap " << this->name << " has repaired " << amount << " point of itself\n";
    this->energypoint--;
    this->hitpoint += amount;
}