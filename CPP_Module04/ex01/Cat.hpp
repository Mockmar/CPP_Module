
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public :
        Cat(void);
        virtual ~Cat(void);
        Cat(std::string type);
        Cat(const Cat &C);
        Cat&     operator=(const Cat &C);
        virtual void        makeSound(void) const;
    private :
        Brain   *_brain;
};

#endif