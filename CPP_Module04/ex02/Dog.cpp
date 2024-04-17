
#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog default constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor called" << std::endl;
    _type = type;
}

Dog::Dog(const Dog &D)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _type = D._type;
    _brain = new Brain(*D._brain);
}

Dog& Dog::operator=(const Dog &D)
{
	std::cout << "Dog copy assginment operator called" << std::endl;
    _type = D._type;
    delete _brain;
    _brain = new Brain(*D._brain);
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "* Dog sound *" << std::endl;
}