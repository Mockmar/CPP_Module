
#include "Zombie.hpp"

int main( void )
{
    Zombie zombi1("Didier");
    zombi1.announce();
    Zombie *zombi2 = newZombie("Patrick");
    zombi2->announce();
    randomChump("Bernard");
    delete (zombi2);
    return 0;
}