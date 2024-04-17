
#include "Form.hpp"

Form::Form(void) : 
    _name("R404"),
    _tosign(150),
    _toexec(150)
{
    _signed = false;
}

Form::~Form(void)
{
    
}

Form::Form(std::string name, int tosign, int toexec) : 
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

Form::Form(const Form &F) :
    _name(F._name),
    _tosign(F._tosign),
    _toexec(F._toexec)
{
    _signed = F._signed;
}

Form& Form::operator=(const Form &F)
{
    _signed = F._signed;
    return (*this);
}

std::string Form::getName(void) const
{
    return (_name);    
}

bool Form::getSigned(void) const
{
    return (_signed);    
}

int Form::getTosign(void) const
{
    return (_tosign);    
}

int Form::getToexec(void) const
{
    return (_toexec);    
}

std::ostream&	operator<<(std::ostream& stream, const Form& F)
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

void	Form::beSigned(Bureaucrat &B)
{
    if (B.getGrade() > _tosign)
        throw GradeTooLowException();
    else
	    _signed = true;
}