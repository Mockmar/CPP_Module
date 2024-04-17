
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    public :
        Dog(void);
        virtual ~Dog(void);
        Dog(std::string type);
        Dog(const Dog &D);
        Dog&     operator=(const Dog &D);
        virtual void     makeSound(void) const;
    private :
        Brain   *_brain;
};

#endif