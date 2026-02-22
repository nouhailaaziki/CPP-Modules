#include "Form.hpp"

int main()
{
    std::cout << "\n========== FORM CREATION TESTS ==========\n";
    try
    {
        Form f1("TopSecret", 10, 5);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form f2("InvalidLow", 151, 10); // too low
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form f3("InvalidHigh", 0, 10); // too high
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== SIGNING TESTS ==========\n";
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    Form contract("Contract", 50, 25);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;
    std::cout << contract << std::endl;

    std::cout << "\n-- Intern tries to sign --\n";
    try
    {
        intern.signForm(contract);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-- Boss signs the form --\n";
    try
    {
        boss.signForm(contract);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << contract << std::endl;

    std::cout << "\n========== DOUBLE SIGN TEST ==========\n";
    try
    {
        boss.signForm(contract); // already signed
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== STREAM OPERATOR TEST ==========\n";
    Form report("Report", 30, 10);
    std::cout << report << std::endl;

    return (0);
}