
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Intern
{
	public :
		Intern(void);
		~Intern(void);
		Intern(const Intern &I);
		Intern&	operator=(const Intern &I);
		
    	AForm* makeForm(std::string name, std::string target);
};

#endif