#include "Base.hpp"

Base::~Base()
{}

Base*   generate(void)
{
    static bool seed = false;
    if (!seed)
    {
        std::srand(std::time(NULL));
        seed = true;
    }
    int num = std::rand() % 3;
    if ( num == 0)
        return (new A());
    else if (num == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Null pointer\n";
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else
        std::cout << "C\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch (std::exception&)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        }
        catch (std::exception&)
        {
            std::cout << "C\n";
        }
    }
}
