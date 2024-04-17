
#include <iostream>
#include "RPN.hpp"

int	main(int ac, char ** av)
{
	if (ac != 2)
	{
		std::cout << "Error: need input" << std::endl;
		return 1;
	}
	if (!is_valid_rpn(av[1]))
	{
		std::cout << "Error: bad input" << std::endl;
		return 1;
	}
	std::cout << compute_rpn(av[1]) << std::endl;
	return 0;
}