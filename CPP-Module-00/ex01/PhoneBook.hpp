#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
	private:
		int		index;
		int		totalcontacts;
		Contact		contacts[8];
	public:
		PhoneBook();
		void		incrementIndex();
		int			getIndex();
		int			getTotalContacts();
		void		resetIndex();
		void		addContact(const Contact& c, int i);
		Contact&	getContact(int i);
};

#endif