#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	private:
    	std::string firstName;
    	std::string lastName;
    	std::string nickname;
    	std::string phoneNumber;
    	std::string darkestSecret;
	public:
		Contact();
		void 		setContact(const std::string& firstName, const std::string& lastName,
                    	const std::string& nickname, const std::string& phoneNumber,
                    	const std::string& darkestSecret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

#endif