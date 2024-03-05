#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class Claptrap
{
    protected:
        std::string name;
        int hitpoint;
        int energypoint;
        int attackdamage;
    public:
        Claptrap();
        Claptrap(std::string name);
        Claptrap(const Claptrap &r);
        Claptrap &operator=(const Claptrap &r);
        ~Claptrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif