#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &r)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = r;
}

Animal &Animal::operator=(const Animal &r)
{
    std::cout << "Animal copy assigment operator called" << std::endl;
    if (this != &r)
        this->type = r.type;
    return (*this);
}

std::string Animal::getType()const
{
    return (this->type);
}

void Animal::makesound()const
{
    std::cout << "Animal sound called !!!" << std::endl;
}