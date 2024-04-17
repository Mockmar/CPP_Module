
#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default constructor called" << std::endl;
    _type = "Animal";
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "Animal constructor called" << std::endl;
    _type = type;
}

Animal::Animal(const Animal &A)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = A;
}

Animal& Animal::operator=(const Animal &A)
{
	std::cout << "Animal copy assginment operator called" << std::endl;
    _type = A.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (_type);
}

void    Animal::makeSound(void) const
{
    std::cout << "* animal sound *" << std::endl;
}