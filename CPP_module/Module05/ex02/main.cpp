#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
  Bureaucrat b1("1st class", 1);
  Bureaucrat b2("15'th class", 15);
  Bureaucrat b3("70'th class", 70);
  Bureaucrat b4("140'th class", 140);

  AForm*f1 = new PresidentialPardonForm("Shin Chang Won");
  AForm*f2 = new RobotomyRequestForm("I.robot");
  AForm*f3 = new ShrubberyCreationForm("Gaepodong");


  std::cout << "\n===============     Bureaucats list   =============" << "\n";
  std::cout << b1 << "\n"
    << b2 << "\n"
    << b3 << "\n"
    << b4 << "\n";


  std::cout << "\n===============     Form list   =============" << "\n";
  std::cout << *f1 << "\n"
    << *f2 << "\n"
    << *f3 << "\n";
  std::cout << "\n";


  std::cout << "\n===============     Sign Test   =============" << "\n";
  b2.signForm(*f1);
  b3.signForm(*f2);
  b4.signForm(*f3);
  std::cout << "\n";

  std::cout << "\n===============     Execution Test   =============" << "\n";
  b2.executeForm(*f1);
  b3.executeForm(*f2);
  b4.executeForm(*f3);
  std::cout << "\n";
  b1.executeForm(*f2);
  b1.executeForm(*f1);
  b1.executeForm(*f3);
  b1.executeForm(*f2);
  b1.executeForm(*f2);
  b1.executeForm(*f2);

  delete f3;
  delete f2;
  delete f1;
  return 0;

	return (0);
}
