#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char* Intern::NoFormTypeException::what(void) const throw()
{
	return ("\033[0;91mNo Matching Type\033[0;39m");
}

void Intern::paperWork(const std::string &name, const std::string &target)
{
	std::cout 
		<< GREEN
		<< "Intern creates <" 
		<< name
		<< " : " 
		<< target
		<< ">" 
		<< DEFAULT
		<< "\n";
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string types[FORM_TYPE] = { PARD_NAME, ROBO_NAME, SHRU_NAME };
	AForm *(Intern::*f[3])(const std::string) = 
	{ 
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyForm
	};
	try
	{
		for (int i = 0 ; i < FORM_TYPE ; ++i)
		{
			if (types[i] == name)
			{
				paperWork(name, target);
				AForm *form = (this ->* f[i])(target);
				return (form);
			}
		}
		throw NoFormTypeException();
	}
	catch (std::exception& e)
	{
		std::cout
			<< "Intern cannot create <" 
			<< name 
			<< "> : <" 
			<< target
			<< "> because " 
			<< e.what() 
			<< "\n";
		return NULL;
	}
}

Intern& Intern::operator = (const Intern& i)
{
	static_cast<void>(i);
	return *this;
}

AForm* Intern::createShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}


Intern::Intern(void) {}

Intern::Intern(const Intern& i) { static_cast<void>(i); }

Intern::~Intern(void) {}
