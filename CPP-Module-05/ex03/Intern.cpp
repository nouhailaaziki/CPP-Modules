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

AForm* Intern::createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string names[3] = {"shrubbery creation",
        "robotomy request", "presidential pardon"};
	AForm* (Intern::*creators[3])(std::string const &) = {&Intern::createShrubbery,
		&Intern::createRobotomy, &Intern::createPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern cannot create form \"" << formName << "\"" << std::endl;
	return (NULL);
}

Intern::~Intern()
{}
