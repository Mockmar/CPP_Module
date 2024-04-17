
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>
# include <cmath>

class Span
{
    private :
        unsigned int        _N;
        std::list<int>    _nb;
    public :
        ~Span();
        Span();
        Span(unsigned int N);
        Span(const Span &S);
        Span& operator=(const Span &S);

        std::list<int>  getNb(void) const;
        void            addNumber(int nb);
        unsigned int    longestSpan(void);
        unsigned int    shortestSpan(void);
        void	        addRange(std::list<int>::iterator start, std::list<int>::iterator end);
};

std::ostream&	operator<<(std::ostream& stream, const Span &span);

#endif