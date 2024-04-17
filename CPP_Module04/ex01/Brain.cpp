
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain clone constructor called" << std::endl ;
	*this = brain;
}

Brain&	Brain::operator=(const Brain& brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i=0; i < MAX_IDEA; i++)
		_ideas[i] = brain._ideas[i];
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	if (i < MAX_IDEA)
		return _ideas[i];
	else
		return NULL;
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < MAX_IDEA && i >= 0)
		_ideas[i] = idea;
	else
		std::cout << "bad index" << std::endl;
}