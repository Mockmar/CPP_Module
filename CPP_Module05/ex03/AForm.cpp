
#include "AForm.hpp"

AForm::AForm(void) :
    _name("R404"),
    _tosign(150),
    _toexec(150)
{
    _signed = false;
}

AForm::~AForm(void)
{

}

AForm::AForm(std::string name, int tosign, int toexec) :
    _name(name),
    _tosign(tosign),
    _toexec(toexec)
{
    _signed = false;
	if (tosign < HIGHGRADE || toexec < HIGHGRADE)
        throw GradeTooHighException();
    else if (tosign > LOWGRADE || toexec > LOWGRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &F) :
    _name(F._name),
    _tosign(F._tosign),
    _toexec(F._toexec)
{
    _signed = F._signed;
}

AForm& AForm::operator=(const AForm &F)
{
    _signed = F._signed;
    return (*this);
}

std::string AForm::getName(void) const
{
    return (_name);    
}

bool AForm::getSigned(void) const
{
    return (_signed);    
}

int AForm::getTosign(void) const
{
    return (_tosign);    
}

int AForm::getToexec(void) const
{
    return (_toexec);    
}

std::ostream&	operator<<(std::ostream& stream, const AForm& F)
{
	stream << F.getName() << ", Form ";
    if (F.getSigned())
        stream << "signed,";
    else
        stream << "not signed,";
    stream << " grade to sign " << F.getTosign();    
    stream << " grade to execute " << F.getToexec();    
	return stream;
}

void	AForm::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > _tosign)
        throw GradeTooLowException();
    else
	    _signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_signed == false)
	{
		std::cout << executor.getGrade() << " cant execute form :" << _name << std::endl;
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > _toexec)
	{
		std::cout << executor.getGrade() << " cant execute form :" << _name << std::endl;
		throw GradeTooLowException();
	}
	else
	{
		this->action();
	}
}