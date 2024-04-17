
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include "AForm.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private :
		std::string	_target;
	public :
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string taget);
		RobotomyRequestForm(const RobotomyRequestForm &F);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &F);
		virtual void action(void) const;
};

#endif