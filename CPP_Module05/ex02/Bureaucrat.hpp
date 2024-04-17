
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class AForm;

class Bureaucrat
{
	private :
		std::string	_name;
		int			_grade;
	public :
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &B);
		Bureaucrat&	operator=(const Bureaucrat &B);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementation(void);
		void		decrementation(void);
		
		struct GradeTooHighException: public std::logic_error {
			GradeTooHighException(void): std::logic_error("error grade too high") {}
		};

		struct GradeTooLowException: public std::logic_error {
			GradeTooLowException(void): std::logic_error("error grade too low") {}
		};

		void	signForm(AForm &F);
		void	executeForm(const AForm &form) const;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& B);

#endif