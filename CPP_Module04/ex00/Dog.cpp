
#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor called" << std::endl;
    _type = type;
}

Dog::Dog(const Dog &D)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = D;
}

Dog& Dog::operator=(const Dog &D)
{
	std::cout << "Dog copy assginment operator called" << std::endl;
    _type = D._type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "* Dog sound *" << std::endl;
}