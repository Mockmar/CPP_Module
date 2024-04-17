
# include "Span.hpp"

Span::~Span(void)
{

}

Span::Span(void)
{
    _N = 0;
}

Span::Span(unsigned int N)
{
    _N = N;
}

Span::Span(const Span &S)
{
    *this = S; 
}

Span& Span::operator=(const Span &S)
{
    *this = S;
    return (*this);
}

void Span::addNumber(int nb)
{
    if (_nb.size() == _N)
        throw std::out_of_range("C'est complet!");
    _nb.push_back(nb);
}

unsigned int	Span::longestSpan(void)
{
	if (_nb.empty())
		throw std::logic_error("list is empty");
	if (_nb.size() == 1)
		throw std::logic_error("only one element");
	std::list<int>::iterator	min = std::min_element(_nb.begin(), _nb.end());
	std::list<int>::iterator	max = std::max_element(_nb.begin(), _nb.end());
	unsigned int result = *max - *min;
	if (!result)
		throw std::logic_error("distance null");
	return (result);	
}

unsigned int	Span::shortestSpan(void)
{
	if (_nb.empty())
		throw std::logic_error("list is empty");
	if (_nb.size() == 1)
		throw std::logic_error("only one element");
	unsigned int result = UINT_MAX;
    for (std::list<int>::iterator it1 = _nb.begin(); it1 != _nb.end(); it1++)
    {
        for (std::list<int>::iterator it2 = _nb.begin(); it2 != _nb.end(); it2++)
        {
            if (it1 != it2 && std::abs(*it1 - *it2) < result)
                result = std::abs(*it1 - *it2);
        }
    }
	return (result);	
}

void	Span::addRange(std::list<int>::iterator start, std::list<int>::iterator end)
{
	unsigned int count = _nb.size();
	for(std::list<int>::iterator it = start; it != end; it++)
	{
		this->addNumber(*it);
	}
}

std::list<int>  Span::getNb(void) const
{
	return (_nb);
}


std::ostream&	operator<<(std::ostream& stream, const Span &span)
{
    std::list<int> tmpList = span.getNb();
	if (tmpList.empty())
		return stream;
    for (std::list<int>::iterator it = tmpList.begin(); it != tmpList.end(); it++)
	    stream << "[" << *it << "]";
	return stream;
}