
#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	int	i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]\n";
			break;
	}
}

void	Harl::debug(void)
{
	std::cout << BLUE << "[DEBUG]" << RESET << ": I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << "[INFO]" << RESET << ": I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING]" << RESET << ": I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ERROR]" << RESET << ": This is unacceptable ! I want to speak to the manager now." << std::endl;
}