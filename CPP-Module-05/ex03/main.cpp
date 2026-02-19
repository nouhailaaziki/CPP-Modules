#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm shrub("home");

	boss.signForm(shrub);
	boss.executeForm(shrub);

	Intern someRandomIntern;
	AForm* f;
	
	f = someRandomIntern.makeForm("robotomy request", "Bender");
	if (f)
	{
		boss.signForm(*f);
		boss.executeForm(*f);
		delete f;
	}
	
	return (0);
}
