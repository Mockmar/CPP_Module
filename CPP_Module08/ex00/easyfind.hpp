
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;

    it = find(container.begin(), container.end(), n);
    if (it != container.end())
        return (it);
    throw std::runtime_error("Pas trouver");
}

#endif