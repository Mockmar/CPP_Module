
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i=0; i < NB_MATERIAS; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{	
	*this = materiaSource;
}

MateriaSource::~MateriaSource(void)
{
	for (int i=0; i < NB_MATERIAS; i++)
	{
		if (_materias[i])
			delete _materias[i];
		_materias[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	for (int i=0; i < NB_MATERIAS; i++)
		_materias[i] = materiaSource.getMateria(i)->clone();
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i=0; i < NB_MATERIAS; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = materia;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i=0; i < NB_MATERIAS; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}

AMateria*	MateriaSource::getMateria(int i) const
{
	if (i < 0 || i >= NB_MATERIAS)
		return NULL;
	return _materias[i];
}