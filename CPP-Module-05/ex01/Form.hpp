#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	name;
		bool				indicator;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form();
		Form(const std::string& _name, const int& gts, const int& gte);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		bool		getIndicator(void) const;
		void		beSigned(Bureaucrat& bureacrat);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif