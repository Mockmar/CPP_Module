
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& F)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = F._value;
}

Fixed& Fixed::operator=(const Fixed& F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = F._value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Member function getRawBits called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "Member function setRawBits called" << std::endl;
	_value = raw;
}