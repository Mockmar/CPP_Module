
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm::AForm("Shrubbery Creation Form", 145, 137)
{
    _target = "random";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm::AForm("Shrubbery Creation Form", 145, 137)

{
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &F) :
    AForm::AForm(F)
{
    _target = F._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &F)
{
    AForm::operator=(F);
    _target = F._target;
	return (*this);
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream	file;

	file.open((_target + "_shrubbery").c_str(), std::ofstream::out);
	if (!file) {
		std::cout << "Unable to open the output file\n";
		return ;
	}
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%&%&%&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%&%&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
}