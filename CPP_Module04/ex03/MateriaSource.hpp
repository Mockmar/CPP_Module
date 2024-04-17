
#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& materiaSource);
		~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& materiaSource);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(const std::string& type);

		AMateria*	getMateria(int i) const;

	private:
		static const int	NB_MATERIAS = 4;

		AMateria*	_materias[NB_MATERIAS];

};

#endif