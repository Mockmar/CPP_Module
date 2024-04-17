
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &newweapon) : _weapon(newweapon)
{
    this->_name = name;
}

HumanA::~HumanA()
{
    
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}