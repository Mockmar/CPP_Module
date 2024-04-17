
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = F._value;
}

Fixed& Fixed::operator=(const Fixed &F)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = F._value;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
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

int	Fixed::toInt(void) const
{
	return (_value >> _fracBits);
}

float	Fixed::toFloat(void) const
{
	return (float)_value / (float)(1 << _fracBits);
}