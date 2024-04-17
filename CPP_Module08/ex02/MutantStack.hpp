
#ifndef MUTANSTACK_HPP
# define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<class T>
class MutantStack : public std::stack<T>
{
    public :
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack(void): std::stack<T>() {}
		MutantStack(const MutantStack &mutantstack): std::stack<T>(mutantstack) {}
		MutantStack& operator=(const MutantStack &mutantstack)
		{
			if (this == &mutantstack)
        		return *this;
    		std::stack<T>::operator=(mutantstack);
		    return *this;
		}
		~MutantStack(void) {}

		iterator	begin(void)
		{
			return this->c.begin();
		}

		iterator	end(void)
		{
			return this->c.end();
		}

		const iterator	begin(void) const
		{
			return this->c.begin();
		}

		const iterator	end(void) const
		{
			return this->c.end();
		}
};

#endif