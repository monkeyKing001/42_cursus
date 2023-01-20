#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char* Intern::NoFormTypeException::what(void) const throw()
{
	return ("\033[0;91mNo Matching Type\033[0;39m");
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string literals[FORM_TYPE] = { PARD_NAME, ROBO_NAME, SHRU_NAME };

	try
	{
		for (int i = 0 ; i < FORM_TYPE ; ++i)
		{
			if (literals[i] == name)
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
				switch (i)
				{
					case 0:
						return new PresidentialPardonForm(target);
						break;
					case 1:
						return new RobotomyRequestForm(target);
						break;
					case 2:
						return new ShrubberyCreationForm(target);
						break;
				}
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

Intern::Intern(void) {}

Intern::Intern(const Intern& i) { static_cast<void>(i); }

Intern::~Intern(void) {}
