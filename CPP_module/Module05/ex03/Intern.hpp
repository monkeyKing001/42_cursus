#ifndef INTERN_H
#define INTERN_H
#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#define FORM_TYPE 3

class Intern
{

	private:
		

	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern& operator = (const Intern& obj);
		~Intern(void);

		//make form
		AForm* makeForm(const std::string &name, const std::string &target);

		//throw exception
		class NoFormTypeException : public std::exception
		{
			public:
				const char* what() const throw(); 
		};
};

#endif /* INTERN_H */
