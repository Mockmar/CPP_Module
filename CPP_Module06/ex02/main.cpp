
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <experimental/random>

Base *generate(void)
{
    int alea = std::rand();

    if (alea % 3 == 0)
    {
        A *ret0 = new A;
        std::cout << "A class create" << std::endl;
        return (ret0);
    }
    else if (alea % 3 == 1)
    {
        B *ret1 = new B;
        std::cout << "B class create" << std::endl;
        return (ret1);
    }
    else if (alea % 3 == 2)
    {
        C *ret2 = new C;
        std::cout << "C class create" << std::endl;
        return (ret2);
    }
    return (NULL);
}

void    identify(Base *p)
{
    A *aptr = dynamic_cast<A*>(p);
    B *bptr = dynamic_cast<B*>(p);
    C *cptr = dynamic_cast<C*>(p);

    if (aptr != NULL)
    {
        std::cout << "A class ptr identify" << std::endl;
        return ;
    }
    if (bptr != NULL)
    {
        std::cout << "B class ptr identify" << std::endl;
        return ;
    }
    if (cptr != NULL)
    {
        std::cout << "C class ptr identify" << std::endl;
        return ;
    }
    return ;
}

void    identify(Base &p)
{
    try
    {
        A &aptr = dynamic_cast<A&>(p);
        (void)aptr;
        std::cout << "A class ref identify" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        B &bptr = dynamic_cast<B&>(p);
        (void)bptr;
        std::cout << "B class ref identify" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        C &cptr = dynamic_cast<C&>(p);
        (void)cptr;
        std::cout << "C class ref identify" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    return ;
}

int main()
{
    srand(time(NULL));
    Base *B = NULL;

    B = generate();
    identify(B);
    identify(*B);
    delete (B);
}