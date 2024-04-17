
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(const Character& character);
		~Character(void);
		Character&	operator=(const Character& character);
		Character(std::string name);

		void				equip(AMateria* m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter& target);
		const std::string&	getName() const;
		AMateria*			getItem(int idx) const;

	private:
		static const int	NB_ITEMS = 4;

		std::string	_name;
		AMateria	*_inventory[NB_ITEMS];
};

#endif