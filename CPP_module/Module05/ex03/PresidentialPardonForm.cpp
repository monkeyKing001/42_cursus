#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(PARD_NAME, PARD_SIGN_GRADE, PARD_EXEC_GRADE)
{
	this -> _target = target;
}
PresidentialPardonForm::PresidentialPardonForm() : AForm(PARD_NAME, PARD_SIGN_GRADE, PARD_EXEC_GRADE)
{
	this -> _target = "None target";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : AForm(PARD_NAME, PARD_SIGN_GRADE, PARD_EXEC_GRADE)
{
	this -> _target = p.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& p)
{
	this -> _target = p.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return (this -> _target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	executable(executor);
	std::cout << GREEN << this -> getTarget() << " has been pardoned by Zaphod Beeblebrox." << DEFAULT <<"\n";
}

