
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	std::cout << "List:\n";
	for (unsigned int i=0; i < vec.size(); i++)
		std::cout << vec[i] << "\n";
	std::cout << "Find 9 in list: " << *(::easyfind(vec, 9)) << std::endl;
	try {
		std::cout << "Find 11 in list: " << *(::easyfind(vec, 11)) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}