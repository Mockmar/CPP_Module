
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ct1("Bernard");
	ClapTrap	ct2("Didier");
	ClapTrap	ct3("Patrick");

	ct1.attack("Didier");
	ct2.takeDamage(ct1.getAttack());
	ct1.attack("Patrick");
	ct3.takeDamage(ct1.getAttack());
	ct3.attack("Didier");
	ct2.takeDamage(ct3.getAttack());
	std::cout << "Didier HP : " << ct2.getHit() << std::endl;
	ct2.beRepaired(10);
	std::cout << "Didier HP : " << ct2.getHit() << std::endl;
	return 0;
}