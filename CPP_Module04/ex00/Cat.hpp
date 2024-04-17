
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat(void);
        ~Cat(void);
        Cat(std::string type);
        Cat(const Cat &C);
        Cat&     operator=(const Cat &C);
        virtual void        makeSound(void) const;
};

#endif