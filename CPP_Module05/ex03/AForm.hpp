
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
#include "Bureaucrat.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat;

class AForm
{
	protected :
		const std::string	_name;
        bool        		_signed;
        const int   		_tosign;
        const int   		_toexec;
	public :
		AForm(void);
		virtual ~AForm(void);
		AForm(std::string name, int tosign, int toexec);
		AForm(const AForm &F);
		AForm&	operator=(const AForm &F);
		
		virtual std::string	getName(void) const;
		virtual int			getTosign(void) const;
		virtual int			getToexec(void) const;
		virtual bool		getSigned(void) const;
		
		struct GradeTooHighException: public std::logic_error {
			GradeTooHighException(void): std::logic_error("error grade too high") {}
		};

		struct GradeTooLowException: public std::logic_error {
			GradeTooLowException(void): std::logic_error("error grade too low") {}
		};

		struct FormNotSignedException: public std::runtime_error {
			FormNotSignedException(void): std::runtime_error("error the form is not signed") {}
		};

		virtual void	execute(const Bureaucrat& executor) const;
		void			beSigned(Bureaucrat &B);
		virtual	void	action(void) const = 0;
};

std::ostream&	operator<<(std::ostream& stream, const AForm& F);

#endif