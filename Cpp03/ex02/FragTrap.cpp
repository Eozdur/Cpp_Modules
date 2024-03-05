#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
    this->name = name;
    this->hitpoint = 100;
    this->energypoint = 50;
    this->attackdamage = 20;
    std::cout << "Fragtrap Default Constructor called "<< std::endl;
}
FragTrap::FragTrap(std::string name)
{
    this->name = name;
    hitpoint = 100;
    energypoint = 50;
    attackdamage = 20;
    std::cout << "FragTrap " << this->name <<" costructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& r)
{
    std::cout << "FragTrap copy costructor called"<< std::endl;
    *this = r;
}
FragTrap::~FragTrap()
{
    std::cout << "Fragtrap " << this->name << " Destructor Called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& r)
{
    if(this == &r)
        return *this;
    this->name = r.name;
    this->hitpoint = r.hitpoint;
    this->energypoint = r.energypoint;
    this->attackdamage = r.attackdamage;
    std::cout << "Fragtrap copy assignment constructor called " << std::endl;
    return *this;
}
void FragTrap::attack(const std::string& target) 
{
    if (this->hitpoint <= 0)
    {
        std::cout << this->name << "is dead :(" << std::endl; 
        return ;
    }
    if (this->energypoint <= 0) 
    {
        std::cout << "f " << this->name << " does not have any energy points" << std::endl;
        return ;
    }
    std::cout << "Fragtrap " << this->name << " attacks " << target << ", with " << this->attackdamage << " points!\n";
    this->energypoint--;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << this->name << " a positive high fives request " << std::endl;
}
