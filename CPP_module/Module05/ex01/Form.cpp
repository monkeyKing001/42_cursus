#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form Grade Too High";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form Grade Too Low";
}

const std::string&  Form::getName(void) const
{
	return _name;
}

const int&  Form::getSignGrade(void) const
{
	return _grade_sign;
}

const int&  Form::getExecGrade(void) const
{
	return _grade_exec;
}

const bool& Form::getSigned(void) const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw Form::GradeTooHighException();
}

Form& Form::operator=(const Form& f)
{
	if (this != &f)
	{
		*(const_cast<std::string*>(&_name)) = f.getName();
		*(const_cast<int*>(&_grade_sign)) = f.getSignGrade();
		*(const_cast<int*>(&_grade_exec)) = f.getExecGrade();
		_signed = f.getSigned();
	}
	return *this;
}

Form::Form(void) : _grade_sign(0), _grade_exec(0) {}

Form::Form(const Form& f)
	: _name(f.getName()), _grade_sign(f.getSignGrade()),
	_grade_exec(f.getExecGrade()), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const std::string& name, const int& sign_grade, const int& exec_grade)
	: _name(name), _grade_sign(sign_grade),
	_grade_exec(exec_grade), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

Form::~Form(void) {}

std::ostream& operator<<(std::ostream& o, const Form& f) {
	o << "========================        Form Info        ==========================\n";
	return o << "<" << f.getName() << ">, sign grade <"
		  << f.getSignGrade() << ">, exec grade <"
		  << f.getExecGrade() << ">, signed <"
		  << std::boolalpha << f.getSigned() << ">";
}
