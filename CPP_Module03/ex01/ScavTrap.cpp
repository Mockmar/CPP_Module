
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
    _name = "José";
    _hit= 100;
    _energy = 50;
    _attack = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap)
{
	std::cout << "ScavTrap clone constructor called" << std::endl;
	*this = ScavTrap;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ScavTrap)
{
	std::cout << "ScavTrap copy assginment operator called" << std::endl;
	_name = ScavTrap.getName();
	_hit = ScavTrap.getHit();
	_energy = ScavTrap.getEnergy();
	_attack = ScavTrap.getAttack();
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap " << _name << " : Gate keeper mode activated" << std::endl;
}


void	ScavTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "ScavTrap " << _name << " cannot attack because it is dead !" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " cannot attack because it does not have enough energy !" << std::endl;
	else {
		_energy--;
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _attack << " points of damage" << std::endl;
	}
}