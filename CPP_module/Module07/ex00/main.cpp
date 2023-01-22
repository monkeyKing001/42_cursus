#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;

	std::cout << "\n====================     int type swap test      ======================\n";
	std::cout << "BEFORE SWAP : ";
    std::cout << "a = " << a << ", b = " << b << "\n";
    ::swap( a, b );
	std::cout << "AFTER SWAP : ";
    std::cout << "a = " << a << ", b = " << b << "\n";

    std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
    std::cout << "max( a, b ) = " << ::max( a, b ) << "\n";

    std::string c = "chaine1";
    std::string d = "chaine2";

	std::cout << "\n====================     string type swap test      ======================\n";
	std::cout << "BEFORE SWAP : ";
    std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "AFTER SWAP : ";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << "\n";

    std::cout << "min( c, d ) = " << ::min( c, d ) << "\n";
    std::cout << "max( c, d ) = " << ::max( c, d ) << "\n";

    return 0;
}
