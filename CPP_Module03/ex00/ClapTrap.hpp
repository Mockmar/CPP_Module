
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <climits>

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _hit;
        unsigned int    _energy;
        unsigned int    _attack;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &C);
        ClapTrap& operator=(const ClapTrap &C);
        ~ClapTrap(void);
        unsigned int	getHit(void) const;
        unsigned int	getEnergy(void) const;
        unsigned int	getAttack(void) const;
        std::string	    getName(void) const;
        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
};




#endif