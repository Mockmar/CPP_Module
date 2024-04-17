
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Bernard");
	ClapTrap	ct2("Didier");
	ClapTrap	ct3("Patrick");
	ScavTrap	st1("Jean-Pierre");

	ct1.attack("Didier");
	ct2.takeDamage(ct1.getAttack());
	ct1.attack("Patrick");
	ct3.takeDamage(ct1.getAttack());
	ct3.attack("Didier");
	ct2.takeDamage(ct3.getAttack());
	std::cout << "Didier HP : " << ct2.getHit() << std::endl;
	ct2.beRepaired(50);
	std::cout << "Didier HP : " << ct2.getHit() << std::endl;
	st1.attack("Didier");
	ct2.takeDamage(st1.getAttack());
	std::cout << "Didier HP : " << ct2.getHit() << std::endl;
	st1.guardGate();
	return 0;
}