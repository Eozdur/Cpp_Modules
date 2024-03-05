#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() 
{
    std::cout << "AMateria constructor called\n";
    this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria& copy)
{
    this->type = copy.getType();
}


AMateria &AMateria::operator=(const AMateria& copy) {
    this->type = copy.getType();
    return *this;
}

AMateria::~AMateria() 
{
    std::cout << "AMateria destructor called\n";
}

std::string const & AMateria::getType() const 
{
    return (this->type);
}

void AMateria::use(ICharacter& target) 
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
