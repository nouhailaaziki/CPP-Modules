#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- BASIC CONSTRUCTION ---\n";
    try
    {
        Bureaucrat a("Anna", 1);
        Bureaucrat b("Ben", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- INVALID CONSTRUCTION ---\n";
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

    std::cout << "\n--- INCREMENT / DECREMENT ---\n";
    try
    {
        Bureaucrat e("Ellie", 2);
        std::cout << e << std::endl;

        e.incrementGrade(); // goes to 1
        std::cout << e << std::endl;

        e.incrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat f("Felix", 149);
        std::cout << f << std::endl;

        f.decrementGrade(); // goes to 150
        std::cout << f << std::endl;

        f.decrementGrade(); // should throw
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- COPY & ASSIGNMENT ---\n";
    try
    {
        Bureaucrat g("Giselle", 42);
        Bureaucrat x(g);
        Bureaucrat h("Henry", 100);

        std::cout << g << std::endl;
        std::cout << x << std::endl;

        h = g;
        std::cout << h << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
