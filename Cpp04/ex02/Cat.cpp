#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cerr << "Error: memory could not be allocated" << std::endl;
        exit(1);
    }
}
Cat::~Cat()
{   
    
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
    
}
Cat::Cat(const Cat &r)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cerr << "Error: memory could not be allocated" << std::endl;
        exit(1);
    }
    *this = r;
}
Cat &Cat::operator=(const Cat &r)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    if(this != &r)
    {
        if(this->brain)
            delete this->brain;
        this->brain = new Brain(*r.brain);
        if(this->brain == NULL)
        {
            std::cerr << "Error: memory could not be allocated" << std::endl;
            exit(1);
        }
    }
    return (*this);
}
void Cat::makesound()const
{
    std::cout << "Meow !!!" << std::endl;
}

Brain *Cat::getbrain()const
{
    return (this->brain);
}