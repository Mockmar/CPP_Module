
#include "Cure.hpp"

Cure::Cure(void)
{
    _type = "cure";
}

Cure::Cure(const Cure &C): AMateria(C)
{

}

Cure::~Cure(void)
{

}

Cure    &Cure::operator=(const Cure &C)
{
	_type = C.getType();
	return *this;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return new Cure(*this);
}