#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
	: name(_name), grade(checkGrade(_grade))
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

int	Bureaucrat::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	grade = checkGrade(grade - 1);
}

void Bureaucrat::decrementGrade()
{
	grade = checkGrade(grade + 1);
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn't sign "
                  << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[ERROR] Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[ERROR] Grade too low.");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade "
		<< obj.getGrade() << ".";
	return (os);
}

Bureaucrat::~Bureaucrat()
{}
