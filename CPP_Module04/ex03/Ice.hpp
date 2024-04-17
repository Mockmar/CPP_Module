
#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &I);
		~Ice(void);
		Ice &operator=(const Ice &I);

		void		use(ICharacter &target);
		AMateria*	clone(void) const;
};

#endif