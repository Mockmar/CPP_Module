
#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer &S)
{
    *this = S;
}

Serializer& Serializer::operator=(const Serializer &S)
{
    (void)S;
    return (*this);
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}