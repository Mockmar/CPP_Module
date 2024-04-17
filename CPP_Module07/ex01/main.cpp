
#include "iter.hpp"

template <typename T, typename Func>
void iter(T *array, size_t len, Func func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void print(T element)
{
    std::cout << "[" << element << "]";
}

void increment(int &i)
{
    i++;
}

void    charup(char &c)
{
    c -= 32;
}

int main()
{
    int array[] = {1, 1, 2, 3, 5, 8};
    char str[] = "abcdef";

    std::cout << std::endl << "-----Liste-----" << std::endl;
    iter(array, 6, print<int>);
    iter(array, 6, increment);
    std::cout << std::endl << "-----Incrementation-----" << std::endl;
    iter(array, 6, print<int>);
    std::cout << std::endl;
    std::cout << std::endl << "-----Chaine-----" << std::endl;
    iter(str, 6, print<char>);
    iter(str, 6, charup);
    std::cout << std::endl << "-----Charup-----" << std::endl;
    iter(str, 6, print<char>);

    return 0;
}
