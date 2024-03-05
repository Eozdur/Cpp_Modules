#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() 
{
    std::cout << "MateriaSource constructer called" << std::endl;
    int i = 0;
    while(i < 4)
    {
        this->inventory[i] = 0;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy) 
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& copy) 
{
    int i = 0;
    if(this != &copy)
    {
        while(i<4)
        {
            if(this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = copy.inventory[i]->clone();
            i++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() 
{
    int i = 0;
    while(i < 4)
    {
        if(this->inventory[i])
            delete this->inventory[i];
        i++;
    }
    std::cout << "MateriaSource destructed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    int i = 0;
    
    if (!m) 
    {
        std::cout << "Materia is empty" << std::endl;
        return ;
    }
    while (this->inventory[i] != 0) 
    {
        i++;
    }
    if (i > 3)
    {
        std::cout << "There is no enough space for learn Materia" << std::endl;
        return ;
    }
    this->inventory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
    int i = 0;
    while(i < 4)
    {
        if (this->inventory[i]->getType() == type)
        {
            std::cout << "Materia " << type << " created" << std::endl;
            return (this->inventory[i]->clone());
        }
        i++;
    }
    std::cout << "Materia " << type << " not found" << std::endl;
    return NULL;
}
