
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "WrongCat constructor called" << std::endl;
    _type = type;
}

WrongCat::WrongCat(const WrongCat &C)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = C;
}

WrongCat& WrongCat::operator=(const WrongCat &C)
{
	std::cout << "WrongCat copy assginment operator called" << std::endl;
    _type = C.getType();
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "* WrongCat sound *" << std::endl;
}