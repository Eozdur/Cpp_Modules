#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &r);
    Animal &operator=(const Animal &r);
    virtual void makesound()const;
    std::string getType()const;
};
#endif