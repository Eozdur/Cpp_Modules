#include "Weapon.hpp"
#include "HumanA.hpp"

void HumanA::attack(){
    std::cout << this->name <<  " attacks with their " << this->weaponA.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : weaponA(weapon){
    this->name = name;
}


