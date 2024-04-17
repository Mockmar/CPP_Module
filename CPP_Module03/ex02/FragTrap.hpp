
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &C);
        FragTrap& operator=(const FragTrap &C);
        ~FragTrap(void);
        void    attack(const std::string& target);
        void    highFivesGuys(void) const;
};

#endif