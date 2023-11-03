#include "Form.hpp"

Form::Form(const std::string &name, const unsigned int gradeToSign, const unsigned int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	this->_isSigned = other._isSigned;
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << this->_name << "'s form destroyed" << std::endl;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

unsigned int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

unsigned int Form::getGradeToExec() const {
	return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat &signingBureaucrat) {
	if (signingBureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << form.getName() << " form signature is " << form.getIsSigned()
		<< ", grade needed to sign is " << form.getGradeToSign()
		<< " and grade needed to execute is " << form.getGradeToExec();

	return os;
}
