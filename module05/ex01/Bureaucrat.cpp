#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name) {
	if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other._grade;

	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->_name << "'s destructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &formToSign) {
	try {
		formToSign.beSigned(*this);
		std::cout << this->_name << " signed " << formToSign.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << this->_name << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	return os;
}
