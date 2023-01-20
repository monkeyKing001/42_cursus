#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "\033[0;91mForm Grade Too High\033[0;39m";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "\033[0;91mForm Grade Too Low\033[0;39m";
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return "\033[0;91mNot Signed Form\033[0;39m";
}

const char* AForm::UnauthorizedExecutorException::what(void) const throw()
{
	return "\033[0;91mUnautorized Executor\033[0;39m";
}

const char* AForm::FileOpenFailException::what(void) const throw()
{
	return "\033[0;91mFailed to open the file\033[0;39m";
}
const std::string&  AForm::getName(void) const
{
	return _name;
}

const int&  AForm::getSignGrade(void) const
{
	return _grade_sign;
}

const int&  AForm::getExecGrade(void) const
{
	return _grade_exec;
}

const bool& AForm::getSigned(void) const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw AForm::GradeTooHighException();
}

AForm& AForm::operator=(const AForm& f)
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

AForm::AForm(void) : _grade_sign(0), _grade_exec(0) {}

AForm::AForm(const AForm& f)
	: _name(f.getName()), _grade_sign(f.getSignGrade()),
	_grade_exec(f.getExecGrade()), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

AForm::AForm(const std::string& name, const int& sign_grade, const int& exec_grade)
	: _name(name), _grade_sign(sign_grade),
	_grade_exec(exec_grade), _signed(false)
{
	if (_grade_sign < GRADE_MAX || _grade_exec < GRADE_MAX)
		throw GradeTooHighException();
	if (_grade_sign > GRADE_MIN || _grade_exec > GRADE_MIN)
		throw GradeTooLowException();
}

AForm::~AForm(void) {}

std::ostream& operator<<(std::ostream& o, const AForm& f)
{
	o << YELLOW << "========================        AForm Info        ==========================\n";
	return o << "<" << f.getName() << ">, sign grade <"
		  << f.getSignGrade() << ">, exec grade <"
		  << f.getExecGrade() << ">, signed <"
		  << std::boolalpha << f.getSigned() << ">" << DEFAULT;
}

void AForm::executable(const Bureaucrat &b) const
{
	if (getSigned() == false)
		throw NotSignedException();
	if (this -> _grade_exec < b.getGrade())
		throw UnauthorizedExecutorException();
}
