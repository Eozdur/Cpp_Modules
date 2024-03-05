#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &r)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = r;
}
WrongCat &WrongCat::operator=(const WrongCat &r)
{
    std::cout << "WrongCat copy assigment operator called" << std::endl;
    if (this != &r)
        this->type = r.type;
    return (*this);
}
void WrongCat::makesound()const
{
    std::cout << "Wrong Meow !!!" << std::endl;
}
std::string WrongCat::getType()const
{
    return (this->type);
}