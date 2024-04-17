
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    _type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    _type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &A)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = A;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &A)
{
	std::cout << "WrongAnimal copy assginment operator called" << std::endl;
    _type = A.getType();
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "* WrongAnimal sound *" << std::endl;
}