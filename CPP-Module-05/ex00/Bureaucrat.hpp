#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

		int	checkGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif