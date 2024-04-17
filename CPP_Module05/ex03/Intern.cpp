
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    
}

Intern::~Intern(void)
{
    
}

Intern::Intern(const Intern &I)
{
    *this = I;
}

Intern& Intern::operator=(const Intern &I)
{
    (void)I;
    return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    int i;
    AForm *form[3];
    std::string namesForm[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *ret = NULL;

    form[0] = new RobotomyRequestForm(target);
    form[1] = new PresidentialPardonForm(target);
    form[2] = new ShrubberyCreationForm(target);
    for (i = 0 ; i < 3 ; i++)
    {
        if (namesForm[i] == name)
            ret = form[i];
        else
            delete (form[i]);
    }
    if (ret)
        std::cout << "Intern creates " << ret->getName() << std::endl;
    else
        std::cout << "This type of form does not exist !" << std::endl;
    return (ret);
}