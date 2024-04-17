
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _fracBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fracBits));;
}

Fixed::Fixed(const Fixed &F)
{
	_value = F._value;
}

Fixed& Fixed::operator=(const Fixed &F)
{
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
}

int	Fixed::getRawBits(void) const
{
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
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

/*************operateur*******************/

Fixed	Fixed::operator+(const Fixed &F) const
{
	Fixed result;

	result.setRawBits(_value + F.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &F) const
{
	Fixed result;

	result.setRawBits(_value - F.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &F) const
{
	Fixed result;

	result.setRawBits((_value * F.getRawBits()) >> _fracBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &F) const
{
	Fixed result;

	result.setRawBits((_value << _fracBits) / F.getRawBits());
	return result;
}

/*************comparaison*******************/

bool	Fixed::operator>(const Fixed &F) const
{
	return _value > F.getRawBits();
}

bool	Fixed::operator<(const Fixed &F) const
{
	return _value < F.getRawBits();
}

bool	Fixed::operator>=(const Fixed &F) const
{
	return _value >= F.getRawBits();
}

bool	Fixed::operator<=(const Fixed &F) const
{
	return _value <= F.getRawBits();
}

bool	Fixed::operator==(const Fixed &F) const
{
	return _value == F.getRawBits();
}

bool	Fixed::operator!=(const Fixed &F) const
{
	return _value != F.getRawBits();
}

/*************iterator*******************/

Fixed&	Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	next(*this);

	_value++;
	return next;
}

Fixed&	Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	next(*this);

	_value--;
	return next;
}

/*************min/max*******************/

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}