#include "Fixed.hpp"

Fixed::Fixed(void) 
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	setRawBits(fixed.getRawBits());
}
Fixed& Fixed::operator = (const Fixed& obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		setRawBits(obj.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this -> value);
}

void Fixed::setRawBits(int const value)
{
	this -> value = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
