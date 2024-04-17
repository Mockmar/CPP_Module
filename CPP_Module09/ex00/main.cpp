
#include "BitcoinExchange.hpp"



int	main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " <file.txt>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange	be = BitcoinExchange("data.csv");
		calcul_price(av[1], be);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

