#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private:
            Weapon &weaponA;
            std::string name;
    public:
            HumanA(std::string, Weapon &);
            void attack();
};