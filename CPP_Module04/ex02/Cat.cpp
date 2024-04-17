
#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor called" << std::endl;
    _type = type;
}

Cat::Cat(const Cat &C)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _type = C._type;
    _brain = new Brain(*C._brain);
}

Cat& Cat::operator=(const Cat &C)
{
	std::cout << "Cat copy assginment operator called" << std::endl;
    _type = C._type;
    delete _brain;
    _brain = new Brain(*C._brain);
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "* Cat sound *" << std::endl;
}