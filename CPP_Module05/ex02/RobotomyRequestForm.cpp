
#include "RobotomyRequestForm.hpp"
#include <experimental/random> 

RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm::AForm("Robotomy Request Form", 72, 45)
{
    _target = "random";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm::AForm("Robotomy Request Form", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &F) :
    AForm::AForm(F)
{
    _target = F._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &F)
{
    AForm::operator=(F);
    _target = F._target;
    return (*this);
}

void RobotomyRequestForm::action(void) const
{
    int alea = std::rand();
    std::cout << "* MaKe SomE NOisE *" << std::endl;
    if (alea % 2 == 0)
        std::cout << "Robotomy executed Successfully" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}