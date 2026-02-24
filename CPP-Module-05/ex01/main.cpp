#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- Invalid Form Creation ---" << std::endl;
    try
    {
        Form high("A1", 0, 10); // Too high
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        Form low("A2", 10, 151); // Too low
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Signing Grade Requirements ---" << std::endl;
    try
    {
        Bureaucrat  intern("Intern", 150);
        Form        difficult("Form 28-B", 1, 1);
        
        std::cout << difficult << std::endl;
        intern.signForm(difficult); // Should fail
        std::cout << difficult << std::endl; // Should show as NOT signed
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Successful Signing ---" << std::endl;
    try
    {
        Bureaucrat  boss("Boss", 1);
        Form        easy("Form 1-A", 150, 150);
        
        boss.signForm(easy);
        std::cout << easy << std::endl; // Should show as signed
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}