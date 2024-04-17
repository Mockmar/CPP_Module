
#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
        Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &F);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
        int	    toInt(void) const;
        float	toFloat(void) const;
		Fixed &operator=(const Fixed &F);
		Fixed	operator+(const Fixed &F) const;
		Fixed	operator-(const Fixed &F) const;
		Fixed	operator*(const Fixed &F) const;
		Fixed	operator/(const Fixed &F) const;
		bool	operator>(const Fixed &F) const;
		bool	operator<(const Fixed &F) const;
		bool	operator>=(const Fixed &F) const;
		bool	operator<=(const Fixed &F) const;
		bool	operator==(const Fixed &F) const;
		bool	operator!=(const Fixed &F) const;
		Fixed &operator++(void);
		Fixed	operator++(int);
		Fixed &operator--(void);
		Fixed	operator--(int);
        static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

	private:
		int			        _value;
		static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif