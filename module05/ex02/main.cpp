#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
	try {
		Bureaucrat personne("Personne", 150);
		Bureaucrat shrubberyCrat("ShrubberyCrat", 145);
		Bureaucrat robotomyCrat("RobotomyCrat", 72);
		Bureaucrat presidentialCrat("PresidentialCrat", 21);

		ShrubberyCreationForm	ShrubberyCreationForm("ShrubyForm");
		RobotomyRequestForm		RobotomyRequestForm("RoboForm");
		PresidentialPardonForm	PresidentialPardonForm("PresidentForm");

//		personne.signForm(ShrubberyCreationForm);
		shrubberyCrat.signForm(ShrubberyCreationForm);
		ShrubberyCreationForm.execute(robotomyCrat);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
