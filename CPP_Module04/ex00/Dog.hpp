
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog(void);
        ~Dog(void);
        Dog(std::string type);
        Dog(const Dog &D);
        Dog&     operator=(const Dog &D);
        virtual void     makeSound(void) const;
};

#endif