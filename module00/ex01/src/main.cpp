#include "../includes/PhoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string command;

	while (31)
	{
		std::cout << "ADD, SEARCH or EXIT (case sensitive)" << std::endl;
		std::cin >> command;

		if (command == "ADD")
		{
			Contact newContact;
			system("clear");

			newContact.setContactInfo();
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH")
		{
			system("clear");
			std::cout << "SEARCH selected" << std::endl;
			phoneBook.displayContacts();
			phoneBook.displayIndexedContact();
		}
		else if (command == "EXIT") {
			system("clear");
			std::cout << "EXIT selected" << std::endl;
			std::cout << "Bye !" << std::endl;
			exit(0);
		}
		else {
			system("clear");
			std::cout << "Command not found" << std::endl;
		}
	}
}
