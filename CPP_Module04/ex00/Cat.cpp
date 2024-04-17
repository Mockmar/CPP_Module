
#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor called" << std::endl;
    _type = type;
}

Cat::Cat(const Cat &C)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = C;
}

Cat& Cat::operator=(const Cat &C)
{
	std::cout << "Cat copy assginment operator called" << std::endl;
    _type = C._type;
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "* Cat sound *" << std::endl;
}