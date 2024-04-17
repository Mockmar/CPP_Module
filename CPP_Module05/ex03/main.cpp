
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("shrubbery creation", "Bender");
		std::cout << *form << std::endl;
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("presidential pardon", "Bender");
		std::cout << *form << std::endl;
		if (form)
			delete form;
	}
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("some random form", "Bender");
		if (form)
			delete form;
	}
	return (0);
}