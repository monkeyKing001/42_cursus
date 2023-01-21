#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
		std::cout << "\n==================   Construction Test( Catch exception )   ===================\n";
			Bureaucrat test("under MIN", 200);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
		std::cout << "\n==================   Construction Test( Catch exception )   ===================\n";
			Bureaucrat test("over MAX", 0);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n==================   Construction Test( Working well )   ===================\n";
		
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		
		std::cout << "\n==================   Incre, Decre Test( Working well )   ===================\n";
//		 a.decrementGrade();
//
//		 b.incrementGrade();
//
//		std::cout << a << std::endl;
//		std::cout << b << std::endl;
//		std::cout << std::endl;

		a.incrementGrade();
		b.decrementGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << "\n==================   Incre, Decre Test( try catch )   ===================\n";
		try
		{
			b.incrementGrade();
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << '\n';
		}

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return (0);
}
