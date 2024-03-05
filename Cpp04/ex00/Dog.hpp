#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &r);
        Dog &operator=(const Dog &r);
        void makesound()const;
};
#endif