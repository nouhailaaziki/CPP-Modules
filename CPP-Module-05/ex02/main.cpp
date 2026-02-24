#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "--- BASIC SUCCESS TEST ---\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- EXECUTE UNSIGNED FORM ---\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		boss.executeForm(shrub); // should fail
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- SIGN WITH LOW GRADE ---\n";
	try
	{
		Bureaucrat low("Intern", 150);
		ShrubberyCreationForm shrub("home");

		low.signForm(shrub); // should fail
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- EXECUTE WITH LOW GRADE ---\n";
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Worker", 150);
		RobotomyRequestForm robot("Bender");

		signer.signForm(robot);
		executor.executeForm(robot); // should fail
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- ROBOTOMY RANDOM TEST ---\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Target");

		boss.signForm(robot);
		for (int i = 0; i < 5; i++)
			boss.executeForm(robot); // success/fail randomly
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- PRESIDENTIAL PARDON ---\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- SHRUBBERY FILE CREATION ---\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");

		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n--- COPY TEST ---\n";
	try
	{
		ShrubberyCreationForm a("tree");
		ShrubberyCreationForm b(a);

		Bureaucrat boss("Boss", 1);
		boss.signForm(b);
		boss.executeForm(b);
	}
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	return (0);
}
