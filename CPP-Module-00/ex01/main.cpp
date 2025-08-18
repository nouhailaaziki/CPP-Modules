#include "PhoneBook.hpp"

std::string	formatField(const std::string& content)
{
	if (content.length() > 10)
		return (content.substr(0, 9) + ".");
	return (std::string(10 - content.length(), ' ') + content);
}

bool	checkValidity(const	std::string& content)
{
	size_t	counter;
	size_t	i;
	
	i = 0;
	counter = 0;
	if (content.empty())
		return (false);
	while (content[i])
	{
		if (!std::isprint(content[i]))
			return (false);
		i++;
	}
	i = 0;
	while (i < content.length())
	{
		if (isspace(content[i]))
			counter += 1;
		i++;
	}
	if (counter == content.length())
		return (false);
	return (true);
}

bool	checkCountryCode(const std::string& content, size_t& i, bool& hasPlus)
{
	size_t	countryDigits;

	countryDigits = 0;
	if (content[0] == '+')
	{
		hasPlus = true;
		i = 1;
		if (i >= content.length() || !isdigit(content[i]))
			return (false);
	}
	while (i < content.length() && isdigit(content[i]) && countryDigits < 3)
	{
		i++;
		countryDigits++;
	}
	if (countryDigits == 0)
		return (false);
	if (i < content.length() && content[i] == ' ')
	{
		i++;
		return (true);
	}
	return (!hasPlus);
}

bool	checkNationalNumber(const std::string& content, size_t& i, size_t& totalDigits)
{
	size_t	nationalDigits;

	nationalDigits = 0;
	while (i < content.length())
	{
		if (!isdigit(content[i]))
			return (false);
		i++;
		nationalDigits++;
	}
	totalDigits += nationalDigits;
	return (true);
}

bool validatePhoneNumber(const std::string& content)
{
	size_t	i;
	bool	hasPlus;
	size_t	totalDigits;

	i = 0;
	hasPlus = false;
	totalDigits = 0;
	if (!checkCountryCode(content, i, hasPlus))
		return (false);
	if (!checkNationalNumber(content, i, totalDigits))
		return (false);
	if (totalDigits < 4 || totalDigits > 15)
		return (false);
	return (true);
}

void getInput(std::string &field, const std::string &prompt,
				bool (*validator)(const std::string &))
{
	std::cout << prompt;
	std::getline(std::cin, field);
	if (std::cin.eof())
		exit(0);
	while (!validator(field))
	{
		std::cout << "Error: Invalid Input!" << std::endl;
		std::cout << prompt;
		std::getline(std::cin, field);
		if (std::cin.eof())
			exit(0);
	}
}

void	getPhoneNumber(std::string &pn)
{
	std::cout << "Enter phone number: ";
	std::getline(std::cin, pn);
	if (std::cin.eof())
		exit(0);
	while (!checkValidity(pn) || !validatePhoneNumber(pn))
	{
		std::cout << "The phone number must contain correct numbers!" << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, pn);
		if (std::cin.eof())
			exit(0);
	}
}

void	addContact(PhoneBook &phonebook)
{
	int		i;
	Contact	contact;

	i = phonebook.getIndex();
	if (i >= 8)
	{
		phonebook.resetIndex();
		i = phonebook.getIndex();
	}
	std::string fn, ln, nn, pn, ds;
	getInput(fn, "Enter first name: ", checkValidity);
	getInput(ln, "Enter last name: ", checkValidity);
	getInput(nn, "Enter nickname: ", checkValidity);
	getPhoneNumber(pn);
	getInput(ds, "Enter darkestSecret: ", checkValidity);
	contact.setContact(fn, ln, nn, pn, ds);
	phonebook.addContact(contact, i);
	phonebook.incrementIndex();
	std::cout << "Contact added successfully!" << std::endl;
}

void printContacts(PhoneBook &phonebook)
{
	int	i;
	
	i = 0;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < phonebook.getTotalContacts())
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|"
					<< formatField(phonebook.getContact(i).getFirstName()) << "|"
					<< formatField(phonebook.getContact(i).getLastName()) << "|"
					<< formatField(phonebook.getContact(i).getNickname()) << "|" << std::endl;
		i++;
	}
}

void showContactDetails(PhoneBook &phonebook, int idx)
{
	Contact &contact = phonebook.getContact(idx);
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void searchContact(PhoneBook &phonebook)
{
    std::string ix;

    if (phonebook.getTotalContacts() == 0)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }
    printContacts(phonebook);
    std::cout << "Enter index to view details: ";
    std::getline(std::cin, ix);
    if (std::cin.eof())
        exit(0);
    int idx = std::atoi(ix.c_str());
    if (idx > 0 && idx <= 8 && idx - 1 < phonebook.getTotalContacts())
        showContactDetails(phonebook, idx - 1);
    else
        std::cout << "Invalid index!" << std::endl;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(0);
		if (cmd == "ADD")
			addContact(phonebook);
		else if (cmd == "SEARCH")
			searchContact(phonebook);
		else if (cmd == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return (0);
		}
	}
}
