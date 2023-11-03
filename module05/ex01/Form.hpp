#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExec;

public:
	Form(const std::string &_name, const unsigned int gradeToSign, const unsigned int gradeToExec);
	Form(const Form & other);
	Form & operator=(const Form & other);
	~Form();

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
	bool			getIsSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExec() const;

	void			beSigned(const Bureaucrat &signingBureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
