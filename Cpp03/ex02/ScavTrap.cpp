#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = name;
    this->hitpoint = 100;
    this->energypoint = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap Default Constructor called "<< std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    hitpoint = 100;
    energypoint = 50;
    attackdamage = 20;
    std::cout << "ScavTrap" << this->name <<" costructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& r)
{
    std::cout << "ScavTrap copy costructor called"<< std::endl;
    *this = r;
}
ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap " << this->name << " Destructor Called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& r)
{
    if(this == &r)
        return *this;
    this->name = r.name;
    this->hitpoint = r.hitpoint;
    this->energypoint = r.energypoint;
    this->attackdamage = r.attackdamage;
    std::cout << "Scavtrap copy assignment constructor called " << std::endl;
    return *this;
}
void ScavTrap::attack(const std::string& target) 
{
    if (this->hitpoint <= 0)
    {
        std::cout << this->name << "is dead :(" << std::endl; 
        return ;
    }
    if (this->energypoint <= 0) 
    {
        std::cout << "ScavTrap " << this->name << " does not have any energy points" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", with " << this->attackdamage << " points!\n";
    this->energypoint--;
}
void ScavTrap::guardGate()
{
    std::cout << "Scavtrap " << this->name << " is now Gate Keeper Mode" << std::endl;
}