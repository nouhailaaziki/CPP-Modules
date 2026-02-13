#include "AForm.hpp"

AForm::AForm() : name("Default"), indicator(false),
    gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Default AForm Constructor Called\n";
}

AForm::AForm(const std::string& _name, const int& gts, const int& gte)
    : name(_name), indicator(false), gradeToSign(gts), gradeToExecute(gte)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
    std::cout << "Parameterized AForm Constructor Called\n";
}

AForm::AForm(const AForm& other)
	: name(other.getName()),indicator(other.getIndicator()),
	gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
	{
        indicator = other.getIndicator();
	}
	return (*this);
}

std::string	AForm::getName(void) const
{
    return(name);
}

int	AForm::getGradeToSign(void) const
{
    return (gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
    return (gradeToExecute);
}

bool	AForm::getIndicator(void) const
{
    return (indicator);
}

void	AForm::beSigned(Bureaucrat &bureacrat)
{
	if (bureacrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (indicator)
	{
		std::cout << "AForm already signed\n";
        return ;
	}
    indicator = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!indicator)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("[ERROR] Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("[ERROR] Grade too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("[ERROR] Form not signed.");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", sign grade: "
		<< obj.getGradeToSign() << ", execution grade: "
		<< obj.getGradeToExecute();
	if (obj.getIndicator())
		os << ", signed";
	else
		os << ", unsigned";
	return (os);
}

AForm::~AForm()
{}
