#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat(const std::string &name, unsigned int grade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat & operator=(const Bureaucrat &other);
	~Bureaucrat();

	class GradeTooHighException {
	public:
		const char *what() const throw() {
			return "Grade is too high!";
		}
	};

	class GradeTooLowException {
	public:
		const char *what() const throw() {
			return "Grade is too low!";
		}
	};

	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(AForm &formToSign);


};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bureaucrat);

#endif
