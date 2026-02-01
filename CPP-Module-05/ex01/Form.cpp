#include "Form.hpp"

Form::Form() : name("Default"), indicator(false),
    gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Default Form Constructor Called\n";
}

Form::Form(const std::string& _name, const int& gts, const int& gte)
    : name(_name), indicator(false), gradeToSign(gts), gradeToExecute(gte)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
    std::cout << "Parameterized Form Constructor Called\n";
}

Form::Form(const Form& other)
	: name(other.getName()),indicator(other.getIndicator()),
	gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{}

Form& Form::operator=(const Form& other)
{
    indicator = other.getIndicator();
	return (*this);
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

void	Form::beSigned(Bureaucrat &bureacrat)
{
	if (bureacrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (indicator)
	{
		std::cout << "Form already signed\n";
        return ;
	}
    indicator = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("[ERROR] Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("[ERROR] Grade too low.");
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
