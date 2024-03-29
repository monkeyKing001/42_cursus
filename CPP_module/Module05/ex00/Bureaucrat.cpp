#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat Grade has been over MAX range";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat Grade has been under MIN range";
}

const std::string& Bureaucrat::getName(void) const
{
	return (this -> _name);
}

const int& Bureaucrat::getGrade(void) const
{
	return (this -> _grade);
}

int& Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < GRADE_MAX)
		throw GradeTooHighException();
	return (--this -> _grade);
}

int& Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > GRADE_MIN)
		throw GradeTooLowException();
	return (++this -> _grade);
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& b)
{
	if (this != &b)
	{
		*(const_cast<std::string*>(&_name)) = b.getName();
	_grade = b.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b.getName()), _grade(b.getGrade())
{
	if (_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade)
{
	if (_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
	return (o << "<" << b.getName() << ">, bureaucrat grade <"
		<< b.getGrade() << ">");
}
