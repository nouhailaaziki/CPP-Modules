#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	std::cout << "===== BASIC SUCCESS TEST =====\n";
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		boss.signForm(shrub);
		boss.executeForm(shrub);
	}

	std::cout << "\n===== EXECUTE UNSIGNED FORM =====\n";
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");

		boss.executeForm(shrub); // should fail
	}

	std::cout << "\n===== SIGN WITH LOW GRADE =====\n";
	{
		Bureaucrat low("Intern", 150);
		ShrubberyCreationForm shrub("home");

		low.signForm(shrub); // should fail
	}

	std::cout << "\n===== EXECUTE WITH LOW GRADE =====\n";
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Worker", 150);
		RobotomyRequestForm robot("Bender");

		signer.signForm(robot);
		executor.executeForm(robot); // should fail
	}

	std::cout << "\n===== ROBOTOMY RANDOM TEST =====\n";
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Target");

		boss.signForm(robot);
		for (int i = 0; i < 5; i++)
			boss.executeForm(robot); // success/fail randomly
	}

	std::cout << "\n===== PRESIDENTIAL PARDON =====\n";
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}

	std::cout << "\n===== SHRUBBERY FILE CREATION =====\n";
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");

		boss.signForm(shrub);
		boss.executeForm(shrub); // check file created
	}

	std::cout << "\n===== COPY TEST =====\n";
	{
		ShrubberyCreationForm a("tree");
		ShrubberyCreationForm b(a);

		Bureaucrat boss("Boss", 1);
		boss.signForm(b);
		boss.executeForm(b);
	}

	return (0);
}
