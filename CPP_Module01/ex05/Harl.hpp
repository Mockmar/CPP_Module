
#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

# define RED	"\e[0;31m"
# define GREEN	"\e[0;32m"
# define YELLOW	"\e[0;33m"
# define BLUE	"\e[0;34m"
# define RESET	"\e[0m"

class Harl
{
	public:
		void	complain(std::string level);
	private:
		typedef void (Harl::*funcPTR)(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif