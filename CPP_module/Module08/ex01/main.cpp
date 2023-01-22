#include "Span.hpp"

int main( void )
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // try{
    //     std::cout << "\n---- TEST #1 -----" << std::endl;
    //     Span sp = Span( 5 );

    //     sp.addNumber( 6 );
    //     sp.addNumber( 3 );
    //     sp.addNumber( 9 );
    //     sp.addNumber( 17 );
    //     sp.addNumber( 11 );
    //     //sp.addNumber( 100 );
        
    //     std::cout << "sp: " << sp << std::endl;

    //     std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    //     std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    // }
    // catch( std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }
    // try {
    //     std::cout << "\n---- TEST #2 -----" << std::endl;
    //     std::list<int>    l( 10000 );
    //     std::srand( time ( NULL ) );
    //     std::generate( l.begin(), l.end(), std::rand );

    //     Span span( l.size() );

    //     span.addNumber( l.begin(), l.end() );
    //     //std::cout << "span: " << span << std::endl;
    //     std::cout << "Longest span: " << span.longestSpan() << std::endl;
    //     std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    // } catch ( std::exception& e ) {
    //     std::cout << e.what() << std::endl;
    // }

    return ( 0 );
}
