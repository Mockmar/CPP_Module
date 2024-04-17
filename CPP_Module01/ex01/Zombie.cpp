
#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout<<this->_name<<" die"<<std::endl;
}

void Zombie::announce(void)
{
    std::cout<<this->_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::named(std::string name)
{
    this->_name = name;
}