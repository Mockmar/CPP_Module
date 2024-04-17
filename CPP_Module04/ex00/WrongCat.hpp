
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(void);
        virtual ~WrongCat(void);
        WrongCat(std::string type);
        WrongCat(const WrongCat &C);
        WrongCat&     operator=(const WrongCat &C);
        void        makeSound(void) const;
};

#endif