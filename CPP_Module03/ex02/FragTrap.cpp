
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
    _name = "José";
    _hit= 100;
    _energy = 100;
    _attack = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hit = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(const FragTrap& FragTrap)
{
	std::cout << "FragTrap clone constructor called" << std::endl;
	*this = FragTrap;
}

FragTrap&	FragTrap::operator=(const FragTrap& FragTrap)
{
	std::cout << "FragTrap copy assginment operator called" << std::endl;
	_name = FragTrap.getName();
	_hit = FragTrap.getHit();
	_energy = FragTrap.getEnergy();
	_attack = FragTrap.getAttack();
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "FragTrap " << _name << " cannot attack because it is dead !" << std::endl;
	else if (_energy == 0)
		std::cout << "FragTrap " << _name << " cannot attack because it does not have enough energy !" << std::endl;
	else {
		_energy--;
		std::cout << "FragTrap " << _name << " attack " << target << ", causing " << _attack << " points of damage" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << _name << " ask for a high five" << std::endl;
}