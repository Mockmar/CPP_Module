
#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <climits>

enum e_type
{
	TYPE_NOTHING,
	TYPE_NAN,
	TYPE_INF_MINUS,
	TYPE_INF_PLUS
};

class  ScalarConvert
{
    public :
		ScalarConvert();
		~ScalarConvert();
		ScalarConvert(const ScalarConvert &SC);
		ScalarConvert& operator=(const ScalarConvert &SC);
        static void convert(std::string& str);
};

bool    is_int(const char *str);
bool    is_char(const char *str);
bool    is_float(const char *str);
bool    is_double(const char *str);
e_type is_spe_string(std::string str);

void    print_char(std::string str);
void    print_int(std::string str);
void    print_double(std::string str);
void	print_spe_string(e_type type);
void	print_impossible(void);

#endif