#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm shrub("home");

	boss.signForm(shrub);
	boss.executeForm(shrub);

	return (0);
}
