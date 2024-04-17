
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sys/types.h>
#include <stack>

bool	is_valid_rpn(std::string rpn);
double	compute_rpn(std::string rpn);

#endif