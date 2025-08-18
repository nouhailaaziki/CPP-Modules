#include "Contact.hpp"

Contact::Contact() {
	Contact::firstName = "";	
	Contact::lastName = "";	
	Contact::nickname = "";	
	Contact::phoneNumber = "";	
	Contact::darkestSecret = "";	
}

void	Contact::setContact(const std::string& firstName, const std::string& lastName,
            		const std::string& nickname, const std::string& phoneNumber,
            		const std::string& darkestSecret) {
		Contact::firstName = firstName;
		Contact::lastName = lastName;
		Contact::nickname = nickname;
		Contact::phoneNumber = phoneNumber;
		Contact::darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() {
	return (Contact::firstName);
}

std::string	Contact::getLastName() {
	return (Contact::lastName);
}

std::string	Contact::getNickname() {
	return (Contact::nickname);
}

std::string	Contact::getPhoneNumber() {
	return (Contact::phoneNumber);
}

std::string	Contact::getDarkestSecret() {
	return (Contact::darkestSecret);
}
