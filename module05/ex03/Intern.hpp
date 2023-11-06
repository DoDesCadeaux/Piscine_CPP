#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);

	Intern & operator=(const Intern &other);

	~Intern();

	typedef	AForm *(Intern::*FormCreator)(const std::string &);

	AForm	*makeForm(const std::string &formName, const std::string &formTarget);

	AForm	*makePresidentialForm(const std::string &formTarget);
	AForm	*makeRobotomyForm(const std::string &formTarget);
	AForm	*makeShrubberyForm(const std::string &formTarget);

};

#endif
