#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{

	//test1 Bureaucat can't sign because his grade is too low
	std::cout << "\n-----------------   good_bureaucrat, good_form_test    -------------------------" << std::endl;
	Bureaucrat bureaucrat1("good_bureaucrat", 1);
	Form form1("good_form_1", 2, 3);
	try {
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------   bad_bureaucrat, good_form_test    -------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat1("bad_bureaucrat", 0);
		Form form1("good_form_1", 2, 3);
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	//test2 Bureaucat can sign the form
	std::cout << "\n-----------------   good_bureaucrat, bad_form_test (over Grade MAX)    -------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat2("good_bureaucrat", 1);
		Form form2("bad_form_over_MAX", 0, 150);
		bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------   good_bureaucrat, bad_form_test (under Grade MIN)    -------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat2("good_bureaucrat", 1);
		Form form2("bad_form_under_MIN", 1, 151);
		bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------   good_bureaucrat, good_form_test, but cannot sign    -------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat2("good_bureaucrat", 5);
		Form form2("good_form_1", 2, 3);
		//signForm throw exception and catch statement within signFrom catches it.
		bureaucrat2.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	//test3 Form can't be create because grade is out of bounds
	std::cout << "\n-----------------   bad_bureaucrat, god_form_test OUT_OF_TRY_CATCH    -------------------------" << std::endl;
	Bureaucrat bureaucrat("out_or_try_catch", 151);
	try {
		Form form3("good_form", 1, 5);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n================   END OF TEST    ===============" << std::endl;

	return (0);
}
