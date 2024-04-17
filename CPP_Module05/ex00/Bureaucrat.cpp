
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Didier"), _grade(150)
{
}

Bureaucrat::~Bureaucrat(void)
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade = 150) : _name(name)
{
	if (grade < HIGHGRADE)
        throw GradeTooHighException();
    if (grade > LOWGRADE)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &B)
{
    *this = B;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &B)
{
    _name = B._name;
    _grade = B._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (_name);    
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);    
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& B)
{
	stream << B.getName() << ", Bureaucrat grade " << B.getGrade();
	return stream;
}

void    Bureaucrat::incrementation(void)
{
    if (_grade == HIGHGRADE)
        throw GradeTooHighException();
    else
        _grade--;
}

void    Bureaucrat::decrementation(void)
{
    if (_grade == LOWGRADE)
        throw GradeTooLowException();
    else
        _grade++;
}