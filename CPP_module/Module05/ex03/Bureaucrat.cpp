#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>

void Bureaucrat::executeForm(const AForm &form) const
{
	AForm *f = const_cast<AForm *>(&form);
	try
	{
		f -> executable(*this);
		std::cout
			<< GREEN
			<< "Bureaucat <"
			<< this -> getName()
			<< "> executed "
			<< f -> getName()
			<< " "
			<< DEFAULT;
		f -> execute(*this);
	}
	catch (std::exception& e)
	{
		std::cout
			<< "<"
			<< this -> getName()
			<< ">"
			<< " cannot execute "
			<< f -> getName()
			<< " because "
			<< e.what()
			<< "\n";
	}
}

void Bureaucrat::signForm(const AForm& f) const {
  try {
    (*const_cast<AForm*>(&f)).beSigned(*this);
    std::cout 
		<< GREEN
		<< "<" 
		<< _name 
		<< "> signs <"
      	<< f.getName() 
		<< ">" 
		<< DEFAULT
		<< "\n";
  } catch (std::exception& e) {
    std::cerr << "<" << _name << "> cannot sign <"
      << f.getName() << "> because <" << e.what() << ">" << "\n";
  }
}
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
