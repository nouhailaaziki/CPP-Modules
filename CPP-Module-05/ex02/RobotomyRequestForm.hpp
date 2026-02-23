#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;

	protected:
		void executeAction() const;

	public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
};

#endif
