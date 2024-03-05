#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cerr << "Error: memory could not be allocated" << std::endl;
        exit(1);
    }
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}
Dog::Dog(const Dog &r)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    if(this->brain == NULL)
    {
        std::cerr << "Error: memory could not be allocated" << std::endl;
        exit(1);
    }
    *this = r;
}
Dog &Dog::operator=(const Dog &r)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    //this->brain = r.getbrain(); bu şekilde bir kopyalama sığ kopyalama olur
    // ya da ben bu yapıcıları tanımlamasamda derleyici bunları otomatik olarak tanımlar
    // bu durumda derleyici tarafından tanımlanan kopyalama işleminde sığ kopyalama olur
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
void Dog::makesound()const
{
    std::cout << "Hav Hav !!!" << std::endl;
}
Brain *Dog::getbrain()const
{
    return (this->brain);
}
