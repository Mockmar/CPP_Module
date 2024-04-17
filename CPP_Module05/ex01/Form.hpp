
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
#include "Bureaucrat.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
        bool        		_signed;
        const int   		_tosign;
        const int   		_toexec;
	public :
		Form(void);
		~Form(void);
		Form(const std::string name, int tosign, int toexec);
		Form(const Form &F);
		Form&	operator=(const Form &F);
		std::string	getName(void) const;
		int			getTosign(void) const;
		int			getToexec(void) const;
		bool		getSigned(void) const;
		
		struct GradeTooHighException: public std::logic_error {
			GradeTooHighException(void): std::logic_error("error grade too high") {}
		};

		struct GradeTooLowException: public std::logic_error {
			GradeTooLowException(void): std::logic_error("error grade too low") {}
		};

		void		beSigned(Bureaucrat &B);
};

std::ostream&	operator<<(std::ostream& stream, const Form& F);

#endif