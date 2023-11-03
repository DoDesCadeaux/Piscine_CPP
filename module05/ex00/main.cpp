#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat test("Debile", 149);
		Bureaucrat test2("Golmon", 1);
		std::cout << test << std::endl;
		std::cout << test2 << std::endl;
		test.decrementGrade();
		test2.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	return 0;
}
