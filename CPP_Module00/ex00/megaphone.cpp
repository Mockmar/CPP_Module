
#include <string>
#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac > 1)
    {
        for (i = 1 ; i < ac ; i++)
        {
            std::string str(av[i]);
            for (j = 0 ; j < (int)str.length() ; j++)
            {
                std::cout<<(char)std::toupper(str[j]);
            }
        }
        std::cout << std::endl;
    }
    else
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return (0);
}