
#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string taget);
		ShrubberyCreationForm(const ShrubberyCreationForm &F);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &F);
		virtual void action(void) const;
};

#endif