
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
    _name = "José";
    _hit= 10;
    _energy = 10;
    _attack = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
	_hit = 10;
	_energy = 10;
	_attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap clone constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap copy assginment operator called" << std::endl;
	_name = claptrap.getName();
	_hit = claptrap.getHit();
	_energy = claptrap.getEnergy();
	_attack = claptrap.getAttack();
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

unsigned int	ClapTrap::getHit(void) const
{
	return _hit;
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return _energy;
}

unsigned int	ClapTrap::getAttack(void) const
{
	return _attack;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " cannot attack because it is dead !" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " cannot attack because it does not have enough energy !" << std::endl;
	else {
		_energy--;
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _attack << " points of damage" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hit)
		_hit = 0;
	else
		_hit -= amount;
	std::cout << "ClapTrap " << _name << " take " << amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy == 0)
		std::cout << "ClapTrap " << _name << " cannot be repaired because it does not have enough energy !" << std::endl;
	else {
		_energy--;
		if (UINT_MAX - _hit < amount)
		{
			_hit = UINT_MAX;
			std::cout << "ClapTrap " << _name << " gain " << UINT_MAX - _hit << " hit points" << std::endl;
		}
		else
		{
			_hit += amount;
			std::cout << "ClapTrap " << _name << " gain " << amount << " hit points" << std::endl;
		}
	}
}