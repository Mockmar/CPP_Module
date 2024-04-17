
#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &C);
		~Cure(void);
		Cure    &operator=(const Cure &C);

		void		use(ICharacter& target);
		AMateria*	clone(void) const;
};

#endif