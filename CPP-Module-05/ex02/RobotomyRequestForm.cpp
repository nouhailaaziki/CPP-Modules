#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm( "RobotomyRequestForm", 72, 45 ), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &other)
{
	if (this != &other)
    {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	static bool seed = false;
	if (!seed)
	{
		std::srand(std::time(NULL));
		seed = true;
	}
	std::cout << "* drilling noises *\n";
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed on " << target << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
