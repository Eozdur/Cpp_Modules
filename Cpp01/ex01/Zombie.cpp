#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " Has been destroyed" << std::endl;
}

void Zombie::setname(std::string name)
{
    this->name = name;
}