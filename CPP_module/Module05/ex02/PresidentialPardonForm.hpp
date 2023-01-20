#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#define PARD_NAME "PresidentialPardonForm"
#define PARD_SIGN_GRADE 25
#define PARD_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{

	private:
		std::string _target;
		PresidentialPardonForm(void);

	public:
		//constructor
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator = (const PresidentialPardonForm& obj);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);

		//execute
		void execute(const Bureaucrat &executor) const;

		//getter
		const std::string getTarget(void) const;
};

#endif /* PRESIDENTIALPARDONFORM_H */
