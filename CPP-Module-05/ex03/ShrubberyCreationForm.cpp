#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Form type: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Form type: ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other)
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
    {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void    ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	file << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠉⠙⠿⢿⡿⠿⠁⠀⠀⠀⠀⠀⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠉⠙⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⡿⠛⠋⠉⠙⠙⠁⠀⠀⠂⠀⠀⠀⠀⠄⠀⠀⠀⠀⠤⠉⠛⠶⣄⣠⣤⣤⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⡏⣄⠀⠃⠀⠀⠀⢀⣀⠀⠀⠀⠀⣐⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⣽⡯⡭⠄⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠⠄⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠂⠀⠀⠀⠀⠀⠀⠉⠈⠉⠀⠀⠀⠄⠀⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠀⠀⠀⠀⢰⣦⡄⠀⢰⡆⠀⠀⠀⠀⠀⠀⠀⠀⠙⠀⠀⠀⠁⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⡇⠀⠀⠐⠒⠂⠀⠀⠀⠀⠀⠀⠀⠴⠂⠀⠀⠀⢸⡏⠻⣧⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠺⢿⣿⣿⣿\n"
		 << "⣿⠿⠿⠋⠀⠀⢀⡴⠂⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⢸⡇⠀⠈⢷⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿\n"
		 << "⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣠⠄⠀⠀⠀⠀⠀⠀⠀⢠⠄⠀⠀⠀⠀⣹\n"
		 << "⣆⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠓⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠉⠉⠀⠀⠀⠀⠀⠈\n"
		 << "⣿⣿⣿⡆⢠⡤⠀⠆⡀⠀⣀⠓⠄⢴⡆⠀⠀⠀⠀⠀⠀⠀⢴⡀⠀⢦⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣾\n"
		 << "⣿⣿⣿⣿⣶⣤⣄⣠⣴⣶⣾⣿⣷⣦⣀⠀⠀⠀⢠⣤⣴⣦⣄⡁⠀⠀⠀⡶⠀⢰⣿⣶⣴⣿⣿⣿⣦⠈⠁⠀⢀⣠⡀⠀⢀⣄⣀⢀⣠⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⡄⠀⠈⢀⣴⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣼⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
		 << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠁⠀⠀⠙⠻⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
	file.close();
}


ShrubberyCreationForm::~ShrubberyCreationForm() 
{}
