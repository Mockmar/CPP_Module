
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Patrick");
	ScavTrap	st1("Jean-Pierre");
	FragTrap	ft1("Bernard");

	ct1.attack("Bernard");
	st1.takeDamage(ct1.getAttack());
	ft1.attack("Patrick");
	ct1.takeDamage(ft1.getAttack());
	ct1.attack("Bernard");
	ct1.beRepaired(50);
	st1.guardGate();
	ft1.highFivesGuys();
	return 0;
}