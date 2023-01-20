#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(ROBO_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE)
{
	this -> _target = target;
}
RobotomyRequestForm::RobotomyRequestForm() : AForm(ROBO_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE)
{
	this -> _target = "None target";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : AForm(ROBO_NAME, ROBO_SIGN_GRADE, ROBO_EXEC_GRADE)
{
	this -> _target = r.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return (this -> _target);
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& obj)
{
	this -> _target = obj.getTarget();
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	executable(executor);
    int randomNumber = rand() % 100 + 1;
    srand(time(nullptr) * randomNumber); // seed the generator with the current time
	if (randomNumber % 2 == 0)
		std::cout << GREEN <<"and successfully Built the Robotomy " 
			<< this ->_target 
			<< DEFAULT
			<< "\n";
	else
		std::cout 
			<< RED 
			<< "but failed to build the Robotomy" 
			<< DEFAULT
			<< "\n";
	randomNumber = rand() % 100 + 1;
}
