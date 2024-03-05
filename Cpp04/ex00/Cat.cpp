#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
Cat::Cat(const Cat &r)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = r;
}
Cat &Cat::operator=(const Cat &r)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    if (this != &r)
        this->type = r.type;
    return (*this);
}
void Cat::makesound()const
{
    std::cout << "Meow !!!" << std::endl;
}