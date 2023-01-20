#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <random>
#include "AForm.hpp"
#define ROBO_SIGN_GRADE 72
#define ROBO_EXEC_GRADE 45
#define ROBO_NAME "RobotomyRequestForm"

class RobotomyRequestForm : public AForm
{

	private:
		std::string _target;
		RobotomyRequestForm(void);

	public:
		//constructor
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& obj);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);

		//execute
		void execute(const Bureaucrat &executor) const;

		//getter
		const std::string getTarget(void) const;
};

#endif /* ROBOTOMYREQUESTFORM_H */
