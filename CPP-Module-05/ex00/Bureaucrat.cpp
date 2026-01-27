#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "[INIT] Bureaucrat [" << name
			<< "] created with grade " << grade << ".\n";
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
	: name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
	std::cout << "[INIT] Bureaucrat [" << name
			<< "] created with grade " << grade << ".\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.getName()), grade(other.getGrade())
{
	std::cout << "[COPY] Bureaucrat [" << name 
			<< "] has been duplicated. Duplicate holds grade "
			<< grade << ".\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.getGrade();
		std::cout << "[ASSIGN] Bureaucrat [" << name
				<< "] copied grade from [" << other.getName() << "].\n";
	}
	return (*this);
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
	std::cout << "Attempting to promote [" << name 
			<< "] from grade " << grade << ".\n";
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
	std::cout << "[" << name << "] successfully promoted to grade "
			<< grade << ".\n";
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Attempting to demote " << "[" << name 
			<< "] from grade " << grade << ".\n";
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
	std::cout << "[" << name << "] successfully demoted to grade "
			<< grade << ".\n";
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
{
	std::cout << "[EXIT] Bureaucrat " << name 
			<< " has exited the bureaucracy." << std::endl;
}
