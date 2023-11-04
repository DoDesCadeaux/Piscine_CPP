#include "AForm.hpp"

AForm::AForm(const std::string &name, const unsigned int gradeToSign, const unsigned int gradeToExec)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	this->_isSigned = other._isSigned;
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

unsigned int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

unsigned int AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat &signingBureaucrat) {
	if (signingBureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::verifyExecution(const Bureaucrat &executor) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << form.getName() << " form signature is " << form.getIsSigned()
		<< ", grade needed to sign is " << form.getGradeToSign()
		<< " and grade needed to execute is " << form.getGradeToExec();

	return os;
}
