
# include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{

}

ScalarConvert::~ScalarConvert()
{
    
}

ScalarConvert::ScalarConvert(const ScalarConvert &SC)
{
    *this = SC;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert &SC)
{
    (void)SC;
    return (*this);
}

void ScalarConvert::convert(std::string& str)
{
	if (is_spe_string(str))
		print_spe_string(is_spe_string(str));
    else if (is_int(str.c_str()))
        print_int(str);
    else if (is_char(str.c_str()))
        print_char(str);
	else if (is_double(str.c_str()) || is_float(str.c_str()))
		print_double(str);
    else
	    print_impossible();
}