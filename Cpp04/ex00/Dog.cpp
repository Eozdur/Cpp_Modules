#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}
Dog::Dog(const Dog &r)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = r;
}
Dog &Dog::operator=(const Dog &r)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    if (this != &r)
        this->type = r.type;
    return (*this);
}
void Dog::makesound()const
{
    std::cout << "Hav Hav !!!" << std::endl;
}
