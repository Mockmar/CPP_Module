

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
		Fixed &operator=(const Fixed &F);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
        int	    toInt(void) const;
        float	toFloat(void) const;

	private:
		int			        _value;
		static const int	_fracBits = 8;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif