#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: public Claptrap 
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& r);
        ScavTrap &operator=(const ScavTrap& r);
        void attack(const std::string& target);
        void guardGate();
};
#endif
