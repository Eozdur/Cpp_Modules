#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() 
{
    std::cout << "Character default constructor called\n";
}
Character::Character(std::string name)
{
    this->name = name;
    std::cout << "Character " << name << " created\n";
    int i = 0;
    while(i < 4) 
    {
        this->inventory[i] = 0;
        i++;
    }
}

Character::Character(const Character& copy) 
{
    *this = copy;
}

Character &Character::operator=(const Character& copy) 
{
    this->name = copy.getName();
    for (int i = 0; i < 4; i++) 
    {
        if (copy.inventory[i] == 0)
            this->inventory[i] = copy.inventory[i];
        else
            this->inventory[i] = copy.inventory[i]->clone();
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) 
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    std::cout << "Character " << name << " destructed " << std::endl;
}

std::string const &Character::getName() const 
{
    return (this->name);
}

void Character::equip(AMateria *m) 
{
    int i = 0;
    
    if (!m) 
    {
        std::cout << "Tried to equip but Materia is empty\n" << std::endl;
        return ;
    }
    while (this->inventory[i] != 0) 
    {
        i++;
    }
    if (i > 3) {
        std::cout << "There is no enough space for Materia " << std::endl;
        return ;
    }
    std::cout << this->getName() << " equip the " << m->getType() << " at slot " << i << std::endl;
    this->inventory[i] = m;
}

void Character::unequip(int idx) 
{
    if(idx >= 0 && idx < 4) 
    {
        if(this->inventory[idx])
        {
           std::cout << this->getName() << " unequip the " << this->inventory[idx]->getType() << " at slot " << idx << std::endl;
            this->inventory[idx] = 0;
        }
        else
            std::cout << "Inventory is empty at slot " << idx << std::endl;
    }
    else
        std::cout << "Index out of range for unequip" << std::endl;
    
        
}
void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3) 
    {
        std::cout << "Index out of range for use" << std::endl;
        return ;
    }
    if (this->inventory[idx] == NULL) 
    {
        std::cout << "Nothing found the use" << std::endl;
        return ; 
    }
    this->inventory[idx]->use(target);
}
