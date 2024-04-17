
#include "RPN.hpp"

bool	isoperator(int c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	is_valid_rpn(std::string rpn)
{
	std::stack<char>	rpn_stack;

	for (int i = 0; i < rpn.size(); i++)
	{
		if (rpn[i] != ' ')
		{
			if (std::isdigit(rpn[i]))
				rpn_stack.push(rpn[i]);
			else if (isoperator(rpn[i]))
			{
				if (rpn_stack.size() < 2)
					return false ;
				rpn_stack.pop();
			}
			else
				return false ;
		}
	}
	return (rpn_stack.size() == 1);
}

double	compute_rpn(std::string rpn)
{
	std::stack<double>	rpn_stack;

	for (int i = 0; i < rpn.size(); i++)
	{
		if (rpn[i] != ' ')
		{
			if (std::isdigit(rpn[i]))
				rpn_stack.push(rpn[i] - '0');
			else
			{
				double a, b;
				b = rpn_stack.top();
				rpn_stack.pop();
				a = rpn_stack.top();
				rpn_stack.pop();
				switch (rpn[i])
				{
					case '+':
						rpn_stack.push(a + b);
						break;
					case '-':
						rpn_stack.push(a - b);
						break;
					case '*':
						rpn_stack.push(a * b);
						break;
					case '/':
						rpn_stack.push(a / b);
				}
			}
		}
	}
	return (rpn_stack.top());
}