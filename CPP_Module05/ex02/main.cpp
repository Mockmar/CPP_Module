
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{
	srand(time(NULL));
	{
		std::cout << "Test case Shrubbery Creation form, all working:" << std::endl;
		ShrubberyCreationForm	form("home");
		Bureaucrat				b("Granny", 100);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case Roboto Request form, all working:" << std::endl;
		RobotomyRequestForm	form("Theo");
		Bureaucrat			b("R2D2", 45);

		b.signForm(form);
		for (int i = 0 ; i < 10 ; i++)
			b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case Presidential Pardon form, all working:" << std::endl;
		PresidentialPardonForm form("Victor");
		Bureaucrat	b("Arthur", 5);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case permission to sign but not to execute" << std::endl;
		PresidentialPardonForm form("Maro");
		Bureaucrat	b("Nathan", 15);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test case no enough permissions at all" << std::endl;
		PresidentialPardonForm form("Paul");
		Bureaucrat	b("Nassim", 30);

		b.signForm(form);
		b.executeForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "Test operateur assignation" << std::endl;
		Bureaucrat	b("Arthur", 5);
		PresidentialPardonForm form("Paul");
		PresidentialPardonForm form2("Didier");
		
		b.signForm(form);
		b.signForm(form2);
		b.executeForm(form);
		b.executeForm(form2);
		form = form2;
		b.executeForm(form);
		b.executeForm(form2);
	}

	return (0);
}