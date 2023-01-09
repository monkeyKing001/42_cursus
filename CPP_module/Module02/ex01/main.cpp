#include <iostream>
#include "Fixed.hpp"
int main(void)
{
	std::cout << "#########       a(42)       ###########" << "\n";
	Fixed a(42);
	std::cout << "overloaded << "<< a << "\n";
	std::cout << "getRawBits: " << a.getRawBits() << "\n";
	std::cout << "toFloat(): "<< a.toFloat() << "\n";
	std::cout << "toInt() : "<< a.toInt() << "\n";

	std::cout << "#########       b(42.0f)       ###########" << "\n";
	Fixed b(42.0f);
	std::cout << "overloaded << "<< b << "\n";
	std::cout << "getRawBits: " << b.getRawBits() << "\n";
	std::cout << "toFloat(): "<< b.toFloat() << "\n";
	std::cout << "toInt() : "<< b.toInt() << "\n";

	std::cout << "#########       c(42.42f)       ###########" << "\n";
	Fixed c(42.42f);
	std::cout << "overloaded << "<< c << "\n";
	std::cout << "getRawBits: " << c.getRawBits() << "\n";
	std::cout << "toFloat(): "<< c.toFloat() << "\n";
	std::cout << "toInt() : "<< c.toInt() << "\n";
	return (0);
}
