#include "Span.hpp"

int main( void )
{
	std::cout << YELLOW <<"=========== PDF TEST ==========\n" << DEFAULT;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

	try
	{
		std::cout << YELLOW << "\n---- TEST #1(span size over) -----\n" << DEFAULT;
		Span sp = Span( 5 );

		sp.addNumber( 6 );
		sp.addNumber( 3 );
		sp.addNumber( 9 );
		sp.addNumber( 17 );
		sp.addNumber( 11 );
		sp.addNumber( 100 );

		std::cout << "sp: " << sp << std::endl;

		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	}
	catch( std::exception& e)
	{
	std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << YELLOW << "\n---- TEST #1(copy, generate) -----\n" << DEFAULT;
		std::list<int>    l( 10000 );
		std::srand( time ( NULL ) );
		std::generate( l.begin(), l.end(), std::rand );

		Span span( l.size() );

		span.addNumber( l.begin(), l.end() );
		//std::cout << "span: " << span << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

	}
	catch ( std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

    return ( 0 );
}
