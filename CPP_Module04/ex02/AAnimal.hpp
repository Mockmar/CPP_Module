
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected :
        std::string _type;
    public :
        AAnimal(void);
        AAnimal(std::string type);
        virtual ~AAnimal(void);
        AAnimal(const AAnimal &A);
        AAnimal&     operator=(const AAnimal &A);
        std::string getType(void) const;
        virtual void        makeSound(void) const = 0;
};

#endif