#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate( void )
{
    if ( std::rand() % 3 == 0 )
        return ( new A );
    else if ( std::rand() % 3 == 1 )
        return ( new B );
    else
        return ( new C );
}

//check with nullptr
void    identify( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << GREEN <<"pointer p is acutally A\n" << DEFAULT;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << GREEN <<"pointer p is acutally B\n" << DEFAULT;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << GREEN <<"pointer p is acutally C\n" << DEFAULT;
    else
        std::cout << RED <<"Unable to cast pointer p to any of pointer to A, B nor C\n" << DEFAULT;
}

//check with exception
void    identify( Base& p ) {
	try {
		A& a = dynamic_cast< A& >( p );
		std::cout << GREEN <<"reference p is acutally A\n" << DEFAULT;
		(void)a;
	} catch(const std::exception& e) 
	{
		std::cout << RED << "Cannot cast p to A. it thows " << e.what() << "\n" << DEFAULT;
	}
	try {
		B& b = dynamic_cast< B& >( p );
		std::cout << GREEN <<"reference p is acutally B\n" << DEFAULT;
		(void)b;
	} catch(const std::exception& e) 
	{
		std::cout << RED << "Cannot cast p to B. it thows " << e.what() << "\n" << DEFAULT;
	}
	try {
		C& c = dynamic_cast< C& >( p );
		std::cout << GREEN <<"reference p is acutally C\n" << DEFAULT;
		(void)c;
	} catch(const std::exception& e) 
	{
		std::cout << RED << "Cannot cast p to C. it thows " << e.what() << "\n" << DEFAULT;
	}
}
