#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== BASIC CONSTRUCTION =====\n";
    try
    {
        Bureaucrat a("Anna", 1);
        Bureaucrat b("Ben", 150);

        std::cout << a;
        std::cout << b;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID CONSTRUCTION =====\n";
    try
    {
        Bureaucrat c("Cecilia", -1); // too high
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("Daniel", 151); // too low
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== INCREMENT / DECREMENT =====\n";
    try
    {
        Bureaucrat e("Ellie", 75);
        std::cout << e;

        e.incrementGrade(); // goes to 1
        std::cout << e;

        e.incrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat f("Felix", 149);
        std::cout << f;

        f.decrementGrade(); // goes to 150
        std::cout << f;

        f.decrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== COPY & ASSIGNMENT =====\n";
    try
    {
        Bureaucrat g("Giselle", 42);
        Bureaucrat x(g);
        Bureaucrat h("Henry", 100);

        std::cout << g;
        std::cout << x;

        h = g;
        std::cout << h;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}
