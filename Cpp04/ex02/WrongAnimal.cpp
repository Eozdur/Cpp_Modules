#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "WrongAnimal";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &r)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = r;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &r)
{
    std::cout << "WrongAnimal copy assigment operator called" << std::endl;
    if (this != &r)
        this->type = r.type;
    return (*this);
}
void WrongAnimal::makesound()const
{
    std::cout << "Wrong Animal sound !!!" << std::endl;
}
std::string WrongAnimal::getType()const
{
    return (this->type);
}