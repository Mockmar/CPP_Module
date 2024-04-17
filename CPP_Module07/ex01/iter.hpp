
#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void    iter(T *array, size_t len, Func func);

template <typename T>
void    print(T element);

void    increment(int &i);

void    charup(char &c);

#endif