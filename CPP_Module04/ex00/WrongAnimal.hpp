
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    protected :
        std::string _type;
    public :
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &A);
        WrongAnimal&     operator=(const WrongAnimal &A);
        std::string getType(void) const;
        void        makeSound(void) const;
};

#endif