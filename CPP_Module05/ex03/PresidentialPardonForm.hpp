
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
#include "AForm.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string taget);
		PresidentialPardonForm(const PresidentialPardonForm &F);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &F);
		virtual void action(void) const;
};

#endif