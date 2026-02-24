#include "AForm.hpp"

AForm::AForm() : name("Default"), indicator(false),
    gradeToSign(150), gradeToExecute(150)
{}

AForm::AForm(const std::string& _name, int gts, int gte)
    : name(_name), indicator(false),
	gradeToSign(checkGrade(gts)), gradeToExecute(checkGrade(gte))
{}

AForm::AForm(const AForm& other)
	: name(other.name),indicator(other.indicator),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
    	indicator = other.indicator;
	return (*this);
}

int AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
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

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (indicator)
        return ;
    indicator = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > gradeToExecute)
	    throw GradeTooLowException();
	if (!indicator)
	    throw FormNotSignedException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed.");
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
