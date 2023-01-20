#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include <fstream>
#include <sstream>
#define SHRU_NAME "ShrubberyCreationForm"
#define SHRU_SIGN_GRADE 145
#define SHRU_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{

	private:
		std::string _target;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& obj);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);

		//execute
		void execute(const Bureaucrat &executor) const;

		//getter
		const std::string getTarget(void) const;

};

#endif /* SHRUBBERYCREATIONFORM_H */
