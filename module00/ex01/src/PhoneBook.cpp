#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : currentSize(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::isFull() const {
	return this->currentSize == MAX_CONTACTS;
}

void PhoneBook::addContact(const Contact &newContact) {
	if (isFull()) {
		// Si le répertoire est plein, on décale tous les contacts d'une position vers le début.
		for (int i = 0; i < MAX_CONTACTS - 1; i++) {
			contacts[i] = contacts[i + 1];
		}
		// Le nouveau contact est ajouté à la dernière position.
		contacts[MAX_CONTACTS - 1] = newContact;
	} else {
		// Si le répertoire n'est pas plein, on ajoute simplement le contact à la fin.
		contacts[currentSize] = newContact;
		currentSize++;
	}
}

std::string PhoneBook::formatField(std::string stringToFormat) const {
	std::string	formatedString;

	if (stringToFormat.length() > 10)
	{
		formatedString = stringToFormat.substr(0, 9) + ".";
		return formatedString;
	}
	else
		return stringToFormat;
}

void PhoneBook::displayContacts() const {
	std::cout << "|" << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "firstname" << "|";
	std::cout << std::setw(10) << "lastname" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;

	for (int i = 0; i < currentSize; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getFirstname()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getLastname()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void PhoneBook::displayIndexedContact() const {
	int	index;

	std::cout << "Enter the contact index" << std::endl;
	std::cin >> index;
	system("clear");

	if (index < 0 || index >= currentSize)
	{
		std::cout << "Bad index" << std::endl;
		return;
	}

	const Contact &contact = contacts[index];

	std::cout << "Firstname : " << contact.getFirstname() << std::endl;
	std::cout << "Lastname : " << contact.getLastname() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone Number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << contact.getDarketSecret() << std::endl;
}
