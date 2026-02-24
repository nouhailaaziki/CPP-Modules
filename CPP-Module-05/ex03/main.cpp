#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* rrf;

    std::cout << "--- TEST 1: SUCCESSFUL ROBOTOMY REQUEST ---" << std::endl;
    try
	{
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: SUCCESSFUL SHRUBBERY CREATION ---" << std::endl;
    try
	{
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: SUCCESSFUL PRESIDENTIAL PARDON ---" << std::endl;
    try
	{
        rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: UNKNOWN FORM (FAILURE) ---" << std::endl;
    try
	{
        rrf = someRandomIntern.makeForm("world domination request", "Evil Genius");
        boss.signForm(*rrf);
        delete rrf;
    }
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }

    return (0);
}