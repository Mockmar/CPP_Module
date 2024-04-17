
#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "Animal default constructor called" << std::endl;
    _type = "Animal";
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    std::cout << "Animal constructor called" << std::endl;
    _type = type;
}

AAnimal::AAnimal(const AAnimal &A)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = A;
}

AAnimal& AAnimal::operator=(const AAnimal &A)
{
	std::cout << "Animal copy assginment operator called" << std::endl;
    _type = A.getType();
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (_type);
}

void    AAnimal::makeSound(void) const
{
    std::cout << "* animal sound *" << std::endl;
}