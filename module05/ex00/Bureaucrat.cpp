#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default crat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) :
_name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor " << this->_name << " called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high !";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low !";
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}
