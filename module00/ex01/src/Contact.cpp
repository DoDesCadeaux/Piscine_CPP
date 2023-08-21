#include "../includes/PhoneBook.hpp"

Contact::Contact(void)  {return;}

Contact::~Contact(void) {return;}

std::string Contact::getFirstname() const {
	return this->_firstname;
}

std::string Contact::getLastname() const {
	return this->_lastname;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::getDarketSecret() const {
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string firstnameToSet) {
	if (this->_firstname.empty())
		this->_firstname = firstnameToSet;
	return;
}

void Contact::setLastName(std::string lastnameToSet) {
	if (this->_lastname.empty())
		this->_lastname = lastnameToSet;
	return;
}

void Contact::setNickname(std::string nicknameToSet) {
	if (this->_nickname.empty())
		this->_nickname = nicknameToSet;
	return;
}

void Contact::setPhoneNumber(std::string phoneNumberToSet) {
	if (this->_phoneNumber.empty())
		this->_phoneNumber = phoneNumberToSet;
	return;
}

void Contact::setDarkestSecret(std::string darkestSecretToSet) {
	if (this->_darkestSecret.empty())
		this->_darkestSecret = darkestSecretToSet;
	return;
}

void Contact::setContactInfo() {
	std::string field;

	std::cout << "Enter first name: ";
	std::cin >> field;
	this->setFirstName(field);

	std::cout << "Enter last name: ";
	std::cin >> field;
	this->setLastName(field);

	std::cout << "Enter nickname: ";
	std::cin >> field;
	this->setNickname(field);

	std::cout << "Enter phone number: ";
	std::cin >> field;
	this->setPhoneNumber(field);

	std::cout << "Enter darkest secret: ";
	std::cin >> field;
	this->setDarkestSecret(field);

	return;
}