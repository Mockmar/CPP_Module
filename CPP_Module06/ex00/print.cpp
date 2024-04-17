
#include "ScalarConvert.hpp"

void    print_char(std::string str)
{
    char c = str[0];
    std::cout << "char  : '" << c << "'" << std::endl;
	std::cout << "int   : " << static_cast<int>(c) << std::endl;
	std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
	std::cout << "float : " << static_cast<int>(c) << ".0f" << std::endl;
}

void    print_int(std::string str)
{
	std::cout << std::fixed << std::setprecision(1);
    int i = std::atoi(str.c_str());
    double 	d = std::atof(str.c_str());
    if (i > CHAR_MIN && i < CHAR_MAX && isprint(i))
	{
    	std::cout << "char  : '" << static_cast<char>(i) << "'" << std::endl;
	}
    else
	{
    	std::cout << "char  : Non displayable" << std::endl;
	}
	if ( d > INT_MAX || d < INT_MIN)
		std::cout << "int   : out of range" << std::endl;
	else
		std::cout << "int   : " << i << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "float : " << d << "f" << std::endl;
}

void    print_double(std::string str)
{
    double 	d = std::atof(str.c_str());
	int		i = static_cast<int>(d);
	if (d == i)
		std::cout << std::fixed << std::setprecision(1);
    if (i > CHAR_MIN && i < CHAR_MAX && isprint(i))
	{
    	std::cout << "char  : '" << static_cast<char>(i) << "'" << std::endl;
	}
    else
	{
    	std::cout << "char  : Non displayable" << std::endl;
	}
	std::cout << "int   : " << i << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout << "float : " << d << "f" << std::endl;
}

void	print_spe_string(e_type type)
{
    std::cout << "char  : impossible" << std::endl;
	std::cout << "int   : impossible" << std::endl;
	if (type == TYPE_NAN)
	{
		std::cout << "double: nan" << std::endl;
		std::cout << "float : nan" << "f" << std::endl;
	}
	else if (type == TYPE_INF_MINUS)
	{
		std::cout << "double: -inf" << std::endl;
		std::cout << "float : -inf" << "f" << std::endl;		
	}
	else if (type == TYPE_INF_PLUS)
	{
		std::cout << "double: +inf" << std::endl;
		std::cout << "float : +inf" << "f" << std::endl;
	}

}

void	print_impossible(void)
{
    std::cout << "char  : impossible" << std::endl;
	std::cout << "int   : impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;	
}