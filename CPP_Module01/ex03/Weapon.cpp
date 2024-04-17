
# include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType(void)
{
    const std::string &type = this->_type;

    return (type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
