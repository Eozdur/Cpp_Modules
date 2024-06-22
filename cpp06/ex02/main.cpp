#include "Base.hpp"

Base *generate(void)
{
    size_t randomNumber = rand();
    Base *selectedOne;
    if (randomNumber % 3 == 1)
        selectedOne = new A;
    else if (randomNumber % 2 == 1)
        selectedOne = new B;
    else
        selectedOne = new C;
    return selectedOne;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "* Actual type object is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "* Actual type object is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "* Actual type object is C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "& Actual type object is A" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error A " << std::endl;
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "& Actual type object is B" << std::endl;
        ;
    }
    catch (std::exception &e)
    {
        std::cout << "Error " << std::endl;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "& Actual type object is C" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error C " << std::endl;
    }
}

int main()
{
    srand(time(0));
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
}