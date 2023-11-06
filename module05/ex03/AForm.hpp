#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExec;

public:
	AForm(const std::string &_name, const unsigned int gradeToSign, const unsigned int gradeToExec);
	AForm(const AForm & other);
	AForm & operator=(const AForm & other);
	virtual ~AForm();

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

	class NoExistingForm {
	public:
		const char *what() const throw() {
			return "Form doesn't exists";
		}
	};

	class FormNotSignedException {
	public:
		const char *what() const throw() {
			return "Form not signed!";
		}
	};

	std::string		getName() const;
	bool			getIsSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExec() const;

	void			beSigned(const Bureaucrat &signingBureaucrat);

	void			verifyExecution(const Bureaucrat &executor) const;

	//Fonction membre virtuelle pure. Donc la classe AForm est abstraite
	virtual void			execute(const Bureaucrat & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
