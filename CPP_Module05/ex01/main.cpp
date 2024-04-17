
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test the form constuctors:\n";
		Form	form1;
		Form	form2("validate budget", 1, 10);
		Form	form3(form2);

		form1 = form3;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;

		try
		{
			Form	form4("fire CEO", 0, 1);
			std::cout << "This text should not appear !" << std::endl;
		}
		catch (Form::GradeTooLowException& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Form::GradeTooHighException& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\nTest the form sign function:" << std::endl;
		Form	form("law contract", 10, 1);
		Bureaucrat	Victor("Victor", 9);
		Bureaucrat	Nathan("Nathan", 11);

		Victor.signForm(form);
		Nathan.signForm(form);
	}
    return (0);
}