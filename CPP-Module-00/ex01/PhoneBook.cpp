#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	PhoneBook::index = 0;
	PhoneBook::totalcontacts = 0;
}

void	PhoneBook::incrementIndex() {
	if (PhoneBook::totalcontacts < 8)
		totalcontacts++;
	PhoneBook::index++;
}

int		PhoneBook::getIndex() {
	return (PhoneBook::index);
}

void	PhoneBook::resetIndex() {
	PhoneBook::index = 0;
}

int		PhoneBook::getTotalContacts() {
	return (PhoneBook::totalcontacts);
}

void	PhoneBook::addContact(const Contact& c, int i) {
		PhoneBook::contacts[i] = c;
}

Contact& PhoneBook::getContact(int i) {
    return (PhoneBook::contacts[i]);
}
