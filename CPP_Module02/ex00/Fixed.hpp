
#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &F);
		~Fixed(void);
		Fixed &operator=(const Fixed &F);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_value;
		static const int	_fracBits = 8;
};

#endif