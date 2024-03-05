#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public Claptrap
{
    public:
        FragTrap();
        FragTrap(std::string);
        FragTrap(const FragTrap&);
        FragTrap& operator=(const FragTrap&);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};
#endif