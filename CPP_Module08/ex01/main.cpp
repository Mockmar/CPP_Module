
# include "Span.hpp"

int main() 
{
    {
        {
            std::cout << "---Test basique---" << std::endl;
            Span sp(10);
            sp.addNumber(6);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp << std::endl;
            std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        }
        {
            std::cout << "---Test addRange---" << std::endl;
            try
            {
                Span sp(10);
                sp.addNumber(6);
                sp.addNumber(17);
                sp.addNumber(9);
                sp.addNumber(11);
                std::cout << sp << std::endl;
                std::list<int> myList;
                myList.push_back(1);
                myList.push_back(2);
                myList.push_back(3);
                sp.addRange(myList.begin(), myList.end());
                std::cout << sp << std::endl;
                std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }        
        {
            std::cout << "---Test c'est complet addRange---" << std::endl;
            try
            {
                Span sp(6);
                sp.addNumber(6);
                sp.addNumber(17);
                sp.addNumber(9);
                sp.addNumber(11);
                std::list<int> myList;
                myList.push_back(1);
                myList.push_back(2);
                myList.push_back(3);
                sp.addRange(myList.begin(), myList.end());
                std::cout << sp << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        {
            std::cout << "---Test c'est complet basique---" << std::endl;
            try
            {
                Span sp(2);
                sp.addNumber(6);
                sp.addNumber(17);
                sp.addNumber(9);
                sp.addNumber(11);
                std::cout << sp << std::endl;
                std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        {
            std::cout << "---Test only one element---" << std::endl;
            try
            {
                Span sp(2);
                sp.addNumber(9);
                std::cout << sp << std::endl;
                std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        {
            std::cout << "---Test empty list---" << std::endl;
            try
            {
                Span sp(2);
                std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
                std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

    }

    srand(time(NULL));
	{
        std::cout << "---Test big list---" << std::endl;
		Span	sp(20000);

		for (unsigned int i=0; i < 20000; i++)
			sp.addNumber(rand() % 10000000);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

    return 0;
}