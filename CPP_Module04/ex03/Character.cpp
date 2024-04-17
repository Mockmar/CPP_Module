
#include "Character.hpp"

Character::Character(void)
{
	_name = "Didier";
	for (int i=0; i < NB_ITEMS; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	_name = name;
	for (int i=0; i < NB_ITEMS; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& character)
{
	int	i;

	i = 0;
	_name = character.getName();
	while (i < NB_ITEMS) 
	{
		if (character.getItem(i))
			_inventory[i] = character.getItem(i)->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
}

Character&	Character::operator=(const Character& character)
{
	int	i;

	i = 0;
	_name = character.getName();
	while (i < NB_ITEMS) 
	{
		if (_inventory[i])
			delete _inventory[i];
		if (character.getItem(i))
			_inventory[i] = character.getItem(i)->clone();
		else
			_inventory[i] = NULL;
		i++;
	}
	return *this;
}

Character::~Character(void)
{
	for (int i=0; i < NB_ITEMS; i++) 
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void	Character::equip(AMateria* m)
{
	for (int i=0; i < NB_ITEMS; i++) 
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < NB_ITEMS)
	{
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < NB_ITEMS && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

const std::string&	Character::getName() const
{
	return _name;
}

AMateria*	Character::getItem(int idx) const
{
	if (idx < 0 || idx >= NB_ITEMS)
		return NULL;
	return _inventory[idx];
}