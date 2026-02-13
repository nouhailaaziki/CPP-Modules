#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	name;
		bool				indicator;
		const int			gradeToSign;
		const int			gradeToExecute;

    protected:
		virtual void    executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string& _name, const int& gts, const int& gte);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		bool		getIndicator(void) const;
		void		beSigned(Bureaucrat& bureacrat);
		void		execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

        class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif