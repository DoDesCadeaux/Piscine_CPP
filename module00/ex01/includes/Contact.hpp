#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <string>

class Contact {
private:
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	//Getters
	std::string	getFirstname() const;
	std::string getLastname() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarketSecret() const;

	//Setter
	void		setFirstName(std::string firstnameToSet);
	void		setLastName(std::string lastnameToSet);
	void		setNickname(std::string nicknameToSet);
	void		setPhoneNumber(std::string phoneNumberToSet);
	void		setDarkestSecret(std::string darkestSecretToSet);

	//Fill contact
	void		setContactInfo();

	Contact();
	~Contact();
};
#endif
