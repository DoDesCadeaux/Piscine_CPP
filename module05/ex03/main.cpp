#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
	try {
		Intern	dorian;
		AForm*	formulaire;

		formulaire = dorian.makeForm("presidential pardon", "Bender");


		Bureaucrat personne("Personne", 150);
		Bureaucrat shrubberyCrat("ShrubberyCrat", 145);
		Bureaucrat robotomyCrat("RobotomyCrat", 72);
		Bureaucrat presidentialCrat("PresidentialCrat", 21);

		ShrubberyCreationForm	sshrubberyCreationForm("ShrubyForm");
		RobotomyRequestForm		RobotomyRequestForm("RoboForm");
		PresidentialPardonForm	PresidentialPardonForm("PresidentForm");

//		personne.signForm(ShrubberyCreationForm);
		shrubberyCrat.signForm(sshrubberyCreationForm);
		sshrubberyCreationForm.execute(presidentialCrat);

		shrubberyCrat.signForm(*formulaire);
		formulaire->execute(presidentialCrat);

		delete formulaire;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::NoExistingForm &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
