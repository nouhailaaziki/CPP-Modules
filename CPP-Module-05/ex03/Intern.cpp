#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern &)
{}

Intern &Intern::operator=(const Intern &)
{
    return (*this);
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Intern cannot create the form.");
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string names[3] = {"shrubbery creation",
        "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (!formName.compare(names[i]))
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw FormNotFoundException();
	}
}

Intern::~Intern()
{}
