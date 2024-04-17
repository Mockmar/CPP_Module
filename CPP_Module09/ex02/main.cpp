
#include "PmergeMe.hpp"

bool isInt(const std::string str)
{
    std::istringstream iss(str);
    int value;
    return (iss >> value) && iss.eof();
}

void checkinput(char **av, std::vector<int> &vec, std::list<int> &lst)
{
	int i = 1;
	int nb;

	while (av[i])
	{
		if (isInt(av[i]))
		{
			nb = std::atoi(av[i]);
			if (nb < 0)
				throw std::runtime_error("Error: negative nb");
			else
			{
				vec.push_back(nb);
				lst.push_back(nb);
			}
		}
		else
			throw std::runtime_error("Error: bad input");
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "faut mettre des argument au prog" << std::endl;
		return 1;
	}
    std::vector<int> vec;
    std::list<int> lst;
	try
	{
		checkinput(av, vec, lst);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}		
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::clock_t startVec = std::clock();
    mergeSortVector(vec, 0, vec.size() - 1);
    std::clock_t endVec = std::clock();
    std::clock_t startLst = std::clock();
    mergeSortList(lst);
    std::clock_t endLst = std::clock();
    std::cout << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    } 
    std::cout << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of "<< lst.size() << " elements with std::list : " << 1000000.0 * (endLst - startLst) / CLOCKS_PER_SEC << " µs" << std::endl;
    std::cout << "Time to process a range of "<< vec.size() << " elements with std::vector : " << 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC << " µs" << std::endl;
}