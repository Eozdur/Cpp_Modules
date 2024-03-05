#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    int i = 0;
    while(i < 100)
    {
        this->ideas[i] = "default";
        i++;
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &r)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = r;
}
Brain &Brain::operator=(const Brain &r)
{
    std::cout << "Brain Operator Assignment Called ! " << std::endl;
    int i = 0;
    if(this != &r)
    {
        while (i < 100)
        {
            this->ideas[i] = r.ideas[i];
            i++;
        }
    }
    return (*this);
}
std::string &Brain::getideas(int i)
{
    return (this->ideas[i]);
}
void Brain::setideas(std::string idea,int i)
{
    this->ideas[i] = idea;
}
