
#include "Ice.hpp"

Ice::Ice(void)
{
    _type = "ice";
}

Ice::Ice(const Ice &I): AMateria(I)
{
	
}

Ice::~Ice(void)
{

}

Ice &Ice::operator=(const Ice &I)
{
	_type = I.getType();
	return *this;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	return new Ice(*this);
}
