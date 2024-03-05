#include "Weapon.hpp"

class HumanB{
    private:
            Weapon *weaponB;
            std::string name;
    public:
            HumanB(std::string);
            void attack();
            void setWeapon(Weapon &);
};