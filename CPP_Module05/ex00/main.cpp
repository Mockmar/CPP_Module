
#include "Bureaucrat.hpp"

int main()
{
	int	grade;
		
	std::cout << "Balance un grade: ";
	std::cin >> grade;
	{
    	try
    	{
    		Bureaucrat B("Bernard", grade);
    	    std::cout << B << std::endl;
    		B.incrementation();
    		std::cout << B << std::endl;
    	}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
    	try
    	{
    		Bureaucrat B("Bernard", grade);
    		std::cout << B << std::endl;
    		B.decrementation();
    		std::cout << B << std::endl;
    	}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    return (0);
}