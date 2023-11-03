#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat james("James", 2);
		Bureaucrat lily("Lily", 1);
		Form form1("Form1", 1, 1);
		Form form2("Form2", 2, 1);

		std::cout << james << std::endl;
		std::cout << lily << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		james.signForm(form1);
		james.signForm(form2);
		lily.signForm(form1);
		lily.signForm(form2);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
