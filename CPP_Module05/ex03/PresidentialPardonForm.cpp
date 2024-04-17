
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm::AForm("Presidential Pardon Form", 25, 5)
{
    _target = "random";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm::AForm("Presidential Pardon Form", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &F) :
    AForm::AForm(F)
{
    _target = F._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &F)
{
    AForm::operator=(F);
    _target = F._target;
    return (*this);
}

void PresidentialPardonForm::action(void) const
{
    std::cout << _target << " a été pardonnée par Zaphod Beeblebrox" << std::endl;
}