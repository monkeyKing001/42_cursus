#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
        Intern  someRandomIntern;
        AForm*   rrf;
        Bureaucrat p("World President", 1);
		Bureaucrat s("World Senator", 2);

		std::cout << "\n--------------- Form 1 ( Robotomy ) ---------------\n";
        rrf = someRandomIntern.makeForm(ROBO_NAME, "Atomboy");
		if (rrf)
		{
			s.signForm(*rrf);
			p.executeForm(*rrf);
			delete rrf;
		}
		std::cout << "\n--------------- Form 2 ( President ) ---------------\n";
		rrf = someRandomIntern.makeForm(PARD_NAME, "Prisoner");
		if (rrf)
		{
			s.signForm(*rrf);
			p.executeForm(*rrf);
			delete rrf;
		}
		std::cout << "\n--------------- Form 3 ( Shrubbery ) ---------------\n";
		rrf = someRandomIntern.makeForm(SHRU_NAME, "Gaepodong");
		if (rrf)
		{
			s.signForm(*rrf);
			p.executeForm(*rrf);
			delete rrf;
		}
		std::cout << "\n--------------- Form 4 ( No Name ) ---------------\n";
		rrf = someRandomIntern.makeForm("NO NAME", "GIVE ME 1 billon dollars Now");
		if (rrf)
		{
			s.signForm(*rrf);
			p.executeForm(*rrf);
			delete rrf;
		}
    }

	return (0);
}
