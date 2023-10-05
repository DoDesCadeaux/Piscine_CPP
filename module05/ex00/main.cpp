#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat	ramy("Ramy", 149);

	try {
		std::cout << "Before decrementation : " << ramy.getGrade() << std::endl;
		ramy.decrementGrade();
		std::cout << "After decrementation : " << ramy.getGrade() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
		std::cout << "Verification after bad decrementation : " << ramy.getGrade() << std::endl;
	}
	return 0;
}
