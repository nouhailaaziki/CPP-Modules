#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm( "RobotomyRequestForm", 72, 45 )
{
	std::cout << "Form type: RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm( "RobotomyRequestForm", 72, 45 ), target(target)
{
	std::cout << "Form type: RobotomyRequestForm" << std::endl;
}

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
	std::cout << "* drilling noises *\n";
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy failed on " << target << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
