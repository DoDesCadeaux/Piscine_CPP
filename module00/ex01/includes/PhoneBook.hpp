#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
private:
	static const int	MAX_CONTACTS = 8;
	Contact				contacts[MAX_CONTACTS];
	int					currentSize;

	std::string			formatField(std::string stringToFormat) const;


public:

	PhoneBook();
	~PhoneBook();
	bool	isFull() const;
	void	addContact(const Contact &newContact);
	void	displayContacts() const;
	void	displayIndexedContact() const;
};

#endif