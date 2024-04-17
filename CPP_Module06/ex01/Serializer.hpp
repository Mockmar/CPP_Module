
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
    public :
        Serializer();
        ~Serializer();
        Serializer(const Serializer &S);
        Serializer& operator=(const Serializer &S);

        static uintptr_t   serialize(Data *ptr);
        static Data*       deserialize(uintptr_t raw);
};

#endif