#include "Form.hpp"

Form::Form() : name("Default"), indicator(false),
    gradeToSign(150), gradeToExecute(150)
{}

Form::Form(const std::string& _name, const int gts, const int gte)
    : name(_name), indicator(false),
	gradeToSign(checkGrade(gts)), gradeToExecute(checkGrade(gte))
{}

Form::Form(const Form& other)
	: name(other.name),indicator(other.indicator),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
    	indicator = other.indicator;
	return (*this);
}

int Form::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::string	Form::getName(void) const
{
    return(name);
}

int	Form::getGradeToSign(void) const
{
    return (gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
    return (gradeToExecute);
}

bool	Form::getIndicator(void) const
{
    return (indicator);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (indicator)
        return ;
    indicator = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
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

Form::~Form()
{}
