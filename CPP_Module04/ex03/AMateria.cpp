
#include "AMateria.hpp"

AMateria::AMateria(void)
{
    _type = "undefinied";
}

AMateria::~AMateria(void)
{

}
AMateria::AMateria(std::string const &type)
{
    _type = type;
}

AMateria::AMateria(AMateria const &M)
{
	*this = M;
}

AMateria &AMateria::operator=(AMateria const &M)
{
	_type = M._type;
	return *this;
}




std::string const &AMateria::getType(void) const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* do nothing to " << target.getName() << " *" << std::endl;
}