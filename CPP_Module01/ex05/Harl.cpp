
#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	funcPTR	    functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i < 4; i++)
    {
		if (levels[i] == level)
			(this->*functions[i])();
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