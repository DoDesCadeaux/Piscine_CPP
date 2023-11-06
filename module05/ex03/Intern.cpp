#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other)
		*this = other;
	return *this;
}

Intern::~Intern() {}

AForm * Intern::makeForm(const std::string &formName, const std::string &formTarget) {

	FormCreator formsToExec[] = {
			&Intern::makePresidentialForm,
			&Intern::makeRobotomyForm,
			&Intern::makeShrubberyForm
	};

	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (unsigned i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			AForm *newForm = (this->*formsToExec[i])(formTarget);
			return newForm;
		}
	}

	throw AForm::NoExistingForm();
}

AForm *Intern::makePresidentialForm(const std::string &formTarget) {
	return new PresidentialPardonForm(formTarget);
}

AForm *Intern::makeShrubberyForm(const std::string &formTarget) {
	return new ShrubberyCreationForm(formTarget);
}

AForm *Intern::makeRobotomyForm(const std::string &formTarget) {
	return new RobotomyRequestForm(formTarget);
}